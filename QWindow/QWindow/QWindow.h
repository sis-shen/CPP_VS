#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QWindow.h"

class QWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWindow(QWidget *parent = nullptr);
    ~QWindow();

private:
    Ui::QWindowClass ui;
};
