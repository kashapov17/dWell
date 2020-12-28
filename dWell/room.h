#ifndef ROOM_H
#define ROOM_H

#include <QString>

#include "habitant.h"

class room
{


public:
    room();
    void checkin(habitant h);
    bool checkout(uint sid);
    uint number() const;
    uint capacity() const;
    uint size() const;
    uint freeSlots() const;
    const habitant &operator[](uint idx) const;
    void setCapacity(uint &n);
    void setNumber(uint &n);
    void clear();
    bool isEmpty() const;
    bool availableForCheckin() const;
    QVector<habitant>::iterator findBySid(uint sid);

private:
    uint mNumber;
    QVector<habitant> mHabitants;
};

inline QDataStream &operator<< (QDataStream &ost, const room &r)
{
    ost << r.number() << r.capacity() << r.size();
    for(uint i=0; i < r.size(); i++)
        ost << r[i];
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, room &r)
{
    uint number, cap, size;
    ist >> number >> cap >> size;
    r.setNumber(number);
    r.setCapacity(cap);
    if (size != 0)
        for (uint i=0; i < size; i++)
        {
            habitant h;
            ist >> h;
            r.checkin(h);
        }
    else
        r.clear();
    return ist;
}

#endif // ROOM_H
