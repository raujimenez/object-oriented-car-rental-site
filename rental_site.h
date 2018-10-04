#ifndef __RENTAL_SITE_H
#define __RENTAL_SITE_H
#include "vehicle.h"
#include <vector>
class Rental_Site
{
  public:
    void add_vehicle(Vehicle vehicle);
    void rent_vehicle(int vehicle, std::string renter_name, std::string renter_driver_license, std::string renter_phone);
    void return_vehicle(int vehicle);
    std::vector<Vehicle> vehicles();
    std::vector<Renter> renters();
  private:
    std::vector<Vehicle> _vehicles;
    std::vector<Renter> _renters;
};
#endif