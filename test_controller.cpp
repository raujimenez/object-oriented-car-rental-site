#include "controller.h"
#include <iostream>

int main()
{
    Controller cont;
    int cmd;
    try
    {
        cmd = 5;
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
        cont.execute_cmd(6);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        cmd = 1;
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        cmd = 2;
        cont.execute_cmd(cmd);        
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        cmd = 3;
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() <<std::endl;
    }    
    try
    {
        cmd = 4;
        cont.execute_cmd(cmd);
        cont.execute_cmd(cmd);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() <<std::endl;
    }
    try
    {
        cmd = 9;
        cont.execute_cmd(cmd);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() <<std::endl;
    }    
    return 0;
}