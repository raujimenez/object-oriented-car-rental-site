#ifndef __CONTROLLER_H
#define __CONTROLLER_H
#include "rental_site.h"

class Controller
{
  public:
    void execute_cmd(int command);
    Rental_Site rental_site();

  private:
    Rental_Site _rental_site;
};

#endif