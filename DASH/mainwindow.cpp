#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
    this->setWindowTitle("Dash Screen 1");
    ui->label_7->setStyleSheet("color: green;"
                             "background-color: lightblue;" "border: lightblue;");
    ui->Speed->setStyleSheet("color: white;");
    ui->Rpm->setStyleSheet("color: white;");
    ui->Eng_temp->setStyleSheet("color: white;");
    ui->Water_temp->setStyleSheet("color: white;""background-color: red;");
    ui->Oil_temp->setStyleSheet("color:white;");
    ui->gear_num->setStyleSheet("color:white;");
    ui->last->setStyleSheet("color:purple;");
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(handleSlider(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleSlider(int val){
    ui->progressBar->setValue(val);
    const QString value1 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #00FF00,stop: 0.4999 #76F150,stop: 0.5 #98F150,stop: 1 #AEF150 );}";
    const QString value2 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #00FF00,stop: 0.4999 #76F150,stop: 0.5 #98F150,stop: 1 #F1AE50 );}";
    const QString value3 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #00FF00,stop: 0.4999 #76F150,stop: 0.5 #98F150,stop: 1 #FF0000 );}";


       if(ui->progressBar->value()<50)
       {
           ui->progressBar->setStyleSheet(value1);
       }
       if(ui->progressBar->value()>50 && ui->progressBar->value()<80)
       {
           ui->progressBar->setStyleSheet(value2);
       }
       if(ui->progressBar->value()>=80)
       {
           ui->progressBar->setStyleSheet(value3);
       }

}
