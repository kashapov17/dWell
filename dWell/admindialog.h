#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>

namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminDialog(QWidget *parent = nullptr);
    ~adminDialog();

private slots:
    void on_addButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminDialog *ui;
};

#endif // ADMINDIALOG_H
