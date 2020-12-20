#include "initsetupdialog.h"
#include "ui_initsetupdialog.h"

#include "ubook.h"
#include "dormitory.h"
#include "rbook.h"

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
    QString adminName = ui->admiLogin->text();
    QString adminPasswd = ui->adminPasswd->text();
    user admin(adminName, adminPasswd, user::utype::ADMIN);
    ubook usersbook;
    usersbook.insert(admin);

    QString dormName = ui->dormName->text();
    uint roomCap = ui->comboBox->currentText().toUInt();
    uint dormCap = ui->dormCapBox->text().toUInt();
    dormitory dorm(dormName, roomCap, dormCap);

    rbook rb;
    rb.touchFile(dormCap, roomCap);

    QDialog::accept();
}
