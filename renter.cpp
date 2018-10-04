#include "renter.h"
#include <iomanip>
#include "iostream"
Renter::Renter(): Renter("Joe Doe", "10010100", "111-111-1111") {}
Renter::Renter(std::string name, std::string dl, std::string phone) : _name{name}, _dl{dl}, _phone{phone} {}

std::string Renter::name() const { return _name; }
std::string Renter::dl() const { return _dl; }
std::string Renter::phone() const{ return _phone; }

std::ostream &operator<<(std::ostream &os, const Renter &renter)
{
    os  << std::setw(18) <<renter.name() <<std::setw(18) <<  renter.dl() <<std::setw(18)<< renter.phone();
    return os;
}
