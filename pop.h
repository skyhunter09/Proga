#ifndef POP_H
#define POP_H

#include <QMainWindow>

namespace Ui {
class pop;
}

class pop : public QMainWindow
{
    Q_OBJECT

public:
    explicit pop(QWidget *parent = 0);
    ~pop();

private slots:
    void on_actioncalk_triggered();

    void on_actionFile_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::pop *ui;
};

#endif // POP_H
