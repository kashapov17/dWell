#ifndef HABITANTEDITDIALOG_H
#define HABITANTEDITDIALOG_H

#include <QDialog>

#include "habitant.h"

namespace Ui {
class habitantEditDialog;
}

class habitantEditDialog : public QDialog
{
    Q_OBJECT

public:
    habitantEditDialog(QWidget *parent, QStringList availRooms);
    ~habitantEditDialog();
    void setHabitant(habitant *h) {mHabitant = h;};

private:
    habitant *mHabitant;
    Ui::habitantEditDialog *ui;

private slots:
    /// Обрабатывает подтверждение диалога.
    void accept();
};

#endif // HABITANTEDITDIALOG_H
