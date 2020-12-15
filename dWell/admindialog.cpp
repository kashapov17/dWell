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
    for (uint i = 0; i < m_ubook->size(); i++)
    {
        QTableWidgetItem *username = new QTableWidgetItem(m_ubook->operator[](i).name());
        QTableWidgetItem *usertype = nullptr;
        switch (m_ubook->operator[](i).type())
        {
        case user::utype::ADMIN:
            usertype = new QTableWidgetItem("админ");
            break;
        case user::utype::COMMANDANT:
            usertype = new QTableWidgetItem("комендант");
            break;
        case user::utype::STUDENT:
                usertype = new QTableWidgetItem("комендант");
                break;
        default:
            break;
        }

        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, username);
        ui->tableWidget->setItem(i, 1, usertype);
    }
}
