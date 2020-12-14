#ifndef COMMANDANTDIALOG_H
#define COMMANDANTDIALOG_H

#include <QDialog>

namespace Ui {
class commandantDialog;
}

class commandantDialog : public QDialog
{
    Q_OBJECT

public:
    explicit commandantDialog(QWidget *parent = nullptr);
    ~commandantDialog();

private:
    Ui::commandantDialog *ui;
};

#endif // COMMANDANTDIALOG_H
