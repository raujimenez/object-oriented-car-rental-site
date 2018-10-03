#include <iostream>
#include "controller.h"
#include "view.h"
void Controller::execute_cmd(int command)
{
    View view{View(_rental_site)};
    if (command == 0)
    {
        std::cout << "Exiting..." << std::endl;
        return;
    }
    else if (command == 1)
    {
        int year, body_choice;
        bool valid_body_style = true;
        std::string make, model;
        Body_style body_style;
        std::cout << "Enter the year of the vehicle: ";
        std::cin >> year;
        std::cin.ignore();
        std::cout << "Enter the make of the vehicle: ";
        getline(std::cin, make);
        std::cin.ignore();
        std::cout << "Enter the model of the vehicle: ";
        getline(std::cin, model);
        std::cin.ignore();
        while (valid_body_style)
        {
            std::cout << "Pick a body style:"
                      << "\n\t(1)Sedan\t(2)Hatchback\n\t(3)Minivan\t(4)Truck\n\t(5)SUV\t(6)Crossover\n";
            std::cin >> body_choice;
            std::cin.ignore();
            switch (body_choice)
            {
            case (1):
                body_style = Body_style::SEDAN;
                valid_body_style = false;
                break;
            case (2):
                body_style = Body_style::HATCHBACK;
                valid_body_style = false;
                break;
            case (3):
                body_style = Body_style::MINIVAN;
                valid_body_style = false;
                break;
            case (4):
                body_style = Body_style::TRUCK;
                valid_body_style = false;
                break;
            case (5):
                body_style = Body_style::SUV;
                valid_body_style = false;
                break;
            case (6):
                body_style = Body_style::CROSSOVER;
                valid_body_style = false;
                break;
            default:
                std::cout << "Try again, not valid." << std::endl;
                break;
            }
        }
        Vehicle vehicle_to_add = Vehicle(year, make, model, body_style);
        _rental_site.add_vehicle(vehicle_to_add);
    }
    else if (command == 2)
    {
        for (Vehicle vehicle : _rental_site.vehicles())
            std::cout << vehicle << std::endl;
    }
    else if (command == 3)
    {
        int vehicle_to_rent, i = 0;
        std::vector<int> returned_cars;
        std::string name, dl, phone;
        for (Vehicle vehicle : _rental_site.vehicles()) //determines index of available cars
        {
            if (!vehicle.is_rented())
                returned_cars.push_back(i);
            i++;
        }

        std::cout << "Available Vehicles: " << std::endl;
        for (int available : returned_cars)
            std::cout << "Vehicle [" << std::to_string(available) << "], ";
        std::cout << std::endl;
        std::cout << "Enter the vehicle slot number: ";
        std::cin >> vehicle_to_rent;
        std::cin.ignore();
        std::cout << "Enter renter's name: ";
        getline(std::cin, name);
        std::cin.ignore();
        std::cout << "Enter renter's drivers license: ";
        getline(std::cin, dl);
        std::cin.ignore();
        std::cout << "Enter renter's phone number: ";
        getline(std::cin, phone);
        std::cin.ignore();
        _rental_site.rent_vehicle(vehicle_to_rent, name, dl, phone);
    }
    else if (command == 4)
    {
        int vehicle_to_return, i{0};
        std::vector<int> rented_cars;
        for (Vehicle vehicle : _rental_site.vehicles()) //determines index of available cars
        {
            if (vehicle.is_rented())
                rented_cars.push_back(i);
            i++;
        }
        std::cout << "Vehicles currently being rented:" << std::endl;
        for (int available : rented_cars)
            std::cout << "Vehicle[" + std::to_string(available) + "], ";
        std::cout << std::endl;
        std::cout << "Enter the number of the returned vehicle: ";
        std::cin >> vehicle_to_return;
        std::cin.ignore();
        _rental_site.return_vehicle(vehicle_to_return);
    }
    else if (command == 9)
    {
        view.help();
    }
    else if (command == 999999)
    {
        std::cout << view.main_menu();
    }
    else
    {
        std::cout << "invalid. Try a valid input" << std::endl;
    }
}

Rental_Site Controller::rental_site() { return _rental_site; }