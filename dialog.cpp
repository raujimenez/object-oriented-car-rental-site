#include "dialog.h"

std::string Dialogs::input(std::string msg, std::string title, std::string default_text, std::string cancel_text)
{
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);

    Gtk::Entry *entry = new Gtk::Entry{};
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();

    dialog->get_vbox()->pack_start(*entry);
    int result = dialog->run();
    std::string text = entry->get_text();
    dialog->close();

    while (Gtk::Main::events_pending())
        Gtk::Main::iteration();

    delete entry;
    delete label;
    delete dialog;
    if (result == 1)
        return text;
    else
        return cancel_text;
}
