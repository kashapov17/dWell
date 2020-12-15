#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent, ubook *users) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
    m_ubook = users;
    updateTable();
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

void adminDialog::updateTable()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
}
