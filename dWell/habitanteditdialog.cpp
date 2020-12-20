#include "habitanteditdialog.h"
#include "ui_habitanteditdialog.h"

habitantEditDialog::habitantEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::habitantEditDialog)
{
    ui->setupUi(this);
}

habitantEditDialog::~habitantEditDialog()
{
    delete ui;
}
