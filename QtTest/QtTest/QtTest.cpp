#include "QtTest.h"
#include <QDebug>

QtTest::QtTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    qDebug() << "hello";
}

QtTest::~QtTest()
{}
