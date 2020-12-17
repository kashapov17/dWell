#include "room.h"
#include "dormitory.h"
#include "config.h"

room::room()
{
    ;
}

void room::checkin(habitant h)
{
    mHabitants.push_back(h);
}

void room::checkout(uint &idx)
{
    mHabitants.erase(std::next(mHabitants.begin(), idx));
}
