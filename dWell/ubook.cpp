#include "ubook.h"
#include "config.h"
#include <QFile>

ubook::ubook()
{
    connect(this, &ubook::dataChanged, [this] { saveToFile(config::fileUsers);});
}

user::utype ubook::checkUser(const QString &name, const QString &passwd)
{
    for (const auto &it : mUsers)
        if (it.name() == name)
            if (it.passwd() == passwd)
                return it.type();

    return user::utype::UNKNOWN;
}

void ubook::insert(user &user)
{
    mUsers.push_back(user);
    emit dataChanged();
}

void ubook::save(QDataStream &ost) const
{
    // Цикл по всем заметкам
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
    // Удаляем все заметки
    mUsers.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
    {
        user u;
        // Читаем очередную заметку из потока
        ist >> u;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error(tr("Corrupt data were read from the stream").toStdString());
        }
        // Вставляем прочитанную заметку в конец вектора mNotes
        mUsers.push_back(u);
    }
}
