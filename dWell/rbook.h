#ifndef RBOOK_H
#define RBOOK_H

#include "room.h"

#include <QVector>

class rbook
{
public:
    rbook();
private:
    QVector<room> mRooms;
};

#endif // RBOOK_H
