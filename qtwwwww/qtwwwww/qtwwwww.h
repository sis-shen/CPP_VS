#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtwwwww.h"

class qtwwwww : public QMainWindow
{
    Q_OBJECT

public:
    qtwwwww(QWidget *parent = nullptr);
    ~qtwwwww();

private:
    Ui::qtwwwwwClass ui;
};
