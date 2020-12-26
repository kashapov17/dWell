#ifndef DOC_H
#define DOC_H

#include <QString>
#include "habitant.h"

class doc
{

public:
    doc();
    static void generate(const habitant *h);
};

#endif // DOC_H
