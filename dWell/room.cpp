#include "room.h"
#include "dormitory.h"
#include "config.h"

#include <iterator>

room::room()
{}

void room::checkin(habitant h)
{
    mHabitants.push_back(h);
}

void room::checkout(uint sid)
{
    auto it = findBySid(sid);
    if (it != mHabitants.end())
        mHabitants.erase(findBySid(sid));
}

QVector<habitant>::iterator room::findBySid(uint sid)
{
    for(QVector<habitant>::iterator it = mHabitants.begin(); it != mHabitants.end(); ++it)
    {
        if (it->studentID() == sid)
            return it;
    }
    return mHabitants.end();
}
