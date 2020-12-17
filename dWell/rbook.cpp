#include "rbook.h"

#include <QFile>
#include <QDataStream>

rbook::rbook()
{

}

void rbook::save(QDataStream &ost) const
{
    // Цикл по всем пользователям
    for (const auto &r : mRooms)
    {
        // Выводим данные пользователя в поток
        ost << r;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ost.status() == QDataStream::WriteFailed)
        {
            throw std::runtime_error(tr("Write to the stream failed").toStdString());
        }
    }
}

void rbook::saveToFile(const QString &filename) const
{
    QFile rbookfile(filename);
    rbookfile.open(QIODevice::WriteOnly);
    QDataStream ost(&rbookfile);
    save(ost);
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
}

void rbook::load(QDataStream &ist)
{
    // Очищаем контейнер
    mRooms.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
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
