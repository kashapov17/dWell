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
    static void initSystem(QWidget *parent);
    static ubook *getUbook();
    static QDialog *getUserInterface(QWidget *parent, const user::utype &);
};

#endif // TOOLS_H
