#ifndef RELOCATIONDIALOG_H
#define RELOCATIONDIALOG_H

#include <QDialog>

namespace Ui {
class relocationDialog;
}

class relocationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit relocationDialog(QWidget *parent = nullptr);
    ~relocationDialog();

private:
    Ui::relocationDialog *ui;
};

#endif // RELOCATIONDIALOG_H
