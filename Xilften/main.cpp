// g++ main.cpp -o output -I/usr/include/mysql/mysql -lmysqlclient -lncurses
/* **********************************************/
/* **************BIBS DECLARATION************** */
/* **********************************************/
#include <iostream>
#include "mysql/mysql.h" // /usr/includes/mariadb/mysql.h
#include "Movie.cpp"
#include "Admin.cpp"
#include "User.cpp"
#include "Pay.cpp"
#include <ncurses.h>
#include <cstring>


#define DB_SERVER "localhost"
#define DB_USER "root"
#define DB_PASS "123456"
#define DB_DATA "xilften"

using namespace std;

int main(int argc, char const *argv[])
{
   /* **********************************************/
   /* **********VARIABLES DECLARATION************ */
   /* **********************************************/

   MYSQL *con;	// the connection
   MYSQL_RES *res;	// the results
   MYSQL_ROW row;	// the results rows (array)
   Movie func; // variable for class Movie
   Admin adm; //  variable for class Admin
   User member;// variable for class user
   Pay pay;    // variable for class pay
   char status;
   int choice;
   string name, genre, id, clas, password, user, description, actors, director;
   bool programStatus = false;
   /* ******************************************/
   /* ***********DATABASE CONECTION*************/
   /* ******************************************/

   struct connection_details mysqlD; //call my struct
   mysqlD.server = DB_SERVER;  // where the mysql database is
   mysqlD.user = DB_USER; // user
   mysqlD.password = DB_PASS; // the password for the database
   mysqlD.database = DB_DATA;	// the databse
   con = mysql_connection_setup(mysqlD); // connect to the mysql database

   /* ************************************************/
   /* ***********PROGRAM LOOP STARTS HERE*************/
   /* ************************************************/
   cout << "HELLO, WELCOME TO XILFTEN MOVIE SERVICE" << endl;
   cout << "Wanna begin?(Y/N)" << endl;
   cin >> status;
   system("clear");
   if (status == 'Y' || status == 'y') programStatus = true;
   else return 0;

   while (programStatus == true){

      cout << "Log as admin or user? " << endl;
      cin  >> user;
      /* ************************************/
      /* ************************************/
      /* ************************************/
      /* ************************************/
      /* ***********ADMIN CONTROL*************/
      /* ************************************/
      /* ************************************/
      /* ************************************/
      /* ************************************/
      
      if(user.compare("admin") == 0){
         
         system("clear");
         cout << "insert admin Password" << endl;
         cin >> password;

         /* **********************************************/
         /* *************INSERT ADMIN PASS****************/
         /* **********************************************/

         while (adm.Admission(password) == -1){//while pass wrong 
            cout << "wrong, try again" << endl;
            cin >> password;
            system("clear");
         }

         if (adm.Admission(password) == 0){//if pass ok!!
            system("clear");
            cout << "Welcome Admin" << endl << endl;
            while (1){ //loop to stay in program

               /* **********************************************/
               /* **************ADMIN OPTIONS*******************/
               /* **********************************************/
               
               cout << "Wanna insert a movie? - 1" << endl << "Wanna Delete a movie? - 2" << endl << "Wanna see the catalog? - 3" << endl << "Wanna see the users - 4" << endl << "Wanna Exit? - 5" << endl;
               cin >> choice;

               if (choice == 1){
                  system("clear");
                  cout << "name " << endl;
                  cin.ignore();
                  getline (cin,name);
                  cout << "genre "<<endl;
                  getline (cin,genre);
                  cout << "description "<<endl;
                  getline (cin,description);
                  cout << "actors "<<endl;
                  getline (cin,actors);
                  cout << "director "<<endl;
                  getline (cin,director);
                  func.movieInsert(con, name, genre, description, actors, director);
               }
               if (choice == 2){
                  system("clear");
                  cout << "name " << endl;
                  cin.ignore();
                  getline (cin,name);
                  func.movieDelete(con, name);
               }
               if (choice == 3){
                  system("clear");
                  func.movieCatalog(con);
               }
               if (choice == 4){
                  system("clear");
                  member.showUsers(con);
               }
               if (choice == 5){
                  return 0;
               }
      
            }
         }
      }
      
      /* ************************************/
      /* ************************************/
      /* ************************************/
      /* ************************************/
      /* ***********USER CONTROL*************/
      /* ************************************/
      /* ************************************/
      /* ************************************/
      /* ************************************/

      else if(user.compare("user") == 0){
      int option, status, cnt = 3, value, totalDonated;
      char sure;
      string name, mail, age, pass, username, rate, resp, exit, fullname;
      system("clear");

      /* **********************************************/
      /* ***********LOG IN/SIGN IN OPTIONS*************/
      /* **********************************************/

      cout << "Log in - 1" << endl<< "Register - 2 "<< endl;
      cin >> option;
      system("clear");
      
      /* **********************************************/
      /* ***************REGISTRATION*******************/
      /* **********************************************/
      if(option == 2){
         system("clear");
         
         cout << "What is your username? " << endl;
         cin.ignore();
         getline (cin,username);

         cout << "Enter your email? " << endl;
         cin >> mail;

         cout << "Enter your full name? " << endl;
         cin.ignore();
         getline (cin,fullname);

         cout << "How old are you? " << endl;
         cin >> age;

         cout << "Choose a password? " << endl;
         cin >> pass;
         member.newUser(con, username, mail, age, pass, fullname);
         cout << endl;
      }

      /* **********************************************/
      /* ********************LOG IN/******************/
      /* **********************************************/

      if (option == 1){
         while(cnt > 0){
            cout << "username? " << endl;
            cin.ignore();
            getline (cin,username);         
            cout << "pass? " << endl;
            cin >> pass;
            status = member.Log(con,username,pass);
            
            /* **********************************************/
            /* ***************WRONG PASSWORD*****************/
            /* **********************************************/
            if(status == -1){
               system("clear");
               cout << "wrong pass, you have " << cnt << " chances left" << endl;
               cnt--;
            }

            /* **********************************************/
            /* ****************INVALID USER******************/
            /* **********************************************/

            if (status == -2){
               system("clear");
               cout << "Sorry, this user dows not exist =/ try another one" << endl;
            }
            
            /* **********************************************/
            /* ***************LOG IN OK**********************/
            /* **********************************************/

            if(status == 0){
               while(1){//Loop to stay in program
                  system("clear");
                  cout << "Welcome "  << username << endl << endl;
                  cout << "What do you wanna do?" << endl;

                  /* **********************************************/
                  /* ****************USER OPTIONS******************/
                  /* **********************************************/

                  cout << "See all catalog - 1" << endl << "Search a movie? - 2" << endl << "Delete your account - 3" << endl << "See Top 10 Movies? - 4" << endl << "Rate a movie - 5" << endl << "Donate - 6"<< endl << "EXit - 7" << endl;
                  cin >> option;

                  if(option == 1){
                     system("clear");
                     func.movieCatalog(con);
                     cout << "Return?(Y|N) " << endl;
                     cin >> exit;
                     while (1)
                     {
                        if(exit.compare("Y") == 0 || exit.compare("y") == 0){
                           break;
                        }
                        else{
                           return 0;
                        }
                     }
                  }
                  if(option == 2){
                     system("clear");
                     while(1){
                        cout << "What movie do you want to watch? "<< endl;
                        cin.ignore();
                        getline (cin,name);
                        int i = func.SearchMovieName(con, name, resp);
                        if(i==0)break;
                        cout << "Return?(Y|N) " << endl;
                        cin >> exit;
                        while (1)
                        {
                           if(exit.compare("Y") == 0 || exit.compare("y") == 0){
                              break;
                           }
                           else{
                              return 0;
                           }
                        }
                     }
                     system("clear");
                     cout << "You choose " << resp << endl;
                  }
                  if (option == 3){
                     system("clear");
                     cout << "Are you sure?(Y|N) " << endl;
                     cin >> sure;
                     if(sure == 'Y' || sure == 'y'){
                        member.deleteAccount(con, username);
                        cout << "Bye :/ " << endl;
                        return 0;
                     }
                     else{
                        continue;
                     }
                  }
                  if (option == 4){
                     system("clear");
                     func.TopTenMovies(con); //show the ten best rated movies 
                     cout << "Return?(Y|N) " << endl;
                     cin >> exit;
                     while (1)
                     {
                        if(exit.compare("Y") == 0 || exit.compare("y") == 0){
                           break;
                        }
                        else{
                           return 0;
                        }
                     }
                  }
                  if (option == 5){
                     system("clear");
                     cout << "Which movie do you wanna rate " << endl;
                     cin.ignore();
                     getline (cin,name);        
                     cout << "Rate?(0--10) " << endl;
                     cin >> rate;
                     string query = "SELECT * FROM eval where (name='"+username+"' AND movieName ='"+name+"') ;"; 
                     mysql_query(con, query.c_str());
                     res=mysql_store_result(con);
                     row=mysql_fetch_row(res);
                     if (row == NULL){
                        string query3 = "INSERT INTO eval (name, movieName, rate) VALUES ('"+username+"', '"+name+"', '"+rate+"');"; 
                        mysql_query(con, query3.c_str());
                        func.newMovieRate(con,username, name, rate);
                     }
                     else{
                        func.newMovieRate(con,username, name, rate);
                     }
                     
                  }
                  if(option == 6){
                     system("clear");
                     cout << "How much do you want to donate? " << endl;
                     cin >> value;
                     totalDonated = pay.donate(con, username, value);
                     cout << "Congrats, you have already contributed with " << totalDonated  << " xilftens"<< endl;
                     cout << "Return?(Y|N) " << endl;
                     cin >> exit;
                     while (1)
                     {
                        if(exit.compare("Y") == 0 || exit.compare("y") == 0){
                           break;
                        }
                        else{
                           return 0;
                        }
                     }
                  }
                  if(option == 7){
                     return 0;
                  }
               }

            }
         }
      }         
   }
   }
   // clean up the database result
   mysql_free_result(res);
   // close database connection
   mysql_close(con);
   return 0;
}