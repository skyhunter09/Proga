#include "mainwindow.h"
#include "pop.h"
#include "ui_mainwindow.h"
#include "cmath"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
long long a,b,q;
long long global=0;
void MainWindow::on_one_clicked()
{
    global=global*10+1;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_Enter_clicked()
{
    if (q==1)
    {
        b=global;
        ui->Text->setText(QString::number(a+b));
        global=0;
        a=0;
        b=0;
    }
    if (q==2)
    {
        b=global;
        ui->Text->setText(QString::number(a-b));
        global=0;
        a=0;
        b=0;
    }
    if (q==3)
    {
        b=global;
        ui->Text->setText(QString::number(a/b));
        global=0;
        a=0;
        b=0;
    }
    if (q==4)
    {
        b=global;
        ui->Text->setText(QString::number(a*b));
        global=0;
        a=0;
        b=0;
    }

}

void MainWindow::on_pl_clicked()
{
    q=1;
    a=global;
    ui->Text->setText(QString::number(0));
    global=0;

}

void MainWindow::on_pushButton_clicked()
{
    global=global*10+2;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_2_clicked()
{
    global=global*10+3;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_3_clicked()
{
    global=global*10+4;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_4_clicked()
{
    global=global*10+5;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_5_clicked()
{
    global=global*10+6;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_6_clicked()
{
    global=global*10+7;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_7_clicked()
{
    global=global*10+8;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_8_clicked()
{
    global=global*10+9;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_9_clicked()
{
    q=2;
    a=global;
    ui->Text->setText(QString::number(0));
    global=0;
}

void MainWindow::on_pushButton_10_clicked()
{
    q=3;
    a=global;
    ui->Text->setText(QString::number(0));
    global=0;
}

void MainWindow::on_pushButton_11_clicked()
{
    q=4;
    a=global;
    ui->Text->setText(QString::number(0));
    global=0;
}

void MainWindow::on_pushButton_12_clicked()
{
    a=0;
    b=0;
    global=0;
    ui->Text->setText(QString::number(0));
}

void MainWindow::on_pushButton_13_clicked()
{
    global=global*10;
    ui->Text->setText(QString::number(global));
}

void MainWindow::on_pushButton_14_clicked()
{
   pop *zzz= new pop;
    zzz->show();
}


void MainWindow::on_o_clicked()
{
    global=global/10;
    ui->Text->setText(QString::number(global));
}

