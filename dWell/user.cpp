#include "user.h"

user::user() {}

user::user(QString name, QString passwd, utype type)
{
    setData(name, passwd, type);
}

bool user::setData(QString &name, QString &passwd, utype &type)
{
    name = name.trimmed();
    passwd = passwd.trimmed();
    if (!name.isEmpty() and !passwd.isEmpty() and
            (type == user::ADMIN or type == user::COMMANDANT or type == user::STUDENT))
    {
        mName = name;
        mPasswd = passwd;
        mType = type;
        return true;
    }
    return false;
}
