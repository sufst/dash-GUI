#include "debugwindow.h"
#include "ui_debugwindow.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Debug Window"));

    /* connect signals from debug windows ui layer to the debug window slots , this
       means we can emmit them to the main window */
    connect(ui->rpmSlider, SIGNAL(sliderMoved(int)), this, SLOT(onSliderMoved(int)));
    connect(ui->radioButton, SIGNAL(pressed()), this, SLOT(onPageButtonPressed()));
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::onSliderMoved(int val)
{
    emit sliderMoved(val);
}

void DebugWindow::onPageButtonPressed()
{
    emit pageButtonPressed();
}
