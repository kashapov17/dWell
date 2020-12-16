#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>

#include "ubook.h"

namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit adminDialog(QWidget *parent, ubook *);
    ~adminDialog();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void updateTable();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

private:
    ubook *m_ubook;
    Ui::adminDialog *ui;
};

#endif // ADMINDIALOG_H
