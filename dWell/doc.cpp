#include "doc.h"
#include "dormitory.h"

#include <QPdfWriter>
#include <QPainter>
#include <QStandardPaths>
#include <QTextDocument>

doc::doc()
{}

void doc::generate(const habitant *h)
{
    dormitory *dorm = dormitory::getDormCfg();
    QString html = QString ("<p style=\"text-align: center;\"><strong>СПРАВКА </strong></p>"
            "<p style=\"text-align: center;\">&nbsp;</p>"
            "<p style=\"text-align: center;\">&nbsp;</p>"
            "<p style=\"text-align: justify; padding-left: 40px;\">Дана студенту %1 %2 года рождения в том, что"
            "он действительно является студентом, проживающим в общежитии %3, комната %4.</p>:"
            "<p style=\"text-align: justify;\">&nbsp;</p>"
            "<p style=\"text-align: justify; padding-left: 40px;\">Справка выдана для предъявления по месту требования.</p>"
            "<p style=\"text-align: justify; padding-left: 40px;\">&nbsp;</p>"
            "<p style=\"text-align: justify; padding-left: 440px;\">М. П.</p>"
            "<p style=\"text-align: justify; padding-left: 40px;\">&nbsp;</p>"
            "<p style=\"text-align: justify; padding-left: 40px;\">Дата %5</p>")
                .arg(h->fname() + " " + h->lname() + " " + h->patronymic())
                .arg(h->birthDate().toString())
                .arg(dorm->name())
                .arg(h->roomNumber())
                .arg(QDateTime::currentDateTime().toString());
    QTextDocument document;
    document.setHtml(html);

    QString filename = QString("dWell_%1_%2_%3").arg(h->fname()).arg(h->lname()).arg(h->studentID());
    QPdfWriter pdfwriter(QStandardPaths::displayName(QStandardPaths::DocumentsLocation) + filename);
    pdfwriter.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&pdfwriter);
    painter.drawText(0,0, html);
}
