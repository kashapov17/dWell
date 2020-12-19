#ifndef RBOOK_H
#define RBOOK_H

#include <QVector>

#include "room.h"

class rbook : public QObject
{
    Q_OBJECT
public:
    using SizeType = uint;
    rbook();

    void insert(room &r);
    void erase(const int &idx);

    const room &operator[](SizeType idx) const {return mRooms[idx];};
    /// Определяет размер коллекции (количество комнат системы).
    SizeType size() const {return mRooms.size();};

    static void touchFile();

    void loadFromFile(const QString &filename);
private:
    QVector<room> mRooms;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private slots:
    void saveToFile(const QString &filename) const;

signals:
    void dataChanged();
};

#endif // RBOOK_H
