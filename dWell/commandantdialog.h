#ifndef COMMANDANTDIALOG_H
#define COMMANDANTDIALOG_H

#include <QDialog>

#include "rbook.h"
#include "config.h"

namespace Ui {
class commandantDialog;
}

class commandantDialog : public QDialog
{
    Q_OBJECT

public:
    explicit commandantDialog(QWidget *parent = nullptr);
    ~commandantDialog();

private:
    rbook *m_rbook;
    Ui::commandantDialog *ui;

private slots:
    void updateTable();
};

#endif // COMMANDANTDIALOG_H
