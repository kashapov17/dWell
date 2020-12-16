#include "admindialog.h"
#include "ui_admindialog.h"

#include "usereditdialog.h"

adminDialog::adminDialog(QWidget *parent, ubook *users) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
    m_ubook = users;

    connect(m_ubook, &ubook::dataChanged, this, &adminDialog::updateTable);

    updateTable();
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_addButton_clicked()
{
    userEditDialog userEditDlg(this, m_ubook);
    userEditDlg.setWindowTitle("Создание пользователя");
    userEditDlg.exec();
}

void adminDialog::on_removeButton_clicked()
{

}


void adminDialog::updateTable()
{
    ui->tableWidget->clearContents();
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
                usertype = new QTableWidgetItem("студент");
                break;
        default:
            break;
        }

        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, username);
        ui->tableWidget->setItem(i, 1, usertype);
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
}

