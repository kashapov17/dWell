#ifndef HABITANT_H
#define HABITANT_H

#include <QString>
#include <QDate>


class habitant
{
public:
    habitant();

private:
    QString fname;
    QString lname;
    QString patronymic;
    QDate birthDate;
    uint studentID;
    uint numOfCourse;
    uint group;
    uint roomNumber;

};

#endif // HABITANT_H
