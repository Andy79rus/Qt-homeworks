#include <QCoreApplication>
#include <QtSql>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHostAddress my_private_address;
    my_private_address.setAddress("204.12.45.103");
    qDebug() << my_private_address.toString() << Qt::endl;

    QSqlDatabase my_db = QSqlDatabase::database("QPSQL");
    qDebug() << my_db.isValid();
    qDebug() << my_db.isDriverAvailable("QPSQL");
    qDebug() << my_db.isOpen();

    return a.exec();
}
