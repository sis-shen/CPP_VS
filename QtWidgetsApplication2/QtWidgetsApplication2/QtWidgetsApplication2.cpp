#include "stdafx.h"
#include "QtWidgetsApplication2.h"
#include "qlabel.h"

QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QLabel* label = new QLabel;

    label->setText("man! what can I say!");

    label->setParent(this);
}

QtWidgetsApplication2::~QtWidgetsApplication2()
{}
