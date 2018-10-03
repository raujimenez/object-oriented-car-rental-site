#include <iostream>
#include "rental_site.h"

int main()
{
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

        std::cerr << "Before returning: " << std::endl;
        for (Vehicle vehicle : rental_place.vehicles())
            std::cerr << vehicle << std::endl;

        rental_place.return_vehicle(1);
        rental_place.return_vehicle(3);
        std::cerr << "After returning: " << std::endl;
        for (Vehicle vehicle : rental_place.vehicles())
            std::cerr << vehicle << std::endl;
        rental_place.return_vehicle(0);
        rental_place.return_vehicle(5);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}