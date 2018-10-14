#include <iostream>
#include "controller.h"

int main(int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);
    Controller cont;
    cont.cli();
    return 0;
}