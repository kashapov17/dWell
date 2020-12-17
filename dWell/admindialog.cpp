#include "admindialog.h"
#include "ui_admindialog.h"

#include "usereditdialog.h"

#include <QMessageBox>

adminDialog::adminDialog(QWidget *parent, ubook *users) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
    m_ubook = users;

    connect(m_ubook, &ubook::dataChanged, this, &adminDialog::updateTable);
    connect(ui->tableWidget->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this]
    {
        // отключаем кнопку "удалить", если нет выделенных пользователей
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
    userEditDialog userAddtDlg(this, m_ubook);
    user *u = new user;
    userAddtDlg.setUser(u);
    userAddtDlg.setWindowTitle("Создание пользователя");
    if (userAddtDlg.exec() != userEditDialog::Accepted)
    {
        return;
    }
    m_ubook->insert(*u);
}

void adminDialog::on_removeButton_clicked()
{
    int idx = ui->tableWidget->currentIndex().row();
    QMessageBox::StandardButtons ret = QMessageBox::question(this, "Удаление пользователя", QString("Вы действительно хотите "
                                                                 "удалить пользователя <b><i>%1</i></b>?").arg((*m_ubook)[idx].name()));
    if (ret == QMessageBox::No) return;
    m_ubook->erase(idx);
}

void adminDialog::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    userEditDialog userEditDlg(this, m_ubook);
    user *u = const_cast<user *>(&(*m_ubook)[index.row()]);
    userEditDlg.setUserForEdit(u);
    userEditDlg.setWindowTitle("Редактирование пользователя");
    if (userEditDlg.exec() != userEditDialog::Accepted) return;
    emit m_ubook->dataChanged();
}

void adminDialog::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    for (uint i = 0; i < m_ubook->size(); i++)
    {
        QTableWidgetItem *username = new QTableWidgetItem((*m_ubook)[i].name());
        QTableWidgetItem *usertype = nullptr;
        switch ((*m_ubook)[i].type())
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

void adminDialog::on_logoutButton_clicked()
{
    this->close();
}
