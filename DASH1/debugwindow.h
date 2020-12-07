#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QWidget>

namespace Ui {
class debugWindow;
}

class debugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit debugWindow(QWidget *parent = nullptr);
    ~debugWindow();

signals:
    void sliderMoved(int val);

private slots:
    void onSliderMoved(int val);
private:
    Ui::debugWindow *ui;
};

#endif // DEBUGWINDOW_H
