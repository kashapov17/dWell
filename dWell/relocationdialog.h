#ifndef RELOCATIONDIALOG_H
#define RELOCATIONDIALOG_H

#include <QDialog>

#include "habitant.h"

namespace Ui {
class relocationDialog;
}

class relocationDialog : public QDialog
{
    Q_OBJECT

public:
    relocationDialog(QWidget *parent, QStringList availRooms);
    ~relocationDialog();
    void setHabitant(habitant *h);

private:
    habitant *mHabitant;
    Ui::relocationDialog *ui;

private slots:
    /// Обрабатывает подтверждение диалога.
    void accept();
};

#endif // RELOCATIONDIALOG_H
