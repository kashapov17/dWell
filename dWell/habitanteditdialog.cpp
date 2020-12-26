#include "habitanteditdialog.h"
#include "ui_habitanteditdialog.h"

#include <QMessageBox>

habitantEditDialog::habitantEditDialog(QWidget *parent, QStringList availRooms) :
    QDialog(parent),
    ui(new Ui::habitantEditDialog)
{
    ui->setupUi(this);
    ui->roomNumBox->addItems(availRooms);
}

habitantEditDialog::~habitantEditDialog()
{
    delete ui;
}

void habitantEditDialog::accept()
{
    habitant::habitantData hb;
    hb.lname = ui->lnameEdit->text().trimmed();
    hb.fname = ui->fnameEdit->text().trimmed();
    hb.patronymic = ui->patroEdit->text().trimmed();
    hb.birthDate = ui->bdateEdit->date();
    hb.studentID = ui->studentID->text().toUInt();
    hb.group = ui->groupEdit->text();
    hb.numOfCourse = ui->courseBox->currentText().toUInt();
    hb.roomNumber = ui->roomNumBox->currentText().toUInt();
    if(!mHabitant->setData(&hb))
        QMessageBox::warning(this, "Ошибка", "Введены некорректные данные", QMessageBox::StandardButton::Ok);
    else
        QDialog::accept();
}
