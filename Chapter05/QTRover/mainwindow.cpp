#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetup();
    pinMode(leftmotor1, OUTPUT);
    pinMode(leftmotor2, OUTPUT);
    pinMode(rightmotor1,OUTPUT);
    pinMode(rightmotor2,OUTPUT);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_forward_clicked()
{
digitalWrite(leftmotor1,HIGH);
digitalWrite(leftmotor2,LOW);
digitalWrite(rightmotor1,HIGH);
digitalWrite(rightmotor2,LOW);
}

void MainWindow::on_backward_clicked()
{
    digitalWrite(leftmotor1,LOW);
    digitalWrite(leftmotor2,HIGH);
    digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,HIGH);
}

void MainWindow::on_stop_clicked()
{
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,HIGH);
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,HIGH);
}

void MainWindow::on_left_pressed()
{
    digitalWrite(leftmotor1,LOW);
    digitalWrite(leftmotor2,HIGH);
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,LOW);
}

void MainWindow::on_left_released()
{
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,HIGH);
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,HIGH);
}

void MainWindow::on_right_pressed()
{
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,LOW);
    digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,HIGH);
}

void MainWindow::on_right_released()
{
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,HIGH);
    digitalWrite(rightmotor1,HIGH);
    digitalWrite(rightmotor2,HIGH);
}
