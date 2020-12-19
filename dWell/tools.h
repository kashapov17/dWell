#ifndef TOOLS_H
#define TOOLS_H

#include <QString>

#include "user.h"

class tools
{
public:
    tools();
    static QString userTypeToStr(const user::utype &);
};

#endif // TOOLS_H
