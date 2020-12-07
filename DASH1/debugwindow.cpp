#include "debugwindow.h"
#include "ui_debugwindow.h"

debugWindow::debugWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::debugWindow)
{
    ui->setupUi(this);
    this ->setWindowTitle("Debug Window");
    this->setStyleSheet("background-color: black;");
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(onSliderMoved(int)));
}

debugWindow::~debugWindow()
{
    delete ui;
}
void debugWindow::onSliderMoved(int val)
{
    emit sliderMoved(val);
}
