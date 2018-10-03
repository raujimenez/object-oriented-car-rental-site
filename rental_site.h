#ifndef __RENTAL_SITE_H
#define __RENTAL_SITE_H
#include "vehicle.h"
#include <vector>
class Rental_site
{
  public:
    void add_vehicle(Vehicle vehicle);
    void rent_vehicle(int vehicle, std::string renter_name, std::string renter_driver_license, std::string renter_phone);
    void return_vehiclle(int vehicle);
    std::vector<Vehicle> vehicles();

  private:
    std::vector<Vehicle> _vehicles;
};
#endif