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

    habitant();
    habitant(habitantData *hd);
    void setData(habitantData *hd);

    const QString fname() const {return mFname;}
    const QString lname() const {return mLname;}
    const QString patronymic() const {return mPatronymic;}
    const QDate birthDate() const {return mBirthDate;}
    uint studentID() const {return mStudentID;}
    uint numOfCourse() const {return mNumOfCourse;}
    QString group() const {return mGroup;}
    uint roomNumber() const {return mRoomNumber;}
    void changeRoom(uint n) {mRoomNumber = n;}

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

// Запись проживающего в поток
inline QDataStream &operator<< (QDataStream &ost, const habitant &h)
{
    ost << h.group() << h.roomNumber() << h.fname() << h.lname() << h.patronymic() << h.birthDate()
        << h.studentID() << h.numOfCourse();
    return ost;
}

// Считывание проживающего из потока
inline QDataStream &operator>> (QDataStream &ist, habitant &h)
{
    habitant::habitantData hd;
    ist >> hd.group >> hd.roomNumber >> hd.fname >> hd.lname >> hd.patronymic;
    ist >> hd.birthDate >> hd.studentID >> hd.numOfCourse;
    h.setData(&hd);
    return ist;
}

#endif // HABITANT_H
