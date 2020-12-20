#include "commandantdialog.h"
#include "ui_commandantdialog.h"

#include "habitanteditdialog.h"
#include "habitant.h"

commandantDialog::commandantDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commandantDialog)
{
    ui->setupUi(this);
    ui->tableWidget->resizeColumnsToContents();
    m_rbook = rbook::getRbook();

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
            QTableWidgetItem *roomNumber = new QTableWidgetItem(habitant.roomNumber());
            QTableWidgetItem *name = new QTableWidgetItem(QString("%1 %2 %3")
                                                          .arg(habitant.fname(),
                                                               habitant.lname(),
                                                               habitant.patronymic()));
            QTableWidgetItem *bdate = new QTableWidgetItem(habitant.birthDate().toString("dd.MM.yyyy"));
            QTableWidgetItem *sid = new QTableWidgetItem(habitant.studentID());

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
