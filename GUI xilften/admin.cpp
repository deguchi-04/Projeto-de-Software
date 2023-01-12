#include "admin.h"
#include "QString"

Admin::Admin()
{

}

int Admin::Admission(QString password) {
    QString pass = "admin"; // this is the actual password
    if(password == pass){
        return 0;
    }
    else{
        return -1;
    }
}



