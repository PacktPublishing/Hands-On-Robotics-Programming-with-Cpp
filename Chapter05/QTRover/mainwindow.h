#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <wiringPi.h>
#include <QMainWindow>

#define leftmotor1 0
#define leftmotor2 2
#define rightmotor1 3
#define rightmotor2 4
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_forward_clicked();

    void on_backward_clicked();

    void on_stop_clicked();

    void on_left_pressed();

    void on_left_released();

    void on_right_pressed();

    void on_right_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
