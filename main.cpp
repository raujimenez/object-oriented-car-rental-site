#include <iostream>
#include "controller.h"

int main()
{
    Controller cont;
    int cmd;
    do
    {
        cont.execute_cmd(999999); // 999999 is a special value which is used to display main menu
        std::cin >> cmd;
        std::cout << std::endl;
        cont.execute_cmd(cmd);
    } while (cmd != 0);

    return 0;
}