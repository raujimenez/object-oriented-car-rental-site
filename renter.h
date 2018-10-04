#ifndef __RENTER_H
#define __RENTER_H
#include <string>
class Renter
{
  public:
    Renter(std::string name, std::string dl, std::string phone);
    std::string name();
    std::string dl();
    std::string phone();

  private:
    std::string _name;
    std::string _dl;
    std::string _phone;
};

#endif