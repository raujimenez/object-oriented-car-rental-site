#ifndef __VIEW_H
#define __VIEW_H
#include "rental_site.h"
class View
{
  public:
    View(Rental_Site rental_site);
    std::string main_menu();
    std::vector<std::string> list_of_vehicles();
    std::string help();

  private:
    Rental_Site _rental_site;
};

#endif