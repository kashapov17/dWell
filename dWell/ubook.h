#ifndef UBOOK_H
#define UBOOK_H

#include <QVector>
#include <QObject>

#include "user.h"

class ubook : public QObject
{
    Q_OBJECT

public:
    ubook();

    user::utype findUser(const QString &name, const QString &passwd) const;
    user::utype findUserByName(const QString &name) const;

    bool insert(user &user);
    bool erase(const uint &idx);

    const user &operator[](uint idx) const;
    uint size() const;
    static ubook *getUbook();

signals:
    void dataChanged();

private:
    QVector<user> mUsers;
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);

private slots:
    void saveToFile(const QString &filename) const;
    void loadFromFile(const QString &filename);

};

#endif // UBOOK_H
