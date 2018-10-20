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
    menuitem_exit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_exit);

    //Edit
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);
    //Edit: add vehicle
    Gtk::MenuItem *menuitem_addvehicle = Gtk::manage(new Gtk::MenuItem("_Add Vehicle", true));
    menuitem_addvehicle->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_vehicle_click));
    editmenu->append(*menuitem_addvehicle);
    //Edit: rent vehicle
    Gtk::MenuItem *menuitem_rentvehicle = Gtk::manage(new Gtk::MenuItem("_Rent Vehicle", true));
    menuitem_rentvehicle->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_rent_vehicle_click));
    editmenu->append(*menuitem_rentvehicle);
    //Edit: return vehicle
    Gtk::MenuItem *menuitem_returnvehicle = Gtk::manage(new Gtk::MenuItem("_Return Vehicle", true));
    menuitem_returnvehicle->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_return_vechicle_click));
    editmenu->append(*menuitem_returnvehicle);
    //Edit: add renter
    Gtk::MenuItem *menuitem_addrenter = Gtk::manage(new Gtk::MenuItem("_Add Renter", true));
    menuitem_addrenter->signal_activate().connect(sigc::mem(*this, &Main_window::on_add_renter_click)

    //View
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View",true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
    //View: List vehicles

    //View: list renters


    //Help


}