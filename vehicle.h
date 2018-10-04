#ifndef __VEHICLE_H
#define __VEHICLE_H
#include <string>
#include "renter.h"
enum class Body_style
{
  SEDAN,
  HATCHBACK,
  MINIVAN,
  TRUCK,
  SUV,
  CROSSOVER
};

class Vehicle
{
public:
  Vehicle(int year, std::string make, std::string model, Body_style body_style);
  void rent_vehicle(Renter renter);
  Renter renter();
  void return_vehicle();
  std::string make();
  std::string model();
  int year();
  Body_style body_style();
  bool is_rented();
  std::string to_string() const;
  friend std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);

private:
  std::string _make;
  std::string _model;
  int _year;
  Body_style _body_style;
  bool _is_rented;
  Renter _renter;
};
#endif