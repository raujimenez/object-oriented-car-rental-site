#include <iostream>
#include <stdexcept>
#include "view.h"

int main()
{
    //normative case
    try
    {
        Rental_Site rental_place;
        //used to automate testing
        std::vector<std::string> renter_info{
            "Jose Ramirez", "10014323", "123-321-4354",
            "Raul Jimenez", "12354452", "534-123-5231",
            "Maria Nieto", "1823813", "123-434-2523",
            "Jesus R Jimenez", "1233124", "123-231-3214"};
        for (int i = 0; i < renter_info.size() / 3; i++) //generate a generation of nissan altimas
            rental_place.add_vehicle(Vehicle(2010 + i, "Nissan", "Altima 2.5 S", Body_style::SEDAN));
        for (int i = 0; i < renter_info.size() / 3; i++)
            rental_place.rent_vehicle(i + 1, renter_info[(3 * i) + 0], renter_info[(3 * i) + 1], renter_info[(3 * i) + 2]);
        
        View view = View(rental_place);
        std::cerr << view.main_menu() << std::endl;
        std::vector<std::string> string_test = view.list_of_vehicles();
        for(std::string str: string_test)
            std::cerr << str << std::endl;
        std::cerr << view.help() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    //testing to see if it properly displays empty lot
    try
    {
        Rental_Site rental_site_2;
        View view = View(rental_site_2);
        std::vector<std::string> string_test_2 = view.list_of_vehicles();
        for(std::string str : string_test_2)
            std::cerr << str << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}