#include "usereditdialog.h"
#include "ui_usereditdialog.h"

#include "tools.h"

#include <QMessageBox>

userEditDialog::userEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userEditDialog)
{
    m_ubook = tools::getUbook();
    ui->setupUi(this);
}

userEditDialog::~userEditDialog()
{
    delete ui;
}

void userEditDialog::accept()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString passwd = ui->passwdEdit->text().trimmed();
    user::utype type = user::utype(ui->typeBox->currentIndex());
    if(m_ubook->findUserByName(username) != user::UNKNOWN)
        QMessageBox::warning(this, "Ошибка", "Такой пользователь уже существует", QMessageBox::StandardButton::Ok);
    else
    {
        if(!m_user->setData(username, passwd, type))
            QMessageBox::warning(this, "Ошибка", "Введены некорректные данные", QMessageBox::StandardButton::Ok);
        else
            QDialog::accept();
    }
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
    ui->saveButton->setDisabled(username.trimmed().isEmpty() or ui->passwdEdit->text().trimmed().isEmpty());
}

void userEditDialog::on_passwdEdit_textChanged(const QString &passwd)
{
    ui->saveButton->setDisabled(passwd.trimmed().isEmpty() or ui->usernameEdit->text().trimmed().isEmpty());
}
