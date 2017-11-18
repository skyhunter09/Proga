#include "nachalo.h"
#include "ui_nachalo.h"
#include "mainwindow.h"

nachalo::nachalo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nachalo)
{
    ui->setupUi(this);
}

nachalo::~nachalo()
{
    delete ui;
}

void nachalo::on_actionopen_calculator_triggered()
{

  MainWindow *www= new MainWindow;
  www->show();
}

