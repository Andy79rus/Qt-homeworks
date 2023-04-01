#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/cpp.png"));
    w.setWindowTitle("QtWidgets2");
    w.setFixedSize(470, 230);
    w.show();
    return a.exec();
}
