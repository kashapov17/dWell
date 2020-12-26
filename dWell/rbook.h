#ifndef RBOOK_H
#define RBOOK_H

#include <QVector>

#include "room.h"

class rbook : public QObject
{
    Q_OBJECT

public:
    rbook();

    using SizeType = uint;
    void checkin(uint rn, habitant *);
    void checkout(uint rn, uint sid);
    const room &operator[](SizeType idx) const {return mRooms[idx];}

    /// Определяет размер коллекции (количество комнат системы).
    SizeType size() const {return mRooms.size();}
    void setCapacity(uint &cap);

    static rbook *getRbook();
    const habitant *getHabitantBySid(uint sid);

    void touchFile(uint &dormCap, uint roomCap); // for initial setup

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
