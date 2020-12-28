#include "user.h"

user::user() {}

const QString user::name() const
{
    return mName;
}

const QString user::passwd() const
{
    return mPasswd;
}

user::utype user::type() const
{
    return mType;
}

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
