#include "vehicle.h"
#include <exception>
#include <stdexcept>
#include <ctime>

class Vehicle_not_made_yet : public std::exception
{
  public:
    const char *what() const noexcept
    {
        return "year: Vehicle was created in future.\n Try again.";
    }
};

class Vehicle_not_invented : public std::exception
{
  public:
    const char *what() const noexcept
    {
        return "year: Vehicle was could not exist. 1885 was the first vehicle created by Benz.\nTry again.";
    }
};

Vehicle::Vehicle(int year, std::string make, std::string model, Body_style body_style) : _year{year}, _make{make}, _model{model}, _body_style{body_style}, _is_rented{false}
{
    time_t current_time{time(NULL)};
    struct tm *time{localtime(&current_time)};
    int current_year{time->tm_year + 1900 + 1}; //1 implies margin of error for next year models
    if (current_year < year)
        throw Vehicle_not_made_yet();
    if (year < 1885)
        throw Vehicle_not_invented();
}

//rents a vehicle to a customer
void Vehicle::rent_vehicle(Renter renter)
{
    _renter = renter;
    _is_rented = true;
}

//customer returns vehicle therefore vehicle is not being rented
void Vehicle::return_vehicle() { _is_rented = false; }

//getter functions
bool Vehicle::is_rented() { return _is_rented; }
std::string Vehicle::make() { return _make; }
std::string Vehicle::model() { return _model; }
int Vehicle::year() { return _year; }
Body_style Vehicle::body_style() { return _body_style; }
Renter Vehicle::renter() { return _renter; }
//streaming functions
std::string Vehicle::to_string() const
{
    std::string vehicle_info{std::to_string(_year) + " " + _make + " " + _model + " "};
    if (_body_style == Body_style::SEDAN)
        vehicle_info += "Sedan";
    else if (_body_style == Body_style::HATCHBACK)
        vehicle_info += "Hatchback";
    else if (_body_style == Body_style::MINIVAN)
        vehicle_info += "Minivan";
    else if (_body_style == Body_style::TRUCK)
        vehicle_info += "Truck";
    else if (_body_style == Body_style::SUV)
        vehicle_info += "SUV";
    else if (_body_style == Body_style::CROSSOVER)
        vehicle_info += "Crossover";
    if (_is_rented)
    {
        vehicle_info += "\n\tRenter: " + _renter.name() + "\n\t" + "Driver's License: " + _renter.dl() + "\n\t" + "Phone: " + _renter.phone();
    }
    else
    {
        vehicle_info += "\n\tNOT RENTED";
    }
    return vehicle_info;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle)
{
    os << vehicle.to_string();
    return os;
}