#include "dormitory.h"

dormitory::dormitory(QString &name, uint8_t &slotsn)
{
    dormName = name;
    slotsNum = slotsn;
    save
}

const QString dormitory::name()
{
    return dormName;
}

uint8_t dormitory::slotsNumber()
{
    return slotsNum;
}
