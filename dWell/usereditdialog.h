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
    explicit userEditDialog(QWidget *parent = nullptr);
    ~userEditDialog();
    void setUser(user *u);
    void setUserForEdit(user *u);

private:
    user *m_user;
    Ui::userEditDialog *ui;

public slots:
    /// Обрабатывает подтверждение диалога.
    void accept();
};

#endif // USEREDITDIALOG_H
