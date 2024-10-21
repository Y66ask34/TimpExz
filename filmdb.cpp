#include "filmdb.h"



FilmDB::FilmDB()
{
    database = QSqlDatabase::addDatabase("QSQLITE");

    database.setDatabaseName(PATHTODB);
    if (!database.open())
    {
        qDebug() << "Ошибка соединения с базой данных";

    }

    querry = QSqlQuery(database);
}

QVector<QString> FilmDB::get_good_films_of_genre(int rating, QString genre)
{
    querry.prepare("select filmName from Films Where genre = :genre and rating > :rating ;");
    querry.bindValue(":genre", genre);
    querry.bindValue(":rating", rating);
    querry.exec();

    querry.first();

    while (querry.next())
        rez.push_back(querry.value(0).toString());

    return rez;
}

QVector<QString> FilmDB::get_films_of_genre_less_than(int time, QString genre)
{
    querry.prepare("select filmName from Films Where genre = :genre and filmTime < :time;");
    querry.bindValue(":genre", genre);
    querry.bindValue(":time", time);
    querry.exec();

    querry.first();

    while (querry.next())
        rez.push_back(querry.value(0).toString());

    return rez;
}

QVector<QString> FilmDB::get_films_less_than(int time)
{
    querry.prepare("select filmName from Films Where filmTime < :time;");
    querry.bindValue(":time", time);
    querry.exec();

    querry.first();

    while (querry.next())
        rez.push_back(querry.value(0).toString());

    return rez;

}

int FilmDB::count_genre(QString genre)
{
    querry.prepare("select count(filmName) from Films Where genre = :genre;");
    querry.bindValue(":genre", genre);
    querry.exec();

    querry.first();

    return querry.value(0).toInt();
}
