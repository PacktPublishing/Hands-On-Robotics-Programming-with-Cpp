#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetup();
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_on_clicked()
{
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
}

void MainWindow::on_off_clicked()
{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
}

void MainWindow::on_onoff_pressed()
{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
}

void MainWindow::on_onoff_released()
{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
}
