#include <iostream>
#include "controller.h"
#include "view.h"
void Controller::execute_cmd(int command)
{
    View view{View(_rental_site)};
    if (command == 0)
    {
        std::ostringstream ost;
        ost << "Exiting..." << std::endl;
        Gtk::MessageDialog *dialog = new Gtk::MessageDialog(ost.str());
        dialog->run();
        dialog->close();
        delete dialog;
    }
    else if (command == 1)
    {
        int year, body_choice, result;
        bool valid_body_style = true;
        std::string make, model;
        Body_style body_style;

        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create Vehicle");

        // Model Year
        Gtk::HBox b_year;
        Gtk::Label l_year{"Year:"};
        l_year.set_width_chars(15);
        b_year.pack_start(l_year, Gtk::PACK_SHRINK);

        Gtk::Entry e_year;
        e_year.set_max_length(50);
        b_year.pack_start(e_year, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_year, Gtk::PACK_SHRINK);

        // Make
        Gtk::HBox b_make;
        Gtk::Label l_make{"Make:"};
        l_make.set_width_chars(15);
        b_make.pack_start(l_make, Gtk::PACK_SHRINK);

        Gtk::Entry e_make;
        e_make.set_max_length(50);
        b_make.pack_start(e_make, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_make, Gtk::PACK_SHRINK);

        // Model
        Gtk::HBox b_model;
        Gtk::Label l_model{"Model:"};
        l_model.set_width_chars(15);
        b_model.pack_start(l_model, Gtk::PACK_SHRINK);

        Gtk::Entry e_model;
        e_model.set_max_length(50);
        b_model.pack_start(e_model, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_model, Gtk::PACK_SHRINK);

        //Gets Body style
        Gtk::ComboBoxText c_body_style;
        Gtk::HBox b_body_style;
        Gtk::Label l_body_style{"Body style:"};
        l_body_style.set_width_chars(15);
        b_body_style.pack_start(l_body_style, Gtk::PACK_SHRINK);
        c_body_style.set_size_request(160);
        c_body_style.append("Sedan");
        c_body_style.append("Hatchback");
        c_body_style.append("Minivan");
        c_body_style.append("Truck");
        c_body_style.append("Crossover");
        c_body_style.append("SUV");
        b_body_style.pack_start(c_body_style, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_body_style, Gtk::PACK_SHRINK);

        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        result = dialog->run();

        //conversion to bodystyle
        body_choice = c_body_style.get_active_row_number();
        switch (body_choice)
        {
        case (0):
            body_style = Body_style::SEDAN;
            break;
        case (1):
            body_style = Body_style::HATCHBACK;
            break;
        case (2):
            body_style = Body_style::MINIVAN;
            break;
        case (3):
            body_style = Body_style::TRUCK;
            break;
        case (4):
            body_style = Body_style::CROSSOVER;
            break;
        case (5):
            body_style = Body_style::SUV;
            break;
        }
        dialog->close();
        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
        make = e_make.get_text();
        model = e_model.get_text();
        try
        {
            year = std::stoi(e_year.get_text());
            if (result == 1)
                _rental_site.add_vehicle(Vehicle(year, make, model, body_style));
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog *errors = Gtk::manage(new Gtk::MessageDialog(e.what()));
            errors->run();
            errors->close();
        }
    }
    else if (command == 2)
    {
        std::ostringstream ost;
        int i = 0;
        ost << "LIST OF VEHICLES:" << std::endl
            << std::endl;
        for (Vehicle vehicle : _rental_site.vehicles())
            ost << std::to_string(i++) << ") " << vehicle << std::endl;
        Gtk::MessageDialog *msg_dialog = new Gtk::MessageDialog{ost.str()};
        msg_dialog->run();
        msg_dialog->close();
        delete msg_dialog;
    }
    else if (command == 3)
    {
        int vehicle_to_rent, i = 0, result;
        std::vector<int> returned_cars;
        std::string name, dl, phone;
        for (Vehicle vehicle : _rental_site.vehicles()) //determines index of available cars
        {
            if (!vehicle.is_rented())
                returned_cars.push_back(i);
            i++;
        }
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Rent Car"); //available cars
        Gtk::ComboBoxText c_rent_vehicle;
        Gtk::HBox b_rent_vehicle;
        Gtk::Label l_rent_vehicle{"Available:"};
        l_rent_vehicle.set_width_chars(15);
        b_rent_vehicle.pack_start(l_rent_vehicle, Gtk::PACK_SHRINK);
        c_rent_vehicle.set_size_request(160);
        for (int available : returned_cars)
            c_rent_vehicle.append(_rental_site.vehicles()[available].to_string());
        b_rent_vehicle.pack_start(c_rent_vehicle, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_rent_vehicle, Gtk::PACK_SHRINK);

        Gtk::ComboBoxText c_renter;
        Gtk::HBox b_renter;
        Gtk::Label l_renter{"Renter:"};
        l_renter.set_width_chars(15);
        b_renter.pack_start(l_renter, Gtk::PACK_SHRINK);
        c_renter.set_size_request(160);
        for (Renter rents : _rental_site.renters())
            c_renter.append(rents.name() + " " + rents.dl() + " " + rents.phone());
        b_renter.pack_start(c_renter, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_renter, Gtk::PACK_SHRINK);

        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        result = dialog->run();
        dialog->close();
        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();

        vehicle_to_rent = returned_cars[c_rent_vehicle.get_active_row_number()] + 1;
        int renter_val;
        renter_val = c_renter.get_active_row_number() + 1;

        try
        {
            if (result == 1)
                _rental_site.rent_vehicle(vehicle_to_rent, _rental_site.renters()[renter_val - 1]);
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog *err = new Gtk::MessageDialog(e.what());
            err->run();
            err->close();
            delete err;
        }
    }
    else if (command == 4)
    {
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Return Car");
        Gtk::ComboBoxText c_return_vehicle;
        Gtk::HBox b_return_vehicle;
        Gtk::Label l_return_vehicle{"Rented Cars:"};
        l_return_vehicle.set_width_chars(15);
        b_return_vehicle.pack_start(l_return_vehicle, Gtk::PACK_SHRINK);
        c_return_vehicle.set_size_request(160);

        int vehicle_to_return, i{0}, result;
        std::vector<int> rented_cars;
        for (Vehicle vehicle : _rental_site.vehicles()) //determines index of available cars
        {
            if (vehicle.is_rented())
                rented_cars.push_back(i);
            i++;
        }
        for (int available : rented_cars)
            c_return_vehicle.append(_rental_site.vehicles()[available].to_string());
        b_return_vehicle.pack_start(c_return_vehicle, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_return_vehicle, Gtk::PACK_SHRINK);
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        result = dialog->run();
        dialog->close();
        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
        vehicle_to_return = rented_cars[c_return_vehicle.get_active_row_number()] + 1;
        try
        {
            if (result == 1)
                _rental_site.return_vehicle(vehicle_to_return);
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog *err = new Gtk::MessageDialog(e.what());
            err->run();
            err->close();
            delete err;
        }
    }
    else if (command == 5)
    {
        std::string name, dl, phone;
        int result;
        Gtk::Dialog *dialog = new Gtk::Dialog();
        dialog->set_title("Create Renter");

        // Model Year
        Gtk::HBox b_year;
        Gtk::Label l_year{"Name:"};
        l_year.set_width_chars(15);
        b_year.pack_start(l_year, Gtk::PACK_SHRINK);

        Gtk::Entry e_year;
        e_year.set_max_length(50);
        b_year.pack_start(e_year, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_year, Gtk::PACK_SHRINK);

        // Make
        Gtk::HBox b_make;
        Gtk::Label l_make{"Driver License:"};
        l_make.set_width_chars(15);
        b_make.pack_start(l_make, Gtk::PACK_SHRINK);

        Gtk::Entry e_make;
        e_make.set_max_length(50);
        b_make.pack_start(e_make, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_make, Gtk::PACK_SHRINK);

        // Model
        Gtk::HBox b_model;
        Gtk::Label l_model{"Phone #:"};
        l_model.set_width_chars(15);
        b_model.pack_start(l_model, Gtk::PACK_SHRINK);

        Gtk::Entry e_model;
        e_model.set_max_length(50);
        b_model.pack_start(e_model, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_model, Gtk::PACK_SHRINK);

        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();

        result = dialog->run();
        dialog->close();
        while (Gtk::Main::events_pending())
            Gtk::Main::iteration();
        name = e_year.get_text();
        dl = e_make.get_text();
        phone = e_model.get_text();
        try
        {
            if (result == 1)
                _rental_site.add_renter(Renter(name, dl, phone));
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog *err = new Gtk::MessageDialog(e.what());
            err->run();
            err->close();
            delete err;
        }
    }
    else if (command == 6)
    {
        std::ostringstream ost;
        for (std::string str : view.list_of_renters())
            ost << str;
        Gtk::MessageDialog *renters_dialog = new Gtk::MessageDialog(ost.str());
        renters_dialog->run();
        renters_dialog->close();
        delete renters_dialog;
    }
    else if (command == 9)
    {
        Gtk::MessageDialog *help_dialog = new Gtk::MessageDialog(view.help(), true);
        help_dialog->run();
        help_dialog->close();
        delete help_dialog;
    }
    else
    {
        Gtk::MessageDialog *error_dialog = new Gtk::MessageDialog("invalid. Try a valid input");
        error_dialog->run();
        error_dialog->close();
        delete error_dialog;
    }
}

void Controller::cli()
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