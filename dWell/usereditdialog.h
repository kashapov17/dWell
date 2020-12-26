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
    explicit userEditDialog(QWidget *parent);
    ~userEditDialog();
    void setUser(user *u);
    void setUserForEdit(user *u);

private:
    bool editMode;
    ubook *m_ubook;
    user *m_user;
    Ui::userEditDialog *ui;

private slots:
    /// Обрабатывает подтверждение диалога.
    void accept();
    void on_usernameEdit_textChanged(const QString &username);
    void on_passwdEdit_textChanged(const QString &passwd);
};

#endif // USEREDITDIALOG_H
