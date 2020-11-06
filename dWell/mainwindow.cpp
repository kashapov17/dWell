#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "config.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbout_Qt, &QAction::triggered, [this] {about_qt();});
    connect(ui->actionAbout_dWell, &QAction::triggered, [this] {about_dwell();});
    connect(ui->actionAutors, &QAction::triggered, [this] {about_autors();});
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
