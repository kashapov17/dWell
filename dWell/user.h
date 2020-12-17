#ifndef USER_H
#define USER_H

#include <QString>
#include <QDataStream>

class user
{

public:
    enum utype {ADMIN, COMMANDANT, STUDENT, UNKNOWN};
    user();
    user(QString, QString, utype);
    const QString name() const {return mName;};
    const QString passwd() const {return mPasswd;};
    utype type() const {return mType;};
    void setName(QString &);
    void setPasswd(QString &);
    void setType(utype &);
    void setData(QString &, QString &, utype &);

private:
    QString mName;
    QString mPasswd;
    utype mType;
};

// Запись пользователя в поток
inline QDataStream &operator<< (QDataStream &ost, const user &user)
{
    ost << user.name() << user.passwd() << user.type();
    return ost;
}

// Считывание пользователя из потока
inline QDataStream &operator>> (QDataStream &ist, user &user)
{
    QString name;
    QString password;
    user::utype type;
    ist >> name >> password >> type;
    user.setData(name, password, type);
    return ist;
}

#endif // USER_H
