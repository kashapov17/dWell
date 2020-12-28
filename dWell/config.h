#ifndef CONFIG_H
#define CONFIG_H

#include <QtGlobal>
#include <QString>

namespace config
{
    const char applicationName[] = QT_TRANSLATE_NOOP("Config", "dWell");
    const char applicationVersion[] = "20201228";
    const QString fileUsers = "users.dwl";
    const QString fileRooms = "rooms.dwl";
    const QString dormConf = "dorm.dwl";
}

#endif // CONFIG_H
