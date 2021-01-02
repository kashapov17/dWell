#ifndef BOOKENTRY_H
#define BOOKENTRY_H

#include "writereadableitem.h"

#include <QDataStream>

class bookEntry : public writeReadableItem
{
public:
    bookEntry() {}
    friend QDataStream &operator<< (QDataStream &ost, const bookEntry &e);
    friend QDataStream &operator>> (QDataStream &ist, bookEntry &e);
};

inline QDataStream &operator<< (QDataStream &ost, const bookEntry &e)
{
    e.write(ost);
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, bookEntry &e)
{
    e.read(ist);
    return ist;
}

#endif // BOOKENTRY_H
