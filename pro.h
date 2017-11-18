#ifndef PRO_H
#define PRO_H

#include <QMainWindow>
#include <pcap.h>
#include "pcap.h"



namespace Ui {
class Pro;
}

class Pro : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pro(QWidget *parent = 0);
    ~Pro();
public:
    void readFile();
private slots:
    void on_actionreturn_triggered();

    void on_actionfile_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Pro *ui;
};

#endif // PRO_H
