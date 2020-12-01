/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
//#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *FileExit_MU;
    QAction *HelpReadme_MU;
    QAction *actionSelectFile;
    QAction *actionSaveFile;
    QAction *actionRun;
    QAction *actionLoad;
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *Run_PB;
    QPushButton *Exit_PB;
    QGroupBox *input_options;
    QRadioButton *SP_in_sec;
    QRadioButton *MINS_in_sec;
    QRadioButton *MAX_in_percent;
    QCheckBox *MAXS_file_input_mins;
    QRadioButton *SP_in_min;
    QRadioButton *MINS_in_min;
    QRadioButton *MAXS_in_min;
    QCheckBox *MAXS_file_input_secs;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *File_options;
    QCheckBox *append_to_file;
    QPushButton *SaveFile_PB;
    QLineEdit *SaveFile_LE;
    QLineEdit *SelectFile_LE;
    QPushButton *SelectFile_PB;
    QFrame *maxs_frame;
    QDoubleSpinBox *MaxS_Adjustment_DSB;
    QLabel *label_3;
    QFrame *frame;
    QComboBox *Sp_Sat_type_CMB;
    QLineEdit *Sp_Sat_Label_TB;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuZim;
    QMenu *menuHelp;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(699, 325);
        FileExit_MU = new QAction(MainWindow);
        FileExit_MU->setObjectName(QString::fromUtf8("FileExit_MU"));
        FileExit_MU->setCheckable(false);
        HelpReadme_MU = new QAction(MainWindow);
        HelpReadme_MU->setObjectName(QString::fromUtf8("HelpReadme_MU"));
        actionSelectFile = new QAction(MainWindow);
        actionSelectFile->setObjectName(QString::fromUtf8("actionSelectFile"));
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 0, 61, 16));
        QFont font;
        font.setPointSize(7);
        label->setFont(font);
        Run_PB = new QPushButton(centralWidget);
        Run_PB->setObjectName(QString::fromUtf8("Run_PB"));
        Run_PB->setGeometry(QRect(10, 270, 85, 27));
        Run_PB->setFont(font);
        Run_PB->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 255, 0);"));
        Exit_PB = new QPushButton(centralWidget);
        Exit_PB->setObjectName(QString::fromUtf8("Exit_PB"));
        Exit_PB->setGeometry(QRect(470, 270, 85, 27));
        Exit_PB->setFont(font);
        Exit_PB->setAutoFillBackground(false);
        Exit_PB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 4);\n"
""));
        input_options = new QGroupBox(centralWidget);
        input_options->setObjectName(QString::fromUtf8("input_options"));
        input_options->setGeometry(QRect(230, 20, 451, 111));
        input_options->setFont(font);
        SP_in_sec = new QRadioButton(input_options);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(SP_in_sec);
        SP_in_sec->setObjectName(QString::fromUtf8("SP_in_sec"));
        SP_in_sec->setGeometry(QRect(150, 20, 91, 17));
        SP_in_sec->setFont(font);
        MINS_in_sec = new QRadioButton(input_options);
        MINS_in_sec->setObjectName(QString::fromUtf8("MINS_in_sec"));
        MINS_in_sec->setGeometry(QRect(150, 50, 111, 17));
        MINS_in_sec->setFont(font);
        MAX_in_percent = new QRadioButton(input_options);
        buttonGroup_3 = new QButtonGroup(MainWindow);
        buttonGroup_3->setObjectName(QString::fromUtf8("buttonGroup_3"));
        buttonGroup_3->addButton(MAX_in_percent);
        MAX_in_percent->setObjectName(QString::fromUtf8("MAX_in_percent"));
        MAX_in_percent->setGeometry(QRect(130, 80, 111, 17));
        MAX_in_percent->setFont(font);
        MAXS_file_input_mins = new QCheckBox(input_options);
        buttonGroup_3->addButton(MAXS_file_input_mins);
        MAXS_file_input_mins->setObjectName(QString::fromUtf8("MAXS_file_input_mins"));
        MAXS_file_input_mins->setGeometry(QRect(210, 80, 111, 17));
        MAXS_file_input_mins->setFont(font);
        SP_in_min = new QRadioButton(input_options);
        buttonGroup_2->addButton(SP_in_min);
        SP_in_min->setObjectName(QString::fromUtf8("SP_in_min"));
        SP_in_min->setGeometry(QRect(50, 20, 82, 17));
        SP_in_min->setFont(font);
        SP_in_min->setChecked(true);
        MINS_in_min = new QRadioButton(input_options);
        MINS_in_min->setObjectName(QString::fromUtf8("MINS_in_min"));
        MINS_in_min->setGeometry(QRect(50, 50, 101, 17));
        MINS_in_min->setFont(font);
        MINS_in_min->setChecked(false);
        MAXS_in_min = new QRadioButton(input_options);
        buttonGroup_3->addButton(MAXS_in_min);
        MAXS_in_min->setObjectName(QString::fromUtf8("MAXS_in_min"));
        MAXS_in_min->setGeometry(QRect(50, 80, 101, 17));
        MAXS_in_min->setFont(font);
        MAXS_in_min->setChecked(true);
        MAXS_file_input_secs = new QCheckBox(input_options);
        buttonGroup_3->addButton(MAXS_file_input_secs);
        MAXS_file_input_secs->setObjectName(QString::fromUtf8("MAXS_file_input_secs"));
        MAXS_file_input_secs->setGeometry(QRect(330, 80, 111, 17));
        MAXS_file_input_secs->setFont(font);
        label_4 = new QLabel(input_options);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 0, 71, 21));
        label_4->setFont(font);
        label_5 = new QLabel(input_options);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 21, 20));
        label_5->setFont(font);
        label_6 = new QLabel(input_options);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 50, 31, 20));
        label_6->setFont(font);
        label_7 = new QLabel(input_options);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 61, 20));
        label_7->setFont(font);
        File_options = new QGroupBox(centralWidget);
        File_options->setObjectName(QString::fromUtf8("File_options"));
        File_options->setGeometry(QRect(10, 140, 471, 121));
        File_options->setFont(font);
        append_to_file = new QCheckBox(File_options);
        append_to_file->setObjectName(QString::fromUtf8("append_to_file"));
        append_to_file->setGeometry(QRect(10, 90, 141, 17));
        append_to_file->setFont(font);
        append_to_file->setChecked(true);
        SaveFile_PB = new QPushButton(File_options);
        SaveFile_PB->setObjectName(QString::fromUtf8("SaveFile_PB"));
        SaveFile_PB->setGeometry(QRect(360, 60, 85, 21));
        SaveFile_PB->setFont(font);
        SaveFile_LE = new QLineEdit(File_options);
        SaveFile_LE->setObjectName(QString::fromUtf8("SaveFile_LE"));
        SaveFile_LE->setGeometry(QRect(10, 60, 351, 21));
        SaveFile_LE->setFont(font);
        SaveFile_LE->setAutoFillBackground(true);
        SelectFile_LE = new QLineEdit(File_options);
        SelectFile_LE->setObjectName(QString::fromUtf8("SelectFile_LE"));
        SelectFile_LE->setGeometry(QRect(10, 30, 351, 21));
        SelectFile_LE->setFont(font);
        SelectFile_LE->setAutoFillBackground(true);
        SelectFile_PB = new QPushButton(File_options);
        SelectFile_PB->setObjectName(QString::fromUtf8("SelectFile_PB"));
        SelectFile_PB->setGeometry(QRect(360, 30, 85, 21));
        SelectFile_PB->setFont(font);
        maxs_frame = new QFrame(centralWidget);
        maxs_frame->setObjectName(QString::fromUtf8("maxs_frame"));
        maxs_frame->setGeometry(QRect(30, 90, 201, 41));
        maxs_frame->setFont(font);
        maxs_frame->setFrameShape(QFrame::StyledPanel);
        maxs_frame->setFrameShadow(QFrame::Raised);
        MaxS_Adjustment_DSB = new QDoubleSpinBox(maxs_frame);
        MaxS_Adjustment_DSB->setObjectName(QString::fromUtf8("MaxS_Adjustment_DSB"));
        MaxS_Adjustment_DSB->setGeometry(QRect(130, 10, 62, 22));
        MaxS_Adjustment_DSB->setFont(font);
        label_3 = new QLabel(maxs_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 131, 21));
        label_3->setFont(font);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 40, 201, 51));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Sp_Sat_type_CMB = new QComboBox(frame);
        Sp_Sat_type_CMB->addItem(QString());
        Sp_Sat_type_CMB->addItem(QString());
        Sp_Sat_type_CMB->addItem(QString());
        Sp_Sat_type_CMB->addItem(QString());
        Sp_Sat_type_CMB->setObjectName(QString::fromUtf8("Sp_Sat_type_CMB"));
        Sp_Sat_type_CMB->setGeometry(QRect(0, 0, 151, 21));
        Sp_Sat_type_CMB->setFont(font);
        Sp_Sat_Label_TB = new QLineEdit(frame);
        Sp_Sat_Label_TB->setObjectName(QString::fromUtf8("Sp_Sat_Label_TB"));
        Sp_Sat_Label_TB->setGeometry(QRect(110, 20, 41, 21));
        Sp_Sat_Label_TB->setFont(font);
        Sp_Sat_Label_TB->setAutoFillBackground(true);
        Sp_Sat_Label_TB->setMaxLength(4);
        Sp_Sat_Label_TB->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 101, 21));
        label_2->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        File_options->raise();
        input_options->raise();
        label->raise();
        Run_PB->raise();
        Exit_PB->raise();
        maxs_frame->raise();
        frame->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 699, 24));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        menuZim = new QMenu(menuBar);
        menuZim->setObjectName(QString::fromUtf8("menuZim"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuZim->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuZim->addAction(FileExit_MU);
        menuZim->addAction(actionSelectFile);
        menuZim->addAction(actionSaveFile);
        menuZim->addAction(actionLoad);
        menuHelp->addAction(HelpReadme_MU);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        FileExit_MU->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        HelpReadme_MU->setText(QApplication::translate("MainWindow", "Readme", nullptr));
        actionSelectFile->setText(QApplication::translate("MainWindow", "SelectFile", nullptr));
        actionSaveFile->setText(QApplication::translate("MainWindow", "SaveFile", nullptr));
        actionRun->setText(QApplication::translate("MainWindow", "Run", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        label->setText(QApplication::translate("MainWindow", "SP Satisf ", nullptr));
        Run_PB->setText(QApplication::translate("MainWindow", "Run", nullptr));
        Exit_PB->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        input_options->setTitle(QString());
        SP_in_sec->setText(QApplication::translate("MainWindow", "in seconds", nullptr));
        MINS_in_sec->setText(QApplication::translate("MainWindow", "in seconds", nullptr));
        MAX_in_percent->setText(QApplication::translate("MainWindow", " Percent", nullptr));
        MAXS_file_input_mins->setText(QApplication::translate("MainWindow", "From file Mins", nullptr));
        SP_in_min->setText(QApplication::translate("MainWindow", "in minutes", nullptr));
        MINS_in_min->setText(QApplication::translate("MainWindow", "in minutes", nullptr));
        MAXS_in_min->setText(QApplication::translate("MainWindow", " Minutes", nullptr));
        MAXS_file_input_secs->setText(QApplication::translate("MainWindow", "From file Secs", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Input options", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "SP", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "MINS", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "MAXS", nullptr));
        File_options->setTitle(QString());
        append_to_file->setText(QApplication::translate("MainWindow", "Append to file", nullptr));
        SaveFile_PB->setText(QApplication::translate("MainWindow", "Save File", nullptr));
        SelectFile_PB->setText(QApplication::translate("MainWindow", "Select File", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "MAXS adjustment :", nullptr));
        Sp_Sat_type_CMB->setItemText(0, QApplication::translate("MainWindow", "By time type 1", nullptr));
        Sp_Sat_type_CMB->setItemText(1, QApplication::translate("MainWindow", "By count type 1", nullptr));
        Sp_Sat_type_CMB->setItemText(2, QApplication::translate("MainWindow", "By time type 2", nullptr));
        Sp_Sat_type_CMB->setItemText(3, QApplication::translate("MainWindow", "By count type 2", nullptr));

        Sp_Sat_Label_TB->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Set label (AAAA) :", nullptr));
        menuZim->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
