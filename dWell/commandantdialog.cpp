#include "commandantdialog.h"
#include "ui_commandantdialog.h"

commandantDialog::commandantDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commandantDialog)
{
    ui->setupUi(this);
}

commandantDialog::~commandantDialog()
{
    delete ui;
}
