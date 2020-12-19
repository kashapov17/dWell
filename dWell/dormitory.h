#ifndef DORMITORY_H
#define DORMITORY_H

#include <cstdint>
#include <QString>
#include <QDataStream>

class dormitory
{
public:
    dormitory();
    dormitory(QString &name, uint &roomCapacity, uint &dormCapacity);
    const QString name();
    uint roomCapacity();
    uint capacity();
    static dormitory *getDormCfg();

private:
    uint mRoomCapacity;
    uint mDormCapacity;
    QString mDormName;

    void load(QDataStream &ost);
    void save(QDataStream &ist);
    void loadFromFile(const QString &filename);
    void saveToFile(const QString &filename);
};

#endif // DORMITORY_H
