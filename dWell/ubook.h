#ifndef UBOOK_H
#define UBOOK_H

#include <QVector>
#include <QObject>
#include <QFile>

#include "user.h"

class ubook : QObject
{
    Q_OBJECT
public:
    ubook();

    user::utype checkUser(const QString &name, const QString &passwd);

    void insert(user &user);
    void erase(int idx);
    void save(QDataStream &ost);
    void load(QDataStream &ist);
    void loadFromFile(const QString &filename);

private:
    QVector<user> mUsers;

private slots:
    void saveToFile(const QString &filename);

signals:
    void dataChanged();
};

#endif // UBOOK_H
