#ifndef ROOM_H
#define ROOM_H

#include <QString>

#include "habitant.h"

class room
{

private:
    uint number;
    uint slotsNumber;
    uint freeSlots;
    QVector<habitant> *mHabitants;

public:
    room();
    void checkin(habitant *h);
    void checkout(habitant *h);
};

#endif // ROOM_H
