#include "view.h"
#include <sstream>
#include <iomanip>
View::View(Rental_Site rental_site) : _rental_site{rental_site} {}

std::string View::main_menu()
{
    std::ostringstream ost;
    ost << "<span font_family='monospace'>=======================================================" << std::endl
        << "  <big>Raul's Rental Vehicle Management System<sup>TM</sup></big>" << std::endl
        << "=======================================================" << std::endl
        << std::endl
        << "<u><b>Vehicles</b></u>                              <u><b>Renters</b></u>          " << std::endl
        << "<span fgcolor='#11aa33'>(1) Add Vehicle </span>                   <span fgcolor='#0000ff'>(5) Add Renter</span>      " << std::endl
        << "<span fgcolor='#11aa33'>(2) List All Vehicles</span>              <span fgcolor='#0000ff'>(6) List Renters</span>    " << std::endl
        << "<span fgcolor='#11aa33'>(3) Rent Vehicle</span>                                       " << std::endl
        << "<span fgcolor='#11aa33'>(4) Return Vehicle</span>                                     " << std::endl
        << std::endl
        << "<u><b>Utility</b></u>" << std::endl
        << "(9) Help" << std::endl
        << "<span fgcolor='#ff0000'>(0) Exit </span></span>" << std::endl
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

std::vector<std::string> View::list_of_renters()
{
    std::ostringstream ost;
    std::vector<std::string> list;
    ost <<std::fixed<< " " << std::setw(18) << "Name" << std::setw(18) << "License #" << std::setw(18) << "Phone #" << std::endl

        << std::endl;
    list.push_back(ost.str());
    ost.str("");
    for (int i = 0; i < _rental_site.renters().size(); i++)
    {
        ost << std::to_string(i + 1) << ") " << _rental_site.renters()[i] << std::endl;
        list.push_back(ost.str());
        ost.str("");
    }
    return list;
}

std::string View::help()
{
    std::ostringstream ost;
    ost << "This program is 4 function vehicle rental place:" << std::endl
        << "\t1)To add vehicles input 1 in the keyboard and then hit enter" << std::endl
        << "\t2)To list all vehicles input 2 in they keyboard and then hit enter" << std::endl
        << "\t3)To rent Vehicles out to a customer input 3 in the keyboard and then hit enter" << std::endl
        << "\t4)To check a vehicle back in to the lot input 4 in the keybaord and then hit enter" << std::endl
        << "\t5)To Add a renter to the database input 5 and hit enter" << std::endl
        << "\t6)To See all of the renter's in database input 6 and hit enter" << std::endl
        << "\t0)The program will run until you are prompted to input another command, in this case you can input 0 and then hit enter to stop program" << std::endl
        << "IMPORTANT: You can input a command after each menu is displayed" << std::endl;
    return ost.str();
} //TODO figure out what to put here

Rental_Site View::rental_site() { return _rental_site; }