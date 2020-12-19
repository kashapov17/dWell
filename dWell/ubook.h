#ifndef UBOOK_H
#define UBOOK_H

#include <QVector>
#include <QObject>

#include "user.h"

class ubook : public QObject
{
    Q_OBJECT
public:
    using SizeType = uint;
    ubook();

    user::utype findUser(const QString &name, const QString &passwd) const;
    user::utype findUserByName(const QString &name) const;

    bool insert(user &user);
    bool erase(const uint &idx);

    void loadFromFile(const QString &filename);
    /**
     * @brief Оператор [].
     * @param idx Индекс читаемого элемента.
     * @return Константная ссылка на пользователя.
     */
    const user &operator[](SizeType idx) const {return mUsers[idx];};
    /// Определяет размер коллекции (количество пользователей системы).
    SizeType size() const {return mUsers.size();};

signals:
    void dataChanged();

private:
    QVector<user> mUsers;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private slots:
    void saveToFile(const QString &filename) const;

};

#endif // UBOOK_H
