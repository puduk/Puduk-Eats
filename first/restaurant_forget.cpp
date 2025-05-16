#include "restaurant_forget.hpp"
#include <iostream>
#include <fstream>

void restaurant_forget(FirstData& f) {

    std::ifstream check_file("restaurant.txt" ,std::ios::in);
    if (!check_file.is_open()) {
        std::cout << "This service currently out of service"  << '\n';
        return;
    }

    std::cout << "Restaurant Name : " ;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, *f.restaurant_name);

    std::string check_line;
    std::string found_name;
    std::string current_id;

    bool found = false;

    while (std::getline(check_file, check_line)) {
        if(check_line.find("Restaurant Name : " ) != std::string::npos){
            found_name = check_line.substr(check_line.find(": ") + 2);
            if(found_name == *f.restaurant_name){
                current_id = check_line.substr(0 , check_line.find("."));
                found = true;
            }


        }
    }

    check_file.close();
    check_file.open("restaurant.txt" ,std::ios::in);

    if(!found){
        std::cout << "This Restaurant did not exits. " << '\n';
        return;
    }

    std::string final_line;
    std::string found_password;
    while (std::getline(check_file, final_line)) {
        if(final_line.find(current_id + ". Restaurant Password : " ) != std::string::npos){
            found_password = final_line.substr(final_line.find(": ") + 2);
        }
    }

    std::cout << "\n Your restaurant password: " << found_password << '\n';

}

