#ifndef USER_H
#define USER_H

#include "bookentry.h"

#include <QString>

class user : public bookentry
{
public:
    enum utype {ADMIN, STUDENT, COMMANDANT};
    user();
    user(QString, QByteArray, utype);
    const QString getName() const;
    const QByteArray getPasswd() const;
    utype getType() const;
    void setName(QString &);
    void setPasswd(QByteArray &);
    void setType(utype &);

private:
    QString name;
    QByteArray passwdHash;
    utype type;
};

#endif // USER_H
