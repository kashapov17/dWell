#ifndef ROOM_H
#define ROOM_H

#include "bookentry.h"
#include "habitant.h"

#include <QString>

class room : public bookEntry
{
public:
    room() {}
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

protected:
    void write(QDataStream &ost) const override;
    void read(QDataStream &ist) override;
};

#endif // ROOM_H
