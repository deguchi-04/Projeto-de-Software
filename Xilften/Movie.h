#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include "database.h"

using namespace std;


class Movie{
    public:
        void movieInsert(MYSQL *con, string name, string genre, string descriptions, string actors, string director);
        void movieCatalog(MYSQL *con);
        void movieDelete(MYSQL *con, string name);
        int getMovieId(MYSQL * con, string name);
        int SearchMovieName(MYSQL * con, string name, string &resp);
        float getMovieRate(MYSQL * con, string name);
        void TopTenMovies(MYSQL * con);
        void newMovieRate(MYSQL * con, string name, string movieName, string rate);
    private:
        char film_id;
        double rate;
        string name;
        string descriptions;
        string actors;
        string director;   
};

#endif