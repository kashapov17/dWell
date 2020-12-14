#include "user.h"

user::user()
{}

user::user(QString name, QByteArray pHash, utype type)
{
    name = this->name;
    passwdHash = pHash;
    type = this->type;
}

const QString user::getName() const
{
    return name;
}

const QByteArray user::getPasswd() const
{
    return passwdHash;
}

user::utype user::getType() const
{
    return type;
}

void user::setName(QString &name)
{
    name = this->name;
}

void user::setPasswd(QByteArray &passwdHash)
{
    passwdHash = this->passwdHash;
}

void user::setType(utype &type)
{
    type = this->type;
}
