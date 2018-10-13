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
        const std::string get_year = "Enter the year of the vehicle: ";
        year = std::stoi(Dialogs::input(get_year));
        const std::string get_make = "Enter the make of the vehicle: ";
        make  = Dialogs::input(get_make);
        const std::string get_model = "Enter the model of the vehicle: ";
        model = Dialogs::input(get_model);
        while (valid_body_style)
        {
            const std::string get_body = "Pick a body style:\n\t(1)Sedan\t(2)Hatchback\n\t(3)Minivan\t(4)Truck\n\t(5)SUV\t\t(6)Crossover\n";
            body_choice = std::stoi(Dialogs::input(get_body));
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
                Gtk::MessageDialog *dialog = new Gtk::MessageDialog{"Try again, not valid."};
                break;
            }
        }
        Vehicle vehicle_to_add = Vehicle(year, make, model, body_style);
        _rental_site.add_vehicle(vehicle_to_add);
    }
    else if (command == 2)
    {
        std::ostringstream ost;
        ost << "LIST OF VEHICLES:" << std::endl << std::endl;
        for (Vehicle vehicle : _rental_site.vehicles())
            ost << vehicle << std::endl;
        Gtk::MessageDialog *msg_dialog = new Gtk::MessageDialog{ost.str()};
        msg_dialog->run();
    }
    else if (command == 3)
    {
        int vehicle_to_rent, i = 0;
        std::vector<int> returned_cars;
        std::string name, dl, phone;
        std::ostringstream ost;
        for (Vehicle vehicle : _rental_site.vehicles()) //determines index of available cars
        {
            if (!vehicle.is_rented())
                returned_cars.push_back(i);
            i++;
        }

        ost << "Available Vehicles: " << std::endl;
        for (int available : returned_cars)
            ost << "Vehicle [" << std::to_string(available+1) << "], ";
        ost << std::endl;
        ost << "Enter the vehicle: "; std::cin >> vehicle_to_rent; std::cin.ignore();
        ost << std::endl;
        for(std::string str : view.list_of_renters())
            ost << str;
        int renter_val;
        ost << "Enter the renter: ";
        renter_val = std::stoi(Dialogs::input(ost.str()));
        _rental_site.rent_vehicle(vehicle_to_rent, _rental_site.renters()[renter_val-1]);
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
        std::ostringstream ost;
        ost << "Vehicles currently being rented:\n";
        for (int available : rented_cars)
            ost << "Vehicle[" + std::to_string(available + 1) + "], ";
        ost << std::endl << std::endl << "Enter the number of the returned vehicle: ";
        vehicle_to_return = std::stoi(Dialogs::input(ost.str()));
        _rental_site.return_vehicle(vehicle_to_return);
    }
    else if(command == 5)
    {
        std::string name, dl, phone;            
        const std::string get_name =  "Enter renter's name: ";
        name = Dialogs::input(get_name);
        const std::string get_dl = "Enter renter's drivers license: ";
        dl = Dialogs::input(get_dl);
        const std::string get_phone = "Enter renter's phone number: ";
        phone = Dialogs::input(get_phone);
        _rental_site.add_renter(Renter(name,dl,phone));
    }
    else if(command == 6)
    {
        std::ostringstream ost;
        for(std::string str : view.list_of_renters())
            ost << str;
        Gtk::MessageDialog *renters_dialog = new Gtk::MessageDialog(ost.str());
        renters_dialog->run();
    }
    else if (command == 9)
    {
        Gtk::MessageDialog *help_dialog = new Gtk::MessageDialog(view.help());
        help_dialog->run();
    }
    else
    {
        Gtk::MessageDialog *error_dialog = new Gtk::MessageDialog("invalid. Try a valid input");
        error_dialog->run();
    }
}

void Controller::cli(int argc, char *argv[])
{
    View view{View(_rental_site)};
    int cmd = 1;
    do
    {
        cmd = std::stoi(Dialogs::input(view.main_menu()));
        execute_cmd(cmd);
    } while (cmd != 0);

}

Rental_Site Controller::rental_site() { return _rental_site; }