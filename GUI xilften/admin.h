#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public user
{
public:
    Admin();
    int Admission(QString password);
};

#endif // ADMIN_H
