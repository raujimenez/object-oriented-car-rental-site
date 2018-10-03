#include "view.h"
#include <sstream>
View::View(Rental_Site rental_site) : _rental_site{rental_site} {}

std::string View::main_menu()
{
    std::ostringstream ost;
    ost << "=======================================================" << std::endl
        << "        Raul's Rental Vehicle Management System        " << std::endl
        << "=======================================================" << std::endl
        << std::endl
        << "Vehicles" << std::endl
        << "-----------------" << std::endl
        << "(1) Add Vehicle" << std::endl
        << "(2) List All Vehicles" << std::endl
        << "(3) Rent Vehicle" << std::endl
        << "(4) Return Vehicle" << std::endl
        << std::endl
        << "Utility" << std::endl
        << "-----------------" << std::endl
        << "(9) Help" << std::endl
        << "(0) Exit" << std::endl
        << std::endl;
    return ost.str();
}

std::vector<std::string> View::list_of_vehicles()
{
    std::ostringstream ost;
    std::vector<std::string> list;
    if (_rental_site.vehicles().size() == 0)
    {
        list.push_back("Empty lot :(");
        return list;
    }
    for (int i = 0; i < _rental_site.vehicles().size(); i++)
    {
        ost << _rental_site.vehicles()[i];
        list.push_back(ost.str());
        ost.str("");
    }
    return list;
}

std::string View::help() { return ""; } //TODO figure out what to put here

Rental_Site View::rental_site() { return _rental_site; }