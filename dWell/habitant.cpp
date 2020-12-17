#include "habitant.h"

habitant::habitant()
{}

habitant::habitant(habitantData *h)
{
    setData(h);
}

void habitant::setData(habitantData *h)
{
    mFname = h->fname;
    mLname = h->lname;
    mPatronymic = h->patronymic;
    mBirthDate = h->birthDate;
    mStudentID = h->studentID;
    mNumOfCourse = h->numOfCourse;
    mGroup = h->group;
    mRoomNumber = h->roomNumber;
}
