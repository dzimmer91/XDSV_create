#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file_parse.h"
#include <QtGui>
#include <QApplication>
#include <QFileDialog>
#include<fstream>
#include<iostream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
{

    setupUi(this);
    connect( SelectFile_PB, SIGNAL( clicked() ), this, SLOT( getPath() ) );

    connect( FileExit_MU, SIGNAL( triggered() ), this, SLOT( Exit_CB() ) );
    connect( HelpReadme_MU, SIGNAL( triggered() ), this, SLOT( Help_CB() ) );
    connect( SaveFile_PB, SIGNAL( clicked() ), this, SLOT( savePath() ) );
    connect( actionSaveFile, SIGNAL( triggered() ), this, SLOT( savePath() ) );
    connect( actionSelectFile, SIGNAL( triggered() ), this, SLOT( getPath() ) );
    connect( actionLoad, SIGNAL( triggered() ), this, SLOT( LoadWindow() ) );
}
void MainWindow::Help_CB()
{

    QMessageBox msgBox;
    msgBox.setText("TODO\n");
    msgBox.exec();

}
void MainWindow::SetWidget(QWidget *Parent)
{
  MyWidget = Parent;
}
void MainWindow::LoadWindow()
{
  MyWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Exit_CB()
{
    exit(1);
}
void MainWindow::on_Exit_PB_clicked()
{
    exit(1);
}

void MainWindow::on_Run_PB_clicked()
{


   std::string Instr = SelectFile_LE->text().toStdString();
   char *InFileName = (char*) Instr.c_str();

   std::string Outstr = SaveFile_LE->text().toStdString();
   const char *OutFileName = Outstr.c_str();

   bool sp_in_mins = false;
   bool mins_in_mins = false;
   bool maxs_in_mins = false;
   bool maxs_from_file = false;
   sp_in_mins = SP_in_min->isChecked();

   mins_in_mins = MINS_in_min->isChecked();
   maxs_in_mins = MAXS_in_min->isChecked();

   maxs_from_file = (MAXS_file_input_mins->isChecked() || MAXS_file_input_secs->isChecked());


   std::string sp_sat_label = Sp_Sat_Label_TB->text().toStdString();

  // std::string maxs_adjustment = MaxS_adjustment_TB->text().toStdString();
   double maxs_adjustment = MaxS_Adjustment_DSB->text().toDouble();
   int type_idx = Sp_Sat_type_CMB->currentIndex();
   int type;

   if(type_idx == 0 || type_idx == 1)
   {
       type = 1;
   }else
   {
       type = 2;
   }
   FILE* output_FP;

   if(append_to_file->isChecked())
   {
       output_FP = fopen(OutFileName,"a");
   }else
   {
       output_FP = fopen(OutFileName,"w");
   }

   if(output_FP == NULL)
   {
       std::cout << "Error";
       return;
   }

   //write header for XDSV file//
   fprintf(output_FP," XDSP%2.2dST  %4.4s\n", type, sp_sat_label.c_str());
   fprintf(output_FP," XDSP%2.2dDA  %4.4s%6d%10d\n", type, sp_sat_label.c_str(),0,0);




    bool debug = false;

    input_file_parser = new Parser(InFileName);
    input_file_parser->setDel(',');


    int sp_num=1;
    int numlines = input_file_parser->getnumlines();
    int numperline = input_file_parser->getnumdelcount();
    ++numperline;
    input_file_parser->setVarsPerLine(&numperline);

    if(maxs_from_file && numperline != 3)
    {
        QMessageBox msgBox;
        msgBox.setText("Error File doesn't contain the correct format\nFORMAT below:\n SP_time,MINS,MAXS\n");
        msgBox.exec();
#ifdef _WIN32
        WaitMessage();
#endif
#ifdef __unix__
//#include<unistd.h>
      //  sleep(10);
#endif


        delete input_file_parser;
        return;
    }

    if(debug)std::cout << "num of lines =" << numlines << "\n";
    if(debug)std::cout << "num of del per line =" << numperline << "\n";

    output_data = new XDSV[numlines];

    char **data;
    //data = new char **[numlines];

    //Type 1 by time
    if(type_idx == 0)
    {
    for(int k=0;k<numlines; k++)
    {
      data = input_file_parser->getline();

      if(data == NULL)
      {
        if(debug) std::cout << "data[k]=NULL at=" << k << "\n";
        break;

      }



        if(k != 0 && type == 1)
        {
          output_data[k-1].sp = sp_num++;
          if(mins_in_mins)
          {
              output_data[k-1].mins = atof(data[1]);
          }
          else
          {
              output_data[k-1].mins = (atof(data[1]) / 60) ;
          }

          if(maxs_from_file)
          {
             if(MAXS_file_input_mins->isChecked() )
             {
                output_data[k-1].maxs =atof(data[2]);
             }else
             {
                output_data[k-1].maxs = (atof(data[2]) / 60);
             }

          }else
          {
            if(maxs_in_mins)
            {
                output_data[k-1].maxs = output_data[k-1].mins + maxs_adjustment;
            }
            else
            {
                  output_data[k-1].maxs = output_data[k-1].mins + (output_data[k-1].mins * (maxs_adjustment/100) );
            }
          }

          if(sp_in_mins)
          {
              output_data[k-1].sp_minutes = atof(data[0]);
              output_data[k-1].sp_seconds = output_data[k-1].sp_minutes * 60;
          }
          else
          {
              output_data[k-1].sp_seconds = atof(data[0]);
              output_data[k-1].sp_minutes = output_data[k-1].sp_seconds / 60;

          }
      }

        for(int i=0;i<numperline;i++)
      {

        if(debug) std::cout << i << "->" << data[i] << "    ";
        delete [] data[i];
      }
        delete[] data;

        if(debug) std::cout << "\n";
    }

    for(int k=0;k<numlines-1; k++)
    {
        int seconds = ((int)(output_data[k].sp_seconds  ) %  60);
        int minutes = ((int)(output_data[k].sp_seconds ) % 3600) / 60;
        int hours = ((int)(output_data[k].sp_seconds ) % 86400) / 3600;
        int days = ((int)(output_data[k].sp_seconds )) / 86400;

        output_data[k].SP_seconds = seconds;
        output_data[k].SP_minutes = minutes;
        output_data[k].SP_hours = hours;
        output_data[k].SP_days = days;

        seconds = ((int)(output_data[k].mins * 60  ) %  60);
        minutes = ((int)(output_data[k].mins * 60 ) % 3600) / 60;
        hours = ((int)(output_data[k].mins * 60 ) % 86400) / 3600;
        days = ((int)(output_data[k].mins * 60)) / 86400;

        output_data[k].MINS_seconds = seconds;
        output_data[k].MINS_minutes = minutes;
        output_data[k].MINS_hours = hours;
        output_data[k].MINS_days = days;

        seconds = ((int)(output_data[k].maxs * 60 ) %  60);
        minutes = ((int)(output_data[k].maxs * 60 ) % 3600) / 60;
        hours = ((int)(output_data[k].maxs * 60 ) % 86400) / 3600;
        days = ((int)(output_data[k].maxs * 60 )) / 86400;

        output_data[k].MAXS_seconds = seconds;
        output_data[k].MAXS_minutes = minutes;
        output_data[k].MAXS_hours = hours;
        output_data[k].MAXS_days = days;
    }

    for(int k=0;k<numlines-1; k++)
    {
        fprintf(output_FP," XDSP%2.2dDA  %4.4s%6d          %4d%2.2d%2.2d%2.2d",
                type, sp_sat_label.c_str(),output_data[k].sp, output_data[k].SP_days,
                output_data[k].SP_hours,  output_data[k].SP_minutes,  output_data[k].SP_seconds);

        fprintf(output_FP,"%4d%2.2d%2.2d%2.2d", output_data[k].MINS_days,
                output_data[k].MINS_hours,  output_data[k].MINS_minutes,  output_data[k].MINS_seconds);
        fprintf(output_FP,"%4d%2.2d%2.2d%2.2d\n", output_data[k].MAXS_days,
                output_data[k].MAXS_hours,  output_data[k].MAXS_minutes,  output_data[k].MAXS_seconds);
    }
}

    //type 1 by count
    else if(type_idx == 1)
    {
        for(int k=0;k<numlines; k++)
        {
            data = input_file_parser->getline();

            if(data == NULL)
            {
                if(debug) std::cout << "data[k]=NULL at=" << k << "\n";
                break;
            }
            if(k != 0 && type == 1)
            {
                output_data[k-1].sp = sp_num++;
                output_data[k-1].maxs =atof(data[1]);
            }
            if(sp_in_mins)
            {
              output_data[k-1].sp_minutes = atof(data[0]);
              output_data[k-1].sp_seconds = output_data[k-1].sp_minutes * 60;
            }
            else
            {
              output_data[k-1].sp_seconds = atof(data[0]);
              output_data[k-1].sp_minutes = output_data[k-1].sp_seconds / 60;

            }
       }

       for(int i=0;i<numperline;i++)
       {

            if(debug) std::cout << i << "->" << data[i] << "    ";
            delete [] data[i];
       }
       delete[] data;

       if(debug) std::cout << "\n";

       for(int k=0;k<numlines-1; k++)
    {
        int seconds = ((int)(output_data[k].sp_seconds  ) %  60);
        int minutes = ((int)(output_data[k].sp_seconds ) % 3600) / 60;
        int hours = ((int)(output_data[k].sp_seconds ) % 86400) / 3600;
        int days = ((int)(output_data[k].sp_seconds )) / 86400;

        output_data[k].SP_seconds = seconds;
        output_data[k].SP_minutes = minutes;
        output_data[k].SP_hours = hours;
        output_data[k].SP_days = days;
    }

       for(int k=0;k<numlines-1; k++)
    {
        fprintf(output_FP," XDSP%2.2dDA  %4.4s%6d          %4d%2.2d%2.2d%2.2d",
                type, sp_sat_label.c_str(),output_data[k].sp, output_data[k].SP_days,
                output_data[k].SP_hours,  output_data[k].SP_minutes,  output_data[k].SP_seconds);

        fprintf(output_FP,"          ");
        fprintf(output_FP,"%10d\n", (int)output_data[k].maxs);
    }


    }

    fprintf(output_FP," XDSP%2.2dEN  %4.4s\n", type, sp_sat_label.c_str());


    fclose(output_FP);

    delete output_data;
    delete input_file_parser;

    QMessageBox completeMsgBox;
    completeMsgBox.setText("Done converting file to XDSV\n");
    completeMsgBox.exec();

}



void MainWindow::getPath()
{
    QString path;
    path = QFileDialog::getOpenFileName(this, "Choose a file to open", NULL, NULL);
    SelectFile_LE->setText(path);
}

void MainWindow::savePath()
{
    QString path;
    path = QFileDialog::getSaveFileName(this, "Choose a file to save", NULL, NULL);
    SaveFile_LE->setText(path);
}

void MainWindow::on_Sp_Sat_type_CMB_currentIndexChanged(int index)
{

    if(index == 0)
    {
        input_options->show();
        maxs_frame->show();
    }else if(index == 1)
    {
        input_options->hide();
        maxs_frame->hide();
    }
        //input_options
}
