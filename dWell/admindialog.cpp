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
    //ui->removeButton->setDisabled(!ui->tableWidget->selectionModel()
    //                              ->hasSelection());
    connect(ui->tableWidget->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this]
    {
        // отключаем кнопку "удалить", если нет выделенных потльзователей
        ui->removeButton->setDisabled(!ui->tableWidget->selectionModel()
                                                         ->hasSelection());
    });

    updateTable();
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::on_addButton_clicked()
{
    userEditDialog userAddtDlg(this);
    user *u = new user;
    userAddtDlg.setUser(u);
    userAddtDlg.setWindowTitle("Создание пользователя");
    userAddtDlg.exec();
    if (userAddtDlg.exec() != userEditDialog::Accepted)
    {
        return;
    }
    m_ubook->insert(*u);
}

void adminDialog::on_removeButton_clicked()
{
    m_ubook->erase(ui->tableWidget->currentIndex().row());
}

void adminDialog::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    userEditDialog userEditDlg(this);
    user *u = const_cast<user *>(&(*m_ubook)[index.row()]);
    userEditDlg.setUserForEdit(u);
    userEditDlg.setWindowTitle("Редактирование пользователя");
    if (userEditDlg.exec() != userEditDialog::Accepted)
    {
        return;
    }
    emit m_ubook->dataChanged();
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


