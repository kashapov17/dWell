#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class studentDialog;
}

class studentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit studentDialog(QWidget *parent = nullptr);
    ~studentDialog();


private slots:
    void on_docqButton_clicked();

    void on_relocqButton_clicked();

private:
    Ui::studentDialog *ui;
};

#endif // STUDENTDIALOG_H
