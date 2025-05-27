#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtCmakeTest.h"

class qtCmakeTest : public QMainWindow
{
    Q_OBJECT

public:
    qtCmakeTest(QWidget *parent = nullptr);
    ~qtCmakeTest();

private:
    Ui::qtCmakeTestClass ui;
};
