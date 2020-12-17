#ifndef CONFIG_H
#define CONFIG_H

#include <QtGlobal>
#include <QString>

namespace config
{
    const char applicationName[] = QT_TRANSLATE_NOOP("Config", "dWell");
    const char applicationVersion[] = "20201216";
    const QString fileUsers = "users.bin";
    const QString fileRooms = "rooms.bin";
    const QString dormConf = "dormcfg.bin";
}

#endif // CONFIG_H
