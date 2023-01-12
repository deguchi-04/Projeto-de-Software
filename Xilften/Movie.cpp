#include <string>
#include "Movie.h"
#include <math.h>

using namespace std;

void Movie::movieInsert(MYSQL *con, string name, string genre, string descriptions, string actors, string director){
    string query = "INSERT INTO movie (name, genre, classification, description, actors, director ) VALUES ('"+name+"', '"+genre+"', '0', '"+descriptions+"', '"+actors+"', '"+director+"');"; 
    mysql_query(con, query.c_str());
}

void Movie::movieCatalog(MYSQL *con){
    MYSQL_RES *res; 
    MYSQL_ROW row;	// the results rows (array)
// get the results from executing commands
    res = mysql_perform_query(con, "select * from movie;");

    //std::cout << ("Database Output:\n") << std::endl;

    while ((row = mysql_fetch_row(res)) != NULL){
        // the below row[] parametes may change depending on the size of the table and your objective
        std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | "  << endl << endl; 
    }
}
void Movie::movieDelete(MYSQL * con, string name){
    string query3 = "DELETE FROM eval WHERE movieName='"+name+"';"; 
    mysql_query(con, query3.c_str());
    string query = "DELETE FROM movie WHERE name='"+name+"';"; 
    mysql_query(con, query.c_str());
    string query2 = "ALTER TABLE movie AUTO_INCREMENT = 1;"; 
    mysql_query(con, query2.c_str());
    
}

int Movie::getMovieId(MYSQL * con, string name){
    int i;
    MYSQL_ROW row;
    MYSQL_RES *res;
    string query = "SELECT id FROM movie WHERE name='"+name+"';"; 
    mysql_query(con, query.c_str());
    res=mysql_store_result(con);
    row=mysql_fetch_row(res);
    i = atoi(row[0]);
    return i;
}
//consertar
int Movie::SearchMovieName(MYSQL * con, string name, string &resp){
    MYSQL_ROW row;
    MYSQL_RES *res;
    int i; 
    string query = "SELECT name FROM movie where name='"+name+"';"; 
    i = mysql_query(con, query.c_str());
    res=mysql_store_result(con);
    row=mysql_fetch_row(res);
    if (row == NULL){
        system("clear");
        cout << "Sorry, we did not found this one =/ try another one" << endl;
        return -1;
    }
    else{
        resp = row[0];
        return 0;
    }
    
}

float Movie::getMovieRate(MYSQL * con, string name){
    int i;
    MYSQL_ROW row;
    MYSQL_RES *res;
    string query = "SELECT classification FROM movie WHERE name='"+name+"';"; 
    mysql_query(con, query.c_str());
    res=mysql_store_result(con);
    row=mysql_fetch_row(res);
    i = atoi(row[0]);
    return i;
}

void Movie::TopTenMovies(MYSQL * con){
    MYSQL_RES *res; 
    MYSQL_ROW row;	// the results rows (array)
     // get the results from executing commands
    res = mysql_perform_query(con, "SELECT name, classification  FROM movie ORDER BY classification DESC LIMIT 10;");

    cout << ("TOP TEN MOVIES:\n") << endl;

    while ((row = mysql_fetch_row(res)) != NULL){
        // the below row[] parametes may change depending on the size of the table and your objective
        cout << row[0] << " | " << row[1] << " | "   << endl << endl;  
    }
}

void Movie::newMovieRate(MYSQL * con, string username, string movieName, string rate){
    float newGeralRate;
    MYSQL_ROW row, row2, row0;
    MYSQL_RES *res, *res2, *res0;
    string aux;
    float previousUserRate, totalUsers, actualSumRate, newRate;

    string query0 = "SELECT rate FROM eval where name='"+username+"' AND movieName = '"+movieName+"';"; 
    mysql_query(con, query0.c_str());
    res0=mysql_store_result(con);
    row0=mysql_fetch_row(res0);
    previousUserRate = atoi(row0[0]);

    string query6 = "UPDATE eval SET rate = '"+rate+"' WHERE name='"+name+"' AND movieName='"+movieName+"';"; 
    mysql_query(con, query6.c_str());

    string query = "Select count(*) from eval where  movieName = '"+movieName+"';"; 
    mysql_query(con, query.c_str());
    res=mysql_store_result(con);
    row=mysql_fetch_row(res);
    totalUsers = atoi(row[0]);

    string query2 = "SELECT SUM(rate) FROM eval where movieName= '"+movieName+"';";
    mysql_query(con, query2.c_str());
    res2=mysql_store_result(con);
    row2=mysql_fetch_row(res2);
    actualSumRate = atoi(row2[0]);

    newRate = stoi(rate);
    
    newGeralRate = ((actualSumRate) - previousUserRate + newRate)/totalUsers;
    aux = to_string(newGeralRate);

    string query3 = "UPDATE movie SET classification= '"+aux+"' WHERE name='"+movieName+"';"; 
    mysql_query(con, query3.c_str());
    
}