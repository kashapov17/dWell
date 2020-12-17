#include "ubook.h"
#include "config.h"
#include <QFile>

ubook::ubook()
{
    connect(this, &ubook::dataChanged, [this] { saveToFile(config::fileUsers);});
}

user::utype ubook::findUser(const QString &name, const QString &passwd)
{
    for (const auto &it : mUsers)
        if (it.name() == name)
            if (it.passwd() == passwd)
                return it.type();

    return user::utype::UNKNOWN;
}

//ubook::userError ubook::checkUser(user *u)
//{
//    if (u->name().isEmpty()) return WRONG_NAME;
//    if (u->passwd().isEmpty()) return WRONG_PASSWORD;
//    if(u->type() >= user::UNKNOWN && u->type() < 0) return WRONG_TYPE;
//    if (findUser(u->name(), u->passwd()) != user::UNKNOWN) return EXIST;
//    return OK;
//}

//const QString ubook::userErrorToString(ubook::userError e)
//{
//    switch (e)
//    {
//    case ubook::EXIST:
//        return "Данный пользователь уже существует";
//        break;
//    case ubook::WRONG_NAME:
//        return "Введено некорректное имя пользователя";
//        break;
//    case ubook::WRONG_PASSWORD:
//        return "Введён некорректный пароль";
//        break;
//    case ubook::WRONG_TYPE:
//        return "Введён некорректный тип пользователя";
//        break;
//    default:
//        return "ok";
//    }
//}

void ubook::insert(user &user)
{
    mUsers.push_back(user);
    emit dataChanged();
}

void ubook::erase(const int &idx)
{
    mUsers.erase(std::next(mUsers.begin(), idx));
    emit dataChanged();
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
            throw std::runtime_error(tr("Write to the stream failed").toStdString());
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
        throw std::runtime_error((tr("open(): ") + ubookfile.errorString()).toStdString());
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
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());
        }
        // Вставляем прочитанного пользователя в конец вектора mUsers
        mUsers.push_back(u);
    }
}
