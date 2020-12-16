#include "usereditdialog.h"
#include "ui_usereditdialog.h"

userEditDialog::userEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userEditDialog)
{
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
    m_user->setData(username, passwd, type);
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
