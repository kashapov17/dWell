#ifndef DORMITORY_H
#define DORMITORY_H

#include <cstdint>
#include <QString>
#include <QObject>
#include <QDataStream>

class dormitory
{    
    Q_OBJECT
public:
    dormitory();
    dormitory(QString &, uint8_t &);
    const QString name();
    uint8_t slotsNumber();
    void load(QDataStream &);
    void save(QDataStream &);
    void loadFromFile(QString &filename);

private:
    uint8_t slotsNum;
    QString dormName;
    void saveToFile(QString &filename);
};

#endif // DORMITORY_H
