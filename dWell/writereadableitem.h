#ifndef WRITEREADABLEITEM_H
#define WRITEREADABLEITEM_H

#include <QDataStream>

class writeReadableItem
{
public:
    writeReadableItem() {}

protected:
    virtual void write(QDataStream &ost) const = 0;
    virtual void read(QDataStream &ist) = 0;
};

#endif // WRITEREADABLEITEM_H
