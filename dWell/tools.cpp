#include "tools.h"

tools::tools()
{

}

QString tools::userTypeToStr(const user::utype &t)
{
    switch (t)
    {
        case user::utype::ADMIN:
            return QString("админ");
        case user::utype::COMMANDANT:
            return QString("комендант");
        case user::utype::STUDENT:
            return QString("студент");
        default:
            return QString();
    }
}
