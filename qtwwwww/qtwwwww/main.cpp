#include "stdafx.h"
#include "qtwwwww.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtwwwww w;
    w.show();
    return a.exec();
}
