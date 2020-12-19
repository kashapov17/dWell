#ifndef TOOLS_H
#define TOOLS_H

#include <QString>
#include <QDialog>

#include "ubook.h"

class tools
{
public:
    tools();
    static QString userTypeToStr(const user::utype &);
    static void initSystem(QWidget *);
    static QDialog *getUserInterface(QWidget *, const user::utype &);
};

#endif // TOOLS_H
