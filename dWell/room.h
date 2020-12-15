#ifndef ROOM_H
#define ROOM_H

#include <QString>

#include "habitant.h"

class room
{

private:
    uint number;
    uint slotsNumber;
    uint freeslotsNumber;
    QVector<habitant> *mHabitants;

public:
    room();
};

#endif // ROOM_H
