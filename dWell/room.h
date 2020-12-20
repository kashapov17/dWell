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

    uint number() const {return mNumber;}
    uint capacity() const {return mHabitants.capacity();}
    uint size() const {return mHabitants.size();}
    uint freeSlots() const {return uint(capacity() - size());}
    /**
     * @brief Оператор [].
     * @param idx Индекс читаемого элемента.
     * @return Константная ссылка на проживающего.
     */
    const habitant &operator[](SizeType idx) const {return mHabitants[idx];}

    void setCapacity(uint &n) {mHabitants.reserve(n);}
    void setNumber(uint &n) {mNumber = n;};
    void clear() {mHabitants.resize(0);}
    bool isEmpty() const {return static_cast<bool>(size());};
    bool availableForCheckin() const {return static_cast<bool>(freeSlots());}
};

// Запись данных комнаты в поток
inline QDataStream &operator<< (QDataStream &ost, const room &r)
{
    ost << r.number() << r.capacity() << r.size();
    for(uint i=0; i < r.size(); i++)
        ost << r[i];
    return ost;
}

// Считывание данных комнаты из потока
inline QDataStream &operator>> (QDataStream &ist, room &r)
{
    uint number, cap, size;
    ist >> number >> cap >> size;
    r.setNumber(number);
    r.setCapacity(cap);
    if (size)
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
