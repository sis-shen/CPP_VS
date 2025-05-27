#include "qtCmakeTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtCmakeTest w;
    w.show();
    return a.exec();
}
