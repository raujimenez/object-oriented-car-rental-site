#include <iostream>
#include <exception>
#include <stdexcept>
#include "vehicle.h"

int main()
{
    //normative case
    std::string test_tostring;
    try
    {
        Vehicle mycar_1{Vehicle(2010, "Nissan", "Altima 2.5 S", Body_style::SEDAN)};
        mycar_1.rent_vehicle(Renter("Jose Ramirez", "1012030320", "123-456-7890"));
        mycar_1.return_vehicle();
        mycar_1.rent_vehicle(Renter("Maria Nieto", "21908301283", "978-654-3210"));
        std::cerr << "testing output of operator overloading: " << mycar_1 << std::endl;
        mycar_1.return_vehicle();
        std::cerr << "testing output of operator overloading: " << mycar_1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //if year > current_year
    try
    {
        Vehicle mycar_2{Vehicle(100000, "Nissan", "Altima 2.5 S", Body_style::SEDAN)};
        test_tostring = mycar_2.to_string();
        mycar_2.return_vehicle();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //if car is not correct body_style example a car intended to be a sedan
    try
    {
        Vehicle mycar_3{Vehicle(2019, "Nissan", "Altima 2.5 S", Body_style::TRUCK)};
        test_tostring = mycar_3.to_string();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
