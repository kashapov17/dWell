#include "relocationdialog.h"
#include "ui_relocationdialog.h"

relocationDialog::relocationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::relocationDialog)
{
    ui->setupUi(this);
}

relocationDialog::~relocationDialog()
{
    delete ui;
}
