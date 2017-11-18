#include "mainwindow.h"
#include "pop.h"
#include <QApplication>
#include "pro.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pop w;
        w.show();


    return a.exec();
}
