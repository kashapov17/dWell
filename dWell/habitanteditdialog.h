#ifndef HABITANTEDITDIALOG_H
#define HABITANTEDITDIALOG_H

#include <QDialog>

namespace Ui {
class habitantEditDialog;
}

class habitantEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit habitantEditDialog(QWidget *parent = nullptr);
    ~habitantEditDialog();

private:
    Ui::habitantEditDialog *ui;
};

#endif // HABITANTEDITDIALOG_H
