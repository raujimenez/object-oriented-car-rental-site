#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <gtkmm.h>
#include "nim.h"
class Main_window : public Gtk::Window
{
  public:
    Main_window();
    virtual ~Main_window();

  protected:
    void on_add_vehicle_click();
    void on_rent_vehicle_click();
    void on_return_vechicle_click();
    void on_add_renter_click();
    void on_list_vehicles_click();
    void on_list_renters_click();
    void on_help_click();
    void on_exit_click();
  private:
    void set_sticks();              // Update display, robot move
    Nim *nim;
    Gtk::Label *sticks;            // Display of sticks on game board
    Gtk::Label *msg;               // Status message display
    Gtk::ToolButton *button1;      // Button to select 1 stick
    Gtk::Image *button1_on_image;  // Image when active
    Gtk::Image *button1_off_image; // Image when inactive
    Gtk::ToolButton *button2;      // Button to select 2 sticks
    Gtk::Image *button2_on_image;
    Gtk::Image *button2_off_image;
    Gtk::ToolButton *button3; // Button to select 3 sticks
    Gtk::Image *button3_on_image;
    Gtk::Image *button3_off_image;
    Gtk::ToggleToolButton *computer_player; // Button to enable robot
};
#endif