#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>

using namespace std;

class Admin{
    public: 
        int Admission(string password);
    private:
        string name;
        string password;
};

#endif