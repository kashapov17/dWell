#include "user.h"

user::user()
{}

user::user(QString name, QString passwd, utype type)
{
    m_name = name;;
    m_passwd = passwd;
    m_type = type;
}

const QString user::name() const
{
    return m_name;
}

const QString user::passwd() const
{
    return m_passwd;
}

user::utype user::type() const
{
    return m_type;
}

void user::setName(QString &name)
{
    m_name = name;
}

void user::setPasswd(QString &passwd)
{
    m_passwd = passwd;
}

void user::setType(utype &type)
{
    m_type = type;
}

void user::setData(QString &name, QString &passwd, utype &type)
{
    setName(name);
    setPasswd(passwd);
    setType(type);
}
