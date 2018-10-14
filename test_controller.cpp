#include "controller.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);
    Controller cont;
    cont.execute_cmd(0);
    return 0;
}