#include <iostream>
#include "main_window.h"
int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.raulrent");
    Main_window win;
    win.set_title("rental vehicle management system");
    return app->run(win);
}