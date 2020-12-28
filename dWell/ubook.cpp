#include "ubook.h"
#include "config.h"

#include <QFile>

ubook::ubook()
{
    QObject::connect(this, &ubook::dataChanged, [this] { saveToFile(config::fileUsers);});
}

const user &ubook::operator[](uint idx) const
{
    return mUsers[idx];
}

uint ubook::size() const
{
    return mUsers.size();
}

user::utype ubook::findUser(const QString &name, const QString &passwd) const
{
    for (const auto &it : mUsers)
        if (it.name() == name.trimmed() and it.passwd() == passwd.trimmed())
            return it.type();

    return user::utype::UNKNOWN;
}

user::utype ubook::findUserByName(const QString &name) const
{
     for (const auto &it : mUsers)
         if(it.name() == name.trimmed())
             return it.type();

     return user::utype::UNKNOWN;
}

bool ubook::insert(user &user)
{
    if (findUser(user.name(), user.passwd()) == user::UNKNOWN)
    {
        mUsers.push_back(user);
        emit dataChanged();
        return true;
    }
    return false;
}

ubook *ubook::getUbook()
{
    ubook *u = new ubook;
    u->loadFromFile(config::fileUsers);
    return u;
}

bool ubook::erase(const uint &idx)
{
    if (idx < size())
    {
        mUsers.erase(std::next(mUsers.begin(), idx));
        emit dataChanged();
        return true;
    }
    return false;
}

void ubook::save(QDataStream &ost) const
{
    for (const auto &u : mUsers)
    {
        ost << u;
        if (ost.status() == QDataStream::WriteFailed)
            throw std::runtime_error(QString("Write to the stream failed").toStdString());
    }
}

void ubook::saveToFile(const QString &filename) const
{
    QFile ubookfile(filename);
    ubookfile.open(QIODevice::WriteOnly);
    QDataStream ost(&ubookfile);
    save(ost);
}

void ubook::loadFromFile(const QString &filename)
{
    QFile ubookfile(filename);

    if (!ubookfile.open(QIODevice::ReadOnly))
        throw std::runtime_error((QString("open(): ") + ubookfile.errorString()).toStdString());

    QDataStream ist(&ubookfile);
    load(ist);
}

void ubook::load(QDataStream &ist)
{
    mUsers.clear();
    while (!ist.atEnd())
    {
        user u;
        ist >> u;
        if (ist.status() == QDataStream::ReadCorruptData)
            throw std::runtime_error(QString("Corrupt data were read from the stream").toStdString());
        else
            mUsers.push_back(u);
    }
}
