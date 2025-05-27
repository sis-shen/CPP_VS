#include "QWindow.h"

QWindow::QWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QWindow::~QWindow()
{}
