#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <gtkmm.h>
#include "controller.h"
class Main_window : public Gtk::Window
{
  public:
    Main_window();

  protected:
    void on_add_vehicle_click();
    void on_rent_vehicle_click();
    void on_return_vehicle_click();
    void on_list_vehicles_click();
    void on_add_renter_click();
    void on_list_renters_click();
    void on_help_click();
    void on_exit_click();
  private:
    void set_sticks();              // Update display, robot move
    Controller cont;
};
#endif