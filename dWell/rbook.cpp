#include "rbook.h"
#include "config.h"

#include <QFile>
#include <QDataStream>

rbook::rbook()
{
    connect(this, &rbook::dataChanged, [this] { saveToFile(config::fileRooms);});
}

bool rbook::availableForCheckin() const
{
    return !availRooms().empty();
}

const room &rbook::operator[](uint &idx) const
{
    return mRooms[idx];
}

uint rbook::size() const
{
    return mRooms.size();
}

uint rbook::fullness() const
{
    uint count=0;
    for (const auto &room : mRooms)
        count += room.size();
    return count;
}

void rbook::touchFile(uint &dormCap, uint &roomCap)
{
    for (uint i=0; i < dormCap; i++)
    {
        room *r = new room;
        r->setCapacity(roomCap);
        uint n = i+1;
        r->setNumber(n);
        mRooms.push_back(*r);
    }
    saveToFile(config::fileRooms);
}

QStringList rbook::availRooms() const
{
    QStringList rooms;
    for (const auto &room : qAsConst(mRooms))
    {
        if (room.availableForCheckin())
            rooms << QString("%1").arg(room.number());
    }
    return rooms;
}

QStringList rbook::availRooms(uint &exludeRoomNumber) const
{
    QStringList rooms;
    for (const auto &room : qAsConst(mRooms))
    {
        if (room.number() == exludeRoomNumber)
            continue;
        if (room.availableForCheckin())
            rooms << QString("%1").arg(room.number());
    }
    return rooms;
}

void rbook::setCapacity(uint &cap)
{
    mRooms.reserve(cap);
}

rbook *rbook::getRbook()
{
    rbook *rb = new rbook;
    rb->loadFromFile(config::fileRooms);
    return rb;
}

void rbook::checkin(uint roomNumber, habitant *h)
{
    mRooms[roomNumber-1].checkin(*h);
    emit dataChanged();
}

void rbook::checkout(uint roomNumber, uint sid)
{
    if (mRooms[roomNumber-1].checkout(sid))
        emit dataChanged();
}

const habitant *rbook::getHabitantBySid(uint &sid) const
{
    for(const auto &it : qAsConst(mRooms))
    {
        for (uint i = 0; i < it.size(); i++)
            if (it[i].studentID() == sid)
                return &it[i];
    }
    return nullptr;
}

void rbook::save(QDataStream &ost) const
{
    ost << mRooms.size();
    for (const auto &r : mRooms)
    {
        ost << r;
        if (ost.status() == QDataStream::WriteFailed)
            throw std::runtime_error(tr("Write to the stream failed").toStdString());
    }
}

void rbook::load(QDataStream &ist)
{
    mRooms.clear();
    uint size;
    ist >> size;
    for(uint i=0; i < size; i++)
    {
        room r;
        ist >> r;
        if (ist.status() == QDataStream::ReadCorruptData)
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());

        mRooms.push_back(r);
    }
}

void rbook::saveToFile(const QString &filename) const
{
    QFile rbookfile(filename);
    rbookfile.open(QIODevice::WriteOnly);
    QDataStream ost(&rbookfile);
    save(ost);
    rbookfile.close();
}

void rbook::loadFromFile(const QString &filename)
{
    QFile rbookfile(filename);
    if (!rbookfile.open(QIODevice::ReadOnly))
        throw std::runtime_error((tr("open(): ") + rbookfile.errorString()).toStdString());

    QDataStream ist(&rbookfile);
    load(ist);
    rbookfile.close();
}

