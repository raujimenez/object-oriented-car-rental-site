#include "rental_site.h"
#include <stdexcept>

void Rental_Site::add_vehicle(Vehicle vehicle) { _vehicles.push_back(vehicle); }
void Rental_Site::add_renter(Renter renter){ _renters.push_back(renter);}
//counting begins at 1 for customer ease of use
void Rental_Site::rent_vehicle(int vehicle, Renter renter)
{
    if (vehicle > _vehicles.size()) //ensures type safety
        throw std::runtime_error("Quantity Error: Attempted to rent vehicle " + std::to_string(vehicle) + ", but you only have " + std::to_string(_vehicles.size()) + " vehicles.");
    else if (vehicle < 1)
        throw std::runtime_error("Quantity Error: Attempted to access a vehicle at index " + std::to_string(vehicle) + " but vehicle counting begins at 1.");
    _vehicles[vehicle - 1].rent_vehicle(renter);
}

//counting begins at 1 for customer ease of use
void Rental_Site::return_vehicle(int vehicle)
{
    if (vehicle > _vehicles.size()) //ensures type safety
        throw std::runtime_error("Quantity Error: Attempted to return vehicle " + std::to_string(vehicle) + ", but you only have " + std::to_string(_vehicles.size()) + " vehicles.");
    else if (vehicle < 1)
        throw std::runtime_error("Quantity Error: Attempted to access a vehicle at index " + std::to_string(vehicle) + " but vehicle counting begins at 1.");
    _vehicles[vehicle - 1].return_vehicle();
}

std::vector<Vehicle> Rental_Site::vehicles() { return _vehicles; }
std::vector<Renter> Rental_Site::renters(){ return _renters; };
