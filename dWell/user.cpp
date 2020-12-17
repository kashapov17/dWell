#include "user.h"

user::user()
{}

user::user(QString name, QString passwd, utype type)
{
    mName = name;;
    mPasswd = passwd;
    mType = type;
}

void user::setName(QString &name)
{
    mName = name;
}

void user::setPasswd(QString &passwd)
{
    mPasswd = passwd;
}

void user::setType(utype &type)
{
    mType = type;
}

void user::setData(QString &name, QString &passwd, utype &type)
{
    setName(name);
    setPasswd(passwd);
    setType(type);
}
