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

private:
    Ui::adminDialog *ui;
};

#endif // ADMINDIALOG_H
