#include "usereditdialog.h"
#include "ui_usereditdialog.h"

#include <QMessageBox>

userEditDialog::userEditDialog(QWidget *parent, ubook *ub) :
    QDialog(parent),
    ui(new Ui::userEditDialog)
{
    m_ubook = ub;
    ui->setupUi(this);
}

userEditDialog::~userEditDialog()
{
    delete ui;
}

void userEditDialog::accept()
{
    QString username = ui->usernameEdit->text();
    QString passwd = ui->passwdEdit->text();
    user::utype type = user::utype(ui->typeBox->currentIndex());
//    user *u = new user;
//    ubook::userError e = m_ubook->checkUser(m_user);
    m_user->setData(username, passwd, type);
//    if (e != ubook::OK)
//        QMessageBox::warning(this, "Ошибка", m_ubook->userErrorToString(e), QMessageBox::StandardButton::Ok);
//    else
        QDialog::accept();
}

void userEditDialog::setUser(user *u)
{
    m_user = u;
}

void userEditDialog::setUserForEdit(user *u)
{
    setUser(u);
    ui->usernameEdit->setText(u->name());
    ui->passwdEdit->setText(u->passwd());
    ui->typeBox->setCurrentIndex(u->type());
}

void userEditDialog::on_usernameEdit_textChanged(const QString &username)
{
    ui->saveButton->setDisabled(username.isEmpty() or ui->passwdEdit->text().isEmpty());
}

void userEditDialog::on_passwdEdit_textChanged(const QString &passwd)
{
    ui->saveButton->setDisabled(passwd.isEmpty() or ui->usernameEdit->text().isEmpty());
}
