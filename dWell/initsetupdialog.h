#ifndef INITSETUPDIALOG_H
#define INITSETUPDIALOG_H

#include <QDialog>

namespace Ui {
class initSetupDialog;
}

class initSetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit initSetupDialog(QWidget *parent = nullptr);
    ~initSetupDialog();

private:
    Ui::initSetupDialog *ui;

public slots:
    /// Обрабатывает подтверждение диалога.
    void accept() Q_DECL_OVERRIDE;
};

#endif // INITSETUPDIALOG_H
