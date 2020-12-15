#include <QFile>

#include "dormitory.h"
#include "config.h"

dormitory::dormitory(QString &name, uint8_t &slotsn)
{
    dormName = name;
    slotsNum = slotsn;
    saveToFile(config::dormConf);
}

const QString dormitory::name()
{
    return dormName;
}

uint8_t dormitory::slotsNumber()
{
    return slotsNum;
}

void dormitory::save(QDataStream &ost)
{
    ost << dormName << slotsNum;
    // Если возникла ошибка, запускаем исключительную ситуацию
    if (ost.status() == QDataStream::WriteFailed)
    {
        throw std::runtime_error(QObject::tr("Write to the stream failed").toStdString());
    }
}

void dormitory::saveToFile(const QString &filename)
{
    QFile dormConfFile(filename);
    dormConfFile.open(QIODevice::WriteOnly);
    QDataStream ost(&dormConfFile);
    save(ost);
}

void dormitory::loadFromFile(const QString &filename)
{
    QFile dormConfFile(filename);
    // Открываем файл только для чтения
    if (!dormConfFile.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error((QObject::tr("open(): ") + dormConfFile.errorString()).toStdString());
    }
    QDataStream ist(&dormConfFile);
    load(ist);
}

void dormitory::load(QDataStream &ist)
{

    while (!ist.atEnd())
    {
        ist >> dormName >> slotsNum;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(QObject::tr("Corrupt data were read from the stream").toStdString());
        }
    }
}
