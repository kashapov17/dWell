#ifndef HABITANTADDDIALOG_H
#define HABITANTADDDIALOG_H

#include <QDialog>

namespace Ui {
class habitantAddDialog;
}

class habitantAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit habitantAddDialog(QWidget *parent = nullptr);
    ~habitantAddDialog();

private:
    Ui::habitantAddDialog *ui;
};

#endif // HABITANTADDDIALOG_H
