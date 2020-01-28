#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#define WINDOWS

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "file_parse.h"
namespace Ui {
class MainWindow;
}

struct XDSV
{
    int sp;
    double sp_minutes,
           sp_seconds;
    int SP_days,
        SP_hours,
        SP_minutes,
        SP_seconds;
    int MINS_days,
        MINS_hours,
        MINS_minutes,
        MINS_seconds;
    int MAXS_days,
        MAXS_hours,
        MAXS_minutes,
        MAXS_seconds;
    double mins;
    double maxs;
};

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void SetWidget(QWidget *);
    ~MainWindow();

private slots:
    void on_Exit_PB_clicked();
    void Exit_CB();
    void Help_CB();
    void on_Run_PB_clicked();
    void getPath();
    void savePath();
    void LoadWindow();

    void on_Sp_Sat_type_CMB_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QWidget *MyWidget;

    XDSV *output_data;
    Parser *input_file_parser;
};


struct MisData
{
    char *MisName;
    char * SA;
    char * ECC;
    char * INC;
    char * RA;
    char * AOP;
    char * MA;
    char *EPDate;
    char *EPTime;
    char *EPSec;
    char *Duration;
    char *STDate;
    char *STTime;
    char *STSec;
    MisData *Node;
};
#endif // MAINWINDOW_H
