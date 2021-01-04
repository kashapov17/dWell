/**
 * @file book.cpp
 * @brief Файл реализации класса book.
 * @author Кашапов Ярослав
 * @date 2021
 */

#include "book.h"
#include "config.h"
#include "user.h"
#include "room.h"

#include <QFile>
#include <QString>

template <typename entry>
void book<entry>::saveToFile(const QString &filename) const
{
    QFile bookfile(filename);
    bookfile.open(QIODevice::WriteOnly);
    QDataStream ost(&bookfile);
    write(ost);
    bookfile.close();
}

template <typename entry>
void book<entry>::loadFromFile(const QString &filename)
{
    QFile bookfile(filename);
    if (!bookfile.open(QIODevice::ReadOnly))
        throw std::runtime_error((QString("open(): ") +
                                  bookfile.errorString())
                                 .toStdString());
    QDataStream ist(&bookfile);
    read(ist);
    bookfile.close();
}

template <typename entry>
const entry &book<entry>::operator[](uint idx) const
{
    return mEntries[idx];
}

template <typename entry>
uint book<entry>::size() const
{
    return mEntries.size();
}

template <typename entry>
void book<entry>::write(QDataStream &ost) const
{
    ost << mEntries.size();
    for (const auto &e : mEntries)
    {
        ost << e;
        if (ost.status() == QDataStream::WriteFailed)
            throw std::runtime_error(QString("Write to the stream failed").toStdString());
    }
}

template <typename entry>
void book<entry>::read(QDataStream &ist)
{
    mEntries.clear();
    uint size;
    ist >> size;
    for(uint i=0; i < size; i++)
    {
        entry e;
        ist >> e;
        if (ist.status() == QDataStream::ReadCorruptData)
            throw std::runtime_error(QString("Corrupt data were read from the stream").toStdString());
        else
            mEntries.push_back(e);
    }
}

template class book<user>;
template class book<room>;
