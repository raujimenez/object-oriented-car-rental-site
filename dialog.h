#ifndef __DIALOG_H
#define __DIALOG_H
#include <string>
#include <gtkmm.h>
class Dialogs
{
  public:
    static std::string input(std::string msg, std::string title = "Input", std::string default_text = "", std::string cancel_text = "CANCEL");
};

#endif