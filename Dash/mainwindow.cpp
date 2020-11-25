#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("SUFST - Dash"));
    //ui->centralwidget->setStyleSheet("background: black");      // forces black background, doing this from ui file made designing GUI harder...

    debugWindow = new DebugWindow;                              // create a debug window (main window stores a pointer to this object)
    debugWindow->show();                                        // show the debug window

    /* connect signals from debug window to change what the main window shows */
    connect(debugWindow, SIGNAL(sliderMoved(int)), this, SLOT(handleSlider(int)));
    connect(debugWindow, SIGNAL(pageButtonPressed()), this, SLOT(handlePages()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete debugWindow;
}

void MainWindow::handleSlider(int val)
{
    /* setup the three gradients for the rpm bar */
    const QString value1 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #00FF00,stop: 0.4999 #76F150,stop: 0.5 #98F150,stop: 1 #AEF150 );}";
    const QString value2 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #00FF00,stop: 0.4999 #76F150,stop: 0.5 #98F150,stop: 1 #F1AE50 );}";
    const QString value3 = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #00FF00,stop: 0.4999 #76F150,stop: 0.5 #98F150,stop: 1 #FF0000 );}";


    ui->progressBar->setValue(val);


    /* set the bars gradients based on the value */
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

    /*
       change the text labels based on the value of the slider as well - need to know how
       we will get info from DAQ code to display actual values (seperate slots/signals for
       all?
    */
    ui->gearLabel->setText(QString::number((val*8)/100));
    ui->speedLabel->setText(QStringLiteral("Speed: %1 km/h").arg(val*1.2f));
    ui->rpmLabel->setText(QStringLiteral("RPM: %1").arg(val*220));
    ui->engTempLabel->setText(QStringLiteral("Eng. Temp: %1 C").arg(val));
    ui->lastLabel->setText(QStringLiteral("Last: 1:23.456"));
    ui->oilTempLabel->setText(QStringLiteral("Oil Temp: %1 C").arg((int)(val*0.8)));
    ui->watTempLabel->setText(QStringLiteral("Water Temp: %1 C").arg((int)(val*1.1)));
}

void MainWindow::handlePages()      // this slot is run every time the pages button is pressed on the debug window
{
    static bool toggle = false;

    toggle = !toggle;               // toggle & set the index to change between pages
    ui->stackedWidget->setCurrentIndex(toggle);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    debugWindow->close();           // if the main window is closed, also close the debug window
}
