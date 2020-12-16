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
    const QString name() const;
    const QString passwd() const;
    utype type() const;
    void setName(QString &);
    void setPasswd(QString &);
    void setType(utype &);
    void setData(QString &, QString &, utype &);

private:
    QString m_name;
    QString m_passwd;
    utype m_type;
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
