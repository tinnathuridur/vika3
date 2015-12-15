#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db;

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("ComputerHistory_db.sqlite");
        db. open();
        if (!db.open())
           {
              qDebug() << "Error: connection with database fail";
           }
           else
           {
              qDebug() << "Database: connection ok";
           }

    /*QSqlQuery query;
    query.exec("CREATE TABLE Computers("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                   "name VARCHAR NOT NULL,"
                   "type INTEGER NOT NULL,"
                   "yearBuilt INTEGER,"
                   "wasBuilt BOOL)");

    query.exec("CREATE TABLE Scientists("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                   "name VARCHAR NOT NULL,"
                   "sex INTEGER NOT NULL,"
                   "yearBorn INTEGER NOT NULL,"
                   "yearDied INTEGER)");

    query.exec("CREATE TABLE ScientistComputerConnections("
                   "scientistId INTEGER,"
                   "computerId INTEGER,"
                   "foreign key (scientistId) references Scientists(id),"
                   "foreign key (computerId) references Computers(id),"
                   "primary key(scientistId, computerId)");*/



    return a.exec();
}
