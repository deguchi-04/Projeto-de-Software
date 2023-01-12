#include "Admin.h"
#include <cstring>
#include <ncurses.h>
using namespace std;

int Admin::Admission(string password) { 
    string pass = "admin"; // this is the actual password 
    if(password == pass){
        return 0;
    }
    else{
        return -1;
    }
}


