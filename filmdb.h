#ifndef FILMDB_H
#define FILMDB_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

#define PATHTODB "../../FilmsDB.db"


class FilmDB
{
private:

    QSqlDatabase database;
    bool databaseIsOpen;
    QSqlQuery querry;
    QVector<QString> rez;


public:
    FilmDB();
    QVector<QString> get_good_films_of_genre(int rating, QString genre);
    QVector<QString> get_films_of_genre_less_than(int time, QString genre);
    QVector<QString> get_films_less_than(int time);
    int count_genre(QString genre);
};

#endif // FILMDB_H
