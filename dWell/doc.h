#ifndef DOC_H
#define DOC_H

#include "habitant.h"

#include <QPrinter>

class doc
{

public:
    doc();
    static void generate(const habitant *h, QPrinter *printer);
};

#endif // DOC_H
