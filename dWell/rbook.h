#ifndef RBOOK_H
#define RBOOK_H

#include <QVector>

#include "room.h"
#include "book.h"

class rbook : public book<room>
{
public:
    rbook() {}

    void checkin(uint rn, habitant *);
    void checkout(uint rn, uint sid);

    uint fullness() const;
    void setCapacity(uint &cap);
    static rbook *getRbook();
    const habitant *getHabitantBySid(uint &sid) const;
    QStringList availRooms() const;
    QStringList availRooms(uint &exludeRoomNumber) const;
    bool availableForCheckin() const;
    void touchFile(uint &dormCap, uint &roomCap); // for initial setup
};

#endif // RBOOK_H
