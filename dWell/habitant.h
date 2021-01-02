#ifndef HABITANT_H
#define HABITANT_H

#include <QString>
#include <QDate>
#include <QDataStream>

class habitant
{

public:
    struct habitantData
    {
        QString fname;
        QString lname;
        QString patronymic;
        QDate birthDate;
        uint studentID;
        uint numOfCourse;
        QString group;
        uint roomNumber;
    };

    habitant() {}
    habitant(habitantData *hd);
    bool setData(habitantData *hd);
    habitantData *getData() const;

    const QString fname() const;
    const QString lname() const;
    const QString patronymic() const;
    const QDate birthDate() const;
    uint studentID() const;
    uint numOfCourse() const;
    QString group() const;
    uint roomNumber() const;

private:
    QString mFname;
    QString mLname;
    QString mPatronymic;
    QDate mBirthDate;
    uint mStudentID;
    uint mNumOfCourse;
    QString mGroup;
    uint mRoomNumber;
};

inline QDataStream &operator<< (QDataStream &ost, const habitant &h)
{
    ost << h.group() << h.roomNumber() << h.fname() << h.lname() << h.patronymic() << h.birthDate()
        << h.studentID() << h.numOfCourse();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, habitant &h)
{
    habitant::habitantData hd;
    ist >> hd.group >> hd.roomNumber >> hd.fname >> hd.lname >> hd.patronymic;
    ist >> hd.birthDate >> hd.studentID >> hd.numOfCourse;
    h.setData(&hd);
    return ist;
}

#endif // HABITANT_H
