#include "usereditdialog.h"
#include "ui_usereditdialog.h"

userEditDialog::userEditDialog(QWidget *parent, ubook *ub) :
    QDialog(parent),
    ui(new Ui::userEditDialog)
{
    ui->setupUi(this);
    m_ubook = ub;
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
    user u(username, passwd, type);
    m_ubook->insert(u);
    QDialog::accept();
}
