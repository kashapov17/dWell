#ifndef UBOOK_H
#define UBOOK_H

#include <QVector>
#include <QObject>
#include <QFile>

#include "user.h"

class ubook : public QObject
{
    Q_OBJECT
public:
    using SizeType = uint;
    ubook();

    user::utype checkUser(const QString &name, const QString &passwd);
    void insert(user &user);
    void erase(int idx);
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
    void loadFromFile(const QString &filename);
    /**
     * @brief Оператор [].
     * @param idx Индекс читаемого элемента.
     * @return Константная ссылка на пользователя.
     */
    const user &operator[](SizeType idx) const {return mUsers[idx];};
    /// Определяет размер коллекции (количество пользователей системы).
    SizeType size() const {return mUsers.size();};

private:
    QVector<user> mUsers;

private slots:
    void saveToFile(const QString &filename) const;

signals:
    void dataChanged();
};

#endif // UBOOK_H
