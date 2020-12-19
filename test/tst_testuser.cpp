#include <QtTest>
#include <QString>
#include <QDataStream>
#include <QFile>

#include "../dWell/user.h"

Q_DECLARE_METATYPE(user);
Q_DECLARE_METATYPE(user::utype)

class testUser : public QObject
{
    Q_OBJECT
private slots:
    void getName();
    void getPassword();
    void getType();
    void setData();
    void writeAndReadFromFile();
};

void testUser::getName()
{
    QString n = "admin";
    user u(n, "P@ssw0rd", user::ADMIN);
    QVERIFY(u.name() == n);
}

void testUser::getPassword()
{
    QString p = "P@ssw0rd";
    user u("student", p, user::STUDENT);
    QVERIFY(u.passwd() == p);
}

void testUser::getType()
{
    user::utype t = user::ADMIN;
    user ua("admin", "P@ssw0rd", t);
    QVERIFY(ua.type() == t);
    t = user::STUDENT;
    user us("student", "P@ssw0rd", t);
    QVERIFY(us.type() == t);
    t = user::COMMANDANT;
    user uc("comm", "P@ssw0rd", t);
    QVERIFY(uc.type() == t);
}

void testUser::writeAndReadFromFile()
{
    QString n = "admin";
    QString p = "P@ssw0rd";
    user::utype t = user::ADMIN;
    QFile f("file");
    f.open(QIODevice::WriteOnly);
    QDataStream wstr(&f);
    user wu(n, p, t);
    wstr << wu;
    f.close();
    f.open(QIODevice::ReadOnly);
    QDataStream rstr(&f);
    user ru;
    rstr >> ru;
    f.close();
    f.remove();
    QVERIFY(ru.name() == n && ru.passwd() == p && ru.type() == t);
}

void testUser::setData()
{
    QString oldn = "admin";
    QString p = "P@ssw0rd";
    user::utype t = user::ADMIN;
    user u(oldn, p, t);
    QString newn = "anykey";
    QString newp = "pass";
    user::utype newt = user::STUDENT;
    u.setData(newn, newp, newt);
    QVERIFY(u.name() == newn and u.passwd() == newp and u.type() == newt);
}

QTEST_APPLESS_MAIN(testUser)
#include "tst_testuser.moc"
