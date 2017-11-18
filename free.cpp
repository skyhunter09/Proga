#include "free.h"
#include "nachalo.h"
#include "ui_free.h"
#include "cmath"

free::free(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::free)
{
    ui->setupUi(this);
}

free::~free()
{
    delete ui;
}

void free::on_one_clicked()
{
     QString str1 = ui->lineEdit->text();
      QString str2 = ui->lineEdit_2->text();
      QString finalStr=str1+str2;
      ui->lineEdit_3->setText(finalStr);
}
