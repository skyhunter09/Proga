#include "pop.h"
#include "ui_pop.h"
#include "mainwindow.h"
#include "pro.h"
pop::pop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pop)
{
    ui->setupUi(this);
}

pop::~pop()
{
    delete ui;
}

void pop::on_actioncalk_triggered()
{
   MainWindow *xxx=new MainWindow(this);
            xxx->show();
}

void pop::on_actionFile_triggered()
{
    Pro *p=new Pro(this);
    p->show();
}

void pop::on_pushButton_clicked()
{
    MainWindow *xxx=new MainWindow(this);
             xxx->show();
}

void pop::on_pushButton_2_clicked()
{
    Pro *p=new Pro(this);
    p->show();
}
