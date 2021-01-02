#ifndef UBOOK_H
#define UBOOK_H

#include "book.h"
#include "user.h"

#include <QVector>

class ubook : public book<user>
{
public:
    ubook() {}
    user::utype findUser(const QString &name, const QString &passwd) const;
    user::utype findUserByName(const QString &name) const;

    bool insert(user &user);
    bool remove(const uint &idx);
    static ubook *getUbook();
    void touchFile(); // for initial setup
};

#endif // UBOOK_H
