#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QLCDNumber>

class StopWatch : public QWidget
{
    Q_OBJECT
public:
    explicit StopWatch(QWidget *parent = nullptr, bool liveUpdate = false, QLCDNumber *LcdNumber = nullptr);

public slots:
    void updateAndDisplay();
    void onStart();
    void onStop();
    void onPause();

private:
    bool m_LiveUpdate;      // do we constatnly update the timer or just on events
    QTimer *m_Timer;
    QString m_TimeString;

    QTime m_StartTime;
    QTime m_PauseTime;
    QTime m_ContTime;

    QLCDNumber *m_LcdNumber;
};

#endif // STOPWATCH_H
