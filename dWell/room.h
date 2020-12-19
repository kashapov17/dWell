#ifndef ROOM_H
#define ROOM_H

#include <QString>

#include "habitant.h"

class room
{

private:
    uint mNumber;
    QVector<habitant> mHabitants;

public:
    using SizeType = uint;
    room();

    void checkin(habitant h);
    void checkout(uint &idx);

    uint number() const {return mNumber;};
    uint capacity() const {return mHabitants.capacity();};
    uint size() const {return mHabitants.size();}
    uint freeSlots() const {return uint(capacity() - size());};
    /**
     * @brief Оператор [].
     * @param idx Индекс читаемого элемента.
     * @return Константная ссылка на проживающего.
     */
    const habitant &operator[](SizeType idx) const {return mHabitants[idx];};
    void setNumber(uint &n) {mNumber = n;};
    void setCapacity(uint &n) {mHabitants.resize(n);};
};

// Запись данных комнаты в поток
inline QDataStream &operator<< (QDataStream &ost, const room &r)
{
    ost << r.number();
    ost << r.size();
    for(uint i=0; i < r.size(); i++)
    {
        ost << r[i];
    }
    return ost;
}

// Считывание данных комнаты из потока
inline QDataStream &operator>> (QDataStream &ist, room &r)
{
    uint number, size;
    ist >> number >> size;
    for (uint i=0; i < size; i++) {
        habitant h;
        ist >> h;
        r.checkin(h);
    }
    r.setNumber(number);
    return ist;
}

#endif // ROOM_H
