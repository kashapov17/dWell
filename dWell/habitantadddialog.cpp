#include "habitantadddialog.h"
#include "ui_habitantadddialog.h"

habitantAddDialog::habitantAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::habitantAddDialog)
{
    ui->setupUi(this);
}

habitantAddDialog::~habitantAddDialog()
{
    delete ui;
}
