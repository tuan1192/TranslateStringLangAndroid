#include <QCoreApplication>

#include "parsexml.h"
#include <QDebug>

int main()
{
    ParseXml *p = new ParseXml;
    p->XMLTranslate();
    return 0;
}
