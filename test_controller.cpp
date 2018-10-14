#include "controller.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);
    Controller cont;
    try
    {
        cont.cli();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}