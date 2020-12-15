#ifndef USERADDDIALOG_H
#define USERADDDIALOG_H

#include <QDialog>

namespace Ui {
class useraddDialog;
}

class useraddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit useraddDialog(QWidget *parent = nullptr);
    ~useraddDialog();

private:
    Ui::useraddDialog *ui;
};

#endif // USERADDDIALOG_H
