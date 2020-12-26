#include "commandantdialog.h"
#include "ui_commandantdialog.h"

#include "habitanteditdialog.h"
#include "relocationdialog.h"
#include "doc.h"

#include <QMessageBox>

#define ROOM_COLUMN 0
#define SID_COLUMN 1
#define NAME_COLUMN 2
#define BDATE_COLUMN 3

commandantDialog::commandantDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commandantDialog)
{
    ui->setupUi(this);
    m_rbook = rbook::getRbook();

    connect(m_rbook, &rbook::dataChanged, this, &commandantDialog::updateTable);
    updateTable();

    ui->tableWidget->resizeColumnsToContents();

    ui->tableWidget->verticalHeader()->setVisible(false); // отключаем подпись строк таблицы

    connect(ui->tableWidget->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this]
    {
        // отключаем кнопку "удалить", если нет выделенных проживающих
        // или включаем, если они есть
        ui->checkoutButton->setDisabled(!ui->tableWidget->selectionModel()
                                                         ->hasSelection());
        // кнопка "переселить"
        ui->relocButton->setDisabled(!ui->tableWidget->selectionModel()
                                                         ->hasSelection());
        // кнопка "выдать справку"
        ui->giveDocButton->setDisabled(!ui->tableWidget->selectionModel()
                                                         ->hasSelection());
    });
}

commandantDialog::~commandantDialog() { delete ui; }

void commandantDialog::updateTable()
{
    ui->tableWidget->setRowCount(0);
    int row =0;
    for (uint i=0; i < m_rbook->size(); i++)
    {
        auto room = (*m_rbook)[i];
        for (uint j=0; j < room.size(); j++)
        {
            auto habitant = room[j];

            QTableWidgetItem *roomNumber = new QTableWidgetItem(QString("%1").arg(habitant.roomNumber()));
            QTableWidgetItem *name = new QTableWidgetItem(QString("%1 %2 %3")
                                                          .arg(habitant.fname(),
                                                               habitant.lname(),
                                                               habitant.patronymic()));
            QTableWidgetItem *bdate = new QTableWidgetItem(habitant.birthDate().toString("dd.MM.yyyy"));
            QTableWidgetItem *sid = new QTableWidgetItem(QString("%1").arg(habitant.studentID()));

            ui->tableWidget->insertRow (row);
            ui->tableWidget->setItem(row, ROOM_COLUMN, roomNumber);
            ui->tableWidget->setItem(row, SID_COLUMN, sid);
            ui->tableWidget->setItem(row, NAME_COLUMN, name);
            ui->tableWidget->setItem(row, BDATE_COLUMN, bdate);
            row++;
        }
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
}

void commandantDialog::on_checkinButton_clicked()
{
    QStringList availRooms;
    for (uint i=0; i < m_rbook->size(); i++)
        if ((*m_rbook)[i].availableForCheckin())
            availRooms << QString("%1").arg((*m_rbook)[i].number());

    habitantEditDialog habAddtDlg(this, availRooms);
    habitant *h = new habitant;
    habAddtDlg.setHabitant(h);
    habAddtDlg.setWindowTitle("Заселение проживающего");
    if (habAddtDlg.exec() != habitantEditDialog::Accepted)
        return;

    m_rbook->checkin(h->roomNumber(), h);
}

void commandantDialog::on_pushButton_clicked()
{
    this->close();
}

void commandantDialog::on_checkoutButton_clicked()
{
    int row = ui->tableWidget->currentIndex().row();
    auto room =  ui->tableWidget->item(row, ROOM_COLUMN)->text().toUInt();
    auto sid = ui->tableWidget->item(row, SID_COLUMN)->text().toUInt();
    m_rbook->checkout(room, sid);
}

void commandantDialog::on_relocButton_clicked()
{
    int row = ui->tableWidget->currentIndex().row();
    auto curRoom =  ui->tableWidget->item(row, ROOM_COLUMN)->text().toUInt();
    auto sid = ui->tableWidget->item(row, SID_COLUMN)->text().toUInt();

    QStringList availRooms;
    for (uint i=0; i < m_rbook->size(); i++)
    {
        auto room = (*m_rbook)[i];

        if (room.number() == curRoom) // exclude current habitant's room
            continue;
        if (room.availableForCheckin())
            availRooms << QString("%1").arg(room.number());
    }

    if (availRooms.size() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Нет доступных мест", QMessageBox::Ok);
        return;
    }

    auto oldh = m_rbook->getHabitantBySid(sid);
    relocationDialog relocDlg(this, availRooms);
    habitant *newh = new habitant(oldh->getData());
    relocDlg.setHabitant(newh);
    relocDlg.setWindowTitle("Переселение проживающего");
    if (relocDlg.exec() != habitantEditDialog::Accepted)
    {
        return;
    }

    m_rbook->checkin(newh->roomNumber(), newh);
    m_rbook->checkout(oldh->roomNumber(), oldh->studentID());
    updateTable();
}

void commandantDialog::on_giveDocButton_clicked()
{
    int row = ui->tableWidget->currentIndex().row();
    auto sid = ui->tableWidget->item(row, SID_COLUMN)->text().toUInt();
    auto h = m_rbook->getHabitantBySid(sid);
    doc::generate(h);
}
