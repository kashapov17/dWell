#ifndef USER_H
#define USER_H

#include "bookentry.h"

#include <QString>

class user : public bookEntry
{
public:
    enum utype {ADMIN, COMMANDANT, STUDENT, UNKNOWN};
    user() {}
    user(QString name, QString pass, utype type);
    const QString name() const;
    const QString passwd() const;
    utype type() const;
    bool setData(QString &, QString &, utype &);

private:
    QString mName;
    QString mPasswd;
    utype mType;

protected:
    void write(QDataStream &ost) const override;
    void read(QDataStream &ist) override;
};

#endif // USER_H
