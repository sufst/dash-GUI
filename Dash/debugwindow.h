#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QWidget>

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = nullptr);
    ~DebugWindow();

signals:
    void sliderMoved(int val);
    void pageButtonPressed();

private slots:
    void onSliderMoved(int val);
    void onPageButtonPressed();

private:
    Ui::DebugWindow *ui;
};

#endif // DEBUGWINDOW_H
