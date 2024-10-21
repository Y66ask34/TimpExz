#include <QCoreApplication>
#include "filmdb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FilmDB db;

    qDebug() << "Количество по жанру ";
    qDebug() << db.count_genre("comedy");

    qDebug() <<  "По времени ";
    qDebug() << db.get_films_less_than(150);

    return a.exec();
}
