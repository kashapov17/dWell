#include "room.h"
#include "dormitory.h"
#include "config.h"

#include <iterator>

room::room()
{}

uint room::number() const
{
    return mNumber;
}

uint room::capacity() const
{
    return mHabitants.capacity();
}

uint room::size() const
{
    return mHabitants.size();
}

uint room::freeSlots() const
{
    return uint(capacity() - size());
}

const habitant &room::operator[](uint idx) const
{
    return mHabitants[idx];
}

void room::setCapacity(uint &n)
{
    mHabitants.reserve(n);
}

void room::setNumber(uint &n)
{
    mNumber = n;
}

void room::clear()
{
    mHabitants.resize(0);
}

bool room::isEmpty() const
{
    return static_cast<bool>(size());
}

bool room::availableForCheckin() const
{
    return static_cast<bool>(freeSlots());
}

void room::checkin(habitant h)
{
    mHabitants.push_back(h);
}

bool room::checkout(uint sid)
{
    auto it = findBySid(sid);
    if (it != mHabitants.end())
    {
        mHabitants.erase(it);
        return true;
    }
    return false;
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
