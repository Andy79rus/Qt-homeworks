#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/icon.ico"));
    a.setWindowIcon(QIcon(":/icon.ico"));
    w.setWindowTitle("QStopwatch");
    w.show();
    return a.exec();
}
