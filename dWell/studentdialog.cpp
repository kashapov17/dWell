#include "studentdialog.h"
#include "ui_studentdialog.h"

studentDialog::studentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentDialog)
{
    ui->setupUi(this);
}

studentDialog::~studentDialog() {delete ui;}
