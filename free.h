#ifndef FREE_H
#define FREE_H

#include <QMainWindow>

namespace Ui {
class free;
}

class free : public QMainWindow
{
    Q_OBJECT

public:
    explicit free(QWidget *parent = 0);
    ~free();

private slots:
    void on_one_clicked();

private:
    Ui::free *ui;
};

#endif // FREE_H
