#include "ubook.h"
#include "config.h"

#include <QFile>

ubook::ubook()
{
    QObject::connect(this, &ubook::dataChanged, [this] { saveToFile(config::fileUsers);});
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
    // Цикл по всем пользователям
    for (const auto &u : mUsers)
    {
        // Выводим данные пользователя в поток
        ost << u;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ost.status() == QDataStream::WriteFailed)
        {
            throw std::runtime_error(QString("Write to the stream failed").toStdString());
        }
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
    // Открываем файл только для чтения
    if (!ubookfile.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error((QString("open(): ") + ubookfile.errorString()).toStdString());
    }
    QDataStream ist(&ubookfile);
    load(ist);
}

void ubook::load(QDataStream &ist)
{
    // Очищаем контейнер
    mUsers.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
    {
        user u;
        // Читаем очередного пользователя из потока
        ist >> u;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(QString("Corrupt data were read from the stream").toStdString());
        }
        else // Вставляем прочитанного пользователя в конец вектора mUsers
            mUsers.push_back(u);
    }
}
