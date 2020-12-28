#ifndef RBOOK_H
#define RBOOK_H

#include <QVector>

#include "room.h"

class rbook : public QObject
{
    Q_OBJECT

public:
    rbook();

    void checkin(uint rn, habitant *);
    void checkout(uint rn, uint sid);
    const room &operator[](uint &idx) const;
    uint size() const;
    void setCapacity(uint &cap);
    static rbook *getRbook();
    const habitant *getHabitantBySid(uint &sid) const;
    QStringList availRooms() const;
    QStringList availRooms(uint &exludeRoomNumber) const;
    bool availableForCheckin() const;
    void touchFile(uint &dormCap, uint &roomCap); // for initial setup

private:
    QVector<room> mRooms;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private slots:
    void loadFromFile(const QString &filename);
    void saveToFile(const QString &filename) const;

signals:
    void dataChanged();
};

#endif // RBOOK_H
