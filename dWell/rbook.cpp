#include "rbook.h"

#include <QFile>
#include <QDataStream>
#include "config.h"

rbook::rbook()
{
    connect(this, &rbook::dataChanged, [this] { saveToFile(config::fileRooms);});
}

void rbook::touchFile(uint &dormCap, uint roomCap)
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
    mRooms[roomNumber-1].checkout(sid);
    emit dataChanged();
}

const habitant *rbook::getHabitantBySid(uint sid)
{
    for(const auto &it : mRooms)
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
    // Цикл по всем комнатам
    for (const auto &r : mRooms)
    {
        // Выводим данные комнаты в поток
        ost << r;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ost.status() == QDataStream::WriteFailed)
        {
            throw std::runtime_error(tr("Write to the stream failed").toStdString());
        }
    }
}

void rbook::load(QDataStream &ist)
{
    // Очищаем контейнер
    mRooms.clear();
    // Пока в потоке есть данные
    uint size;
    ist >> size;
    for(uint i=0; i < size; i++)
    {
        room r;
        // Читаем очередную комнату из потока
        ist >> r;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());
        }
        // Вставляем прочитанного пользователя в конец вектора mUsers
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
    // Открываем файл только для чтения
    if (!rbookfile.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error((tr("open(): ") + rbookfile.errorString()).toStdString());
    }
    QDataStream ist(&rbookfile);
    load(ist);
    rbookfile.close();
}

