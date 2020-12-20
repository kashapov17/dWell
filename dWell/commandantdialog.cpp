#include "commandantdialog.h"
#include "ui_commandantdialog.h"



commandantDialog::commandantDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commandantDialog)
{
    ui->setupUi(this);
    ui->tableWidget->resizeColumnsToContents();
    m_rbook = new rbook;
    m_rbook->loadFromFile(config::fileRooms);
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
            if (room.isEmpty())
                continue;
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

}
