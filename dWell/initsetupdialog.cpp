#include "initsetupdialog.h"
#include "ui_initsetupdialog.h"

#include "user.h"
#include "ubook.h"
#include "dormitory.h"

initSetupDialog::initSetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::initSetupDialog)
{
    ui->setupUi(this);
}

initSetupDialog::~initSetupDialog()
{
    delete ui;
}

void initSetupDialog::accept()
{
    QString dormName = ui->dormName->text();
    uint8_t roomSlots = uint8_t(ui->comboBox->currentText().toInt());
    QString adminName = ui->admiLogin->text();
    QString adminPasswd = ui->adminPasswd->text();
    user admin = user(adminName, adminPasswd, user::utype::ADMIN);
    ubook usersbook;
    usersbook.insert(admin);
    dormitory dorm = dormitory(dormName, roomSlots);
    QDialog::accept();
}
