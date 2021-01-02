#ifndef BOOK_H
#define BOOK_H

#include "writereadableitem.h"

#include <QVector>
#include <QObject>

template <typename entry>
class book : writeReadableItem
{
public:
    book() {}
    void loadFromFile(const QString &filename);
    void saveToFile(const QString &filename) const;
    const entry &operator[](uint idx) const;
    uint size() const;

private:
    void write(QDataStream &ost) const override;
    void read(QDataStream &ist) override;

protected:
    QVector<entry> mEntries;
};

#endif // BOOK_H
