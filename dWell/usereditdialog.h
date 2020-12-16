#ifndef USEREDITDIALOG_H
#define USEREDITDIALOG_H

#include <QDialog>

#include "ubook.h"

namespace Ui {
class userEditDialog;
}

class userEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit userEditDialog(QWidget *parent, ubook *ub);
    ~userEditDialog();

private:
    ubook *m_ubook;
    Ui::userEditDialog *ui;

public slots:
    /// Обрабатывает подтверждение диалога.
    void accept();
};

#endif // USEREDITDIALOG_H
