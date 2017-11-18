#ifndef NACHALO_H
#define NACHALO_H

#include <QMainWindow>

namespace Ui {
class nachalo;
}

class nachalo : public QMainWindow
{
    Q_OBJECT

public:
    explicit nachalo(QWidget *parent = 0);
    ~nachalo();

private slots:
    void on_actionopen_calculator_triggered();

    void on_label_linkActivated(const QString &link);

    void on_label_2_linkActivated(const QString &link);

    void on_label_linkHovered(const QString &link);

    void on_nachalo_iconSizeChanged(const QSize &iconSize);

private:
    Ui::nachalo *ui;
};

#endif // NACHALO_H
