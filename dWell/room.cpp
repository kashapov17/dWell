#include "room.h"
#include "dormitory.h"
#include "config.h"

room::room()
{
    dormitory *dorm = new dormitory;
    dorm->loadFromFile(config::dormConf);
    mHabitants.resize(dorm->roomSlotsNumber());
}

void room::checkin(habitant h)
{
    mHabitants.push_back(h);
}

void room::checkout(uint &idx)
{
    mHabitants.erase(std::next(mHabitants.begin(), idx));
}
