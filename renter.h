#ifndef __RENTER_H
#define __RENTER_H
#include <string>
class Renter
{
  public:
    Renter(std::string name, std::string dl, std::string phone);
    std::string to_string()const;

    std::string name ()const;
    std::string dl ()const;
    std::string phone ()const;

    friend std::ostream &operator<<(std::ostream &os, const Renter &renter);
  private:
    std::string _name;
    std::string _dl;
    std::string _phone;
};

#endif