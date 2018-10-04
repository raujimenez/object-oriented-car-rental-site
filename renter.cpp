#include "renter.h"

Renter::Renter(std::string name, std::string dl, std::string phone): _name{name}, _dl{dl}, _phone{phone} {}
std::string Renter::name(){ return _name; }
std::string Renter::dl(){ return _dl; }
std::string Renter::phone(){ return _phone; }