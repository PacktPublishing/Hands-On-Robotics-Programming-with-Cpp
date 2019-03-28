#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<wiringPi.h>
#define led1 0
#define led2 2

#include <QMainWindow>

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
    void on_on_clicked();

    void on_off_clicked();

    void on_onoff_pressed();

    void on_onoff_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
