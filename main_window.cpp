#include "main_window.h"

Main_window::Main_window(){
    //SET UP GUI
    set_default_size(400, 300);
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    //set up menu bar
    Gtk::MenuBar menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //File
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    //File: exit program
    Gtk::MenuItem *menuitem_exit = Gtk::manage(new Gtk::MenuItem("_Exit",true));
    menuitem_exit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_exit_click));
    filemenu->append(*menuitem_exit);

    //Vehicles
    Gtk::MenuItem *menuitem_vehicle = Gtk::manage(new Gtk::MenuItem("_Vehicle", true));
    menubar->append(*menuitem_vehicle);
    Gtk::Menu *vehiclemenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*vehiclemenu);
    //Vehicle: add vehicle
    Gtk::MenuItem *menuitem_addvehicle = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_addvehicle->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_vehicle_click));
    vehiclemenu->append(*menuitem_addvehicle);
    //Vehicle: rent vehicle
    Gtk::MenuItem *menuitem_rentvehicle = Gtk::manage(new Gtk::MenuItem("_Rent", true));
    menuitem_rentvehicle->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_rent_vehicle_click));
    vehiclemenu->append(*menuitem_rentvehicle);
    //Vehicle: return vehicle
    Gtk::MenuItem *menuitem_returnvehicle = Gtk::manage(new Gtk::MenuItem("_Return", true));
    menuitem_returnvehicle->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_return_vechicle_click));
    vehiclemenu->append(*menuitem_returnvehicle);
    //vehicle: List vehicles
    Gtk::MenuItem *menuitem_listvehicles = Gtk::manage(new Gtk::MenuItem("_List Vehicles", true));
    menuitem_listvehicles->signal_activate().connect(sigc::mem(*this, &Main_window::on_list_vehicles_click));
    vehiclemenu->append(*menuitem_listvehicles);

    //Renter
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_Renter",true));
    menubar->append(*menuitem_view);
    Gtk::Menu *rentermenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*rentermenu);
    //Renter: add renter
    Gtk::MenuItem *menuitem_addrenter = Gtk::manage(new Gtk::MenuItem("_Add", true));
    menuitem_addrenter->signal_activate().connect(sigc::mem(*this, &Main_window::on_add_renter_click)
    rentermenu->append(*menuitem_addrenter);
    //Renter: list renters
    Gtl::MenuItem *menuitem_listrenters = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listrenters->signal_activate().connect(sigc::mem(*this, &Main_window::on_list_renters_click));
    rentermenu->append(*menuitem_listrenters);

    //Help
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    menuitem_help->signal_activate().connect(sigc::mem(*this, &Main_window::on_help_click));
}