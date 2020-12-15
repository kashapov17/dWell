#include "useradddialog.h"
#include "ui_useradddialog.h"

useraddDialog::useraddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::useraddDialog)
{
    ui->setupUi(this);
}

useraddDialog::~useraddDialog()
{
    delete ui;
}
