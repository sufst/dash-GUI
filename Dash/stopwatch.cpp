#include "stopwatch.h"

StopWatch::StopWatch(QWidget *parent, bool liveUpdate, QLCDNumber *LcdNumber)
          : QWidget(parent), m_LiveUpdate(liveUpdate), m_LcdNumber(LcdNumber)
{
    m_Timer = new QTimer(this);

    if(m_LiveUpdate)
    {
        connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateAndDisplay()));
    }
}

void StopWatch::updateAndDisplay()
{
    QTime current = QTime::currentTime();
    int t = m_StartTime.msecsTo(current);
    QTime displayTime(0,0,0,0);
    displayTime = displayTime.addMSecs(t);
    m_TimeString = displayTime.toString("hh:mm:ss:zzz");
    m_LcdNumber->display(m_TimeString);
}

void StopWatch::onStart()
{
    if(m_LiveUpdate)
    {
        m_Timer->start(1);  // update the timer every 1ms
    }
    else
    {
        updateAndDisplay();
    }

    m_StartTime = QTime::currentTime();
}

void StopWatch::onStop()
{
    m_Timer->stop();
}

void StopWatch::onPause()
{

}
