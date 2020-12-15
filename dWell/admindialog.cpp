#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_addButton_clicked()
{

}

void adminDialog::on_pushButton_2_clicked()
{

}
