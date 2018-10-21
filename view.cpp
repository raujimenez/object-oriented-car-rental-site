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
    ost << "<span font_family='monospace'><big><u>This program is to manage a vehicle rental place:</u></big><span fgcolor='#11aa33'>" << std::endl
        << "Adding Vehicles:    Vehicles->New(in the menu bar), hit ok when done " << std::endl
        << "Renting Vehicles:   Vehicles->Rent(in menu bar), hit ok when done" << std::endl
        << "Returning Vehicles: Vehicles->Return(in menu bar), hit ok when done" << std::endl
        << "List All Vehicles:  Vehicles->List(in menu bar), hit ok when done</span><span fgcolor='#0000ff'>" << std::endl
        << "Adding Renters:     Renter->Add(in menu bar), hit ok when done" << std::endl
        << "List All Renters:   Renter->List(in menu bar), hit ok when done</span><span fgcolor='#ff0000'>" << std::endl
        << "Exit Program:       File->Exit(in Menu bar)</span>" << std::endl
        << "<big><b>IMPORTANT: if you click cancel with an empty databse the program will <span fgcolor='#ff0000'>exit</span>.</b></big></span>" << std::endl;
    return ost.str();
} //TODO figure out what to put here

Rental_Site View::rental_site() { return _rental_site; }