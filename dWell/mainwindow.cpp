#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QFile>
#include <QLineEdit>
#include <QVBoxLayout>

#include "config.h"
#include "user.h"

#include "admindialog.h"
#include "commandantdialog.h"
#include "studentdialog.h"
#include "initsetupdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAbout_Qt, &QAction::triggered, [this] {about_qt();});
    connect(ui->actionAbout_dWell, &QAction::triggered, [this] {about_dwell();});
    connect(ui->actionAutors, &QAction::triggered, [this] {about_autors();});

    if (!QFile(config::fileUsers).exists())
    {
        QMessageBox::warning(this, "Ошибка", "<b>Система не инсталлирована<b>\n"
                                             "Будет открыто окно начальной настройки.",
                             QMessageBox::Ok);
        initSetupDialog *initDlg = new initSetupDialog(this);
        initDlg->setWindowTitle("Мастер начальной настройки");
        initDlg->exec();
    }
    usersbook.loadFromFile(config::fileUsers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about_qt()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::about_autors()
{
    QMessageBox aboutDlg(this);
    aboutDlg.setTextFormat(Qt::RichText);
    aboutDlg.setIcon(QMessageBox::Information);
    aboutDlg.setWindowTitle(tr("About autors"));
    aboutDlg.setText(tr("<a href=\"mailto:ykashapov-ki19@stud.sfu-kras.ru\">"
                        "Yaroslav Kashapov Fanizovich</a>, 2020."));
    aboutDlg.exec();
}

void MainWindow::about_dwell()
{
    QMessageBox aboutDlg(this);
    aboutDlg.setTextFormat(Qt::RichText);
    aboutDlg.setIcon(QMessageBox::Information);
    aboutDlg.setWindowTitle(tr("About %1").arg(config::applicationName));
    aboutDlg.setText(tr("%1 %2<br>"
            "Sourses: <a href=\"https://github.com/kashapovd/dWell\">github</a><br>"
            "License: MIT.<br>"
            "This application is dynamically linked against the<br>"
            "<a href=\"https://www.qt.io/developers/\">Qt Library</a> "
            "v. %3.")
            .arg(config::applicationName).arg(config::applicationVersion)
            .arg(qVersion()));
    aboutDlg.exec();
}

void MainWindow::on_loginButton_clicked()
{

    const QString login = ui->usernameEdit->text();
    const QString password = ui->passwdEdit->text();
    auto interfaceType = usersbook.findUser(login.trimmed(), password.trimmed());

    switch (interfaceType)
    {
        case user::utype::ADMIN:
        {
            adminDialog *adminDlg = new adminDialog(this, reinterpret_cast<ubook*>(&usersbook));
            adminDlg->setWindowTitle("Панель администрирования");
            adminDlg->exec();
        }
        break;
        case user::utype::COMMANDANT:
        {
            commandantDialog *comDlg = new commandantDialog(this);
            comDlg->setWindowTitle("Панель управления проживающими");
            comDlg->exec();
        }
        break;
        case user::utype::STUDENT:
        {
            studentDialog *studDlg = new studentDialog(this);
            studDlg->setWindowTitle("Личный кабинет студента");
            studDlg->exec();
        }
            break;
        default:
            QMessageBox::critical(this, "Ошибка", "Неверный пароль или логин", QMessageBox::Ok);
    }
    ui->usernameEdit->clear();
    ui->passwdEdit->clear();
    ui->usernameEdit->activateWindow();
}
