#ifndef PAY_H
#define PAY_H

#include <string>
#include <vector>


using namespace std;

class Pay{
    public:
        int donate(MYSQL *con, string username, int value);

    private:
        float value;
        
};


#endif