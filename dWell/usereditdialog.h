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
    void setUser(user *u);
    void setUserForEdit(user *u);

private:
    ubook *m_ubook;
    user *m_user;
    Ui::userEditDialog *ui;

private slots:
    /// Обрабатывает подтверждение диалога.
    void accept();
    void on_usernameEdit_textChanged(const QString &arg1);
    void on_passwdEdit_textChanged(const QString &arg1);
};

#endif // USEREDITDIALOG_H
