#include "commandantdialog.h"
#include "ui_commandantdialog.h"

#include "habitanteditdialog.h"
#include "habitant.h"

#include <QMessageBox>

commandantDialog::commandantDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commandantDialog)
{
    ui->setupUi(this);
    ui->tableWidget->resizeColumnsToContents();
    m_rbook = rbook::getRbook();

    connect(ui->tableWidget->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this]
    {
        // отключаем кнопку "удалить", если нет выделенных пользователей
        ui->checkoutButton->setDisabled(!ui->tableWidget->selectionModel()
                                                         ->hasSelection());
    });

    connect(m_rbook, &rbook::dataChanged, this, &commandantDialog::updateTable);
    updateTable();
}

commandantDialog::~commandantDialog()
{
    delete ui;
}

void commandantDialog::updateTable()
{
    ui->tableWidget->setRowCount(0);
    for (uint i=0; i < m_rbook->size(); i++)
    {
        auto room = (*m_rbook)[i];
        for (uint j=0; j < room.size(); j++) {
            auto habitant = room[j];
            QTableWidgetItem *roomNumber = new QTableWidgetItem(QString("%1").arg(habitant.roomNumber()));
            QTableWidgetItem *name = new QTableWidgetItem(QString("%1 %2 %3")
                                                          .arg(habitant.fname(),
                                                               habitant.lname(),
                                                               habitant.patronymic()));
            QTableWidgetItem *bdate = new QTableWidgetItem(habitant.birthDate().toString("dd.MM.yyyy"));
            QTableWidgetItem *sid = new QTableWidgetItem(QString("%1").arg(habitant.studentID()));

            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, roomNumber);
            ui->tableWidget->setItem(i, 1, sid);
            ui->tableWidget->setItem(i, 2, name);
            ui->tableWidget->setItem(i, 3, bdate);
        }
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
}

void commandantDialog::on_checkinButton_clicked()
{
    QStringList availRooms;
    for (uint i=0; i < m_rbook->size(); i++)
    {
        if ((*m_rbook)[i].availableForCheckin())
            availRooms << QString("%1").arg((*m_rbook)[i].number());
    }
    habitantEditDialog habAddtDlg(this, availRooms);
    habitant *h = new habitant;
    habAddtDlg.setHabitant(h);
    habAddtDlg.setWindowTitle("Создание пользователя");
    if (habAddtDlg.exec() != habitantEditDialog::Accepted)
    {
        return;
    }
    m_rbook->checkin(h->roomNumber(), h);
}

void commandantDialog::on_pushButton_clicked()
{
    this->close();
}

void commandantDialog::on_checkoutButton_clicked()
{
    int row = ui->tableWidget->currentIndex().row();
    auto room =  ui->tableWidget->item(row, 0)->text().toUInt();
    auto sid = ui->tableWidget->item(row, 1)->text().toUInt();
    m_rbook->checkout(room, sid);
}

void commandantDialog::on_relocButton_clicked()
{
    int row = ui->tableWidget->currentIndex().row();
    auto curRoom =  ui->tableWidget->item(row, 0)->text().toUInt();
    auto sid = ui->tableWidget->item(row, 1)->text().toUInt();

    QStringList availRooms;
    for (uint i=0; i < m_rbook->size(); i++)
    {
        if ((*m_rbook)[i].number() == curRoom) // exclude current habitant's room
            continue;
        if ((*m_rbook)[i].availableForCheckin())
            availRooms << QString("%1").arg((*m_rbook)[i].number());
    }

    if (availRooms.size() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Нет доступных мест", QMessageBox::Ok);
        return;
    }

}

void commandantDialog::on_giveDocButton_clicked()
{

}
