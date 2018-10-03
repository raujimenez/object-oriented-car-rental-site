#include "controller.h"

int main()
{
    Controller cont;
    int cmd;
    try
    {
        cmd = 0;
        cont.execute_cmd(cmd);
    } 
    catch (std::exception& e)
    {
        
    }
    try
    {
        cmd = 0; 
    } 
    catch (std::exception& e)
    {

    }
    try
    {

    } 
    catch (std::exception& e)
    {

    }
    try
    {

    } 
    catch (std::exception& e)
    {

    }    

    return 0;
}