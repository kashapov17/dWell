#ifndef DORMITORY_H
#define DORMITORY_H

#include <cstdint>
#include <QString>
#include <QDataStream>

class dormitory
{

public:
    dormitory();
    dormitory(QString &, uint8_t &);
    const QString name();
    uint8_t roomSlotsNumber();
    void loadFromFile(const QString &filename);

private:
    uint8_t slotsNum;
    QString dormName;
    QString rbookFilePath;
    QString ubookFilePath;

    void load(QDataStream &);
    void save(QDataStream &);
    void saveToFile(const QString &filename);
};

#endif // DORMITORY_H
