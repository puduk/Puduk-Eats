#include "quit.hpp"
#include <iostream>
#include <fstream>

void quit(RestaurantData& r) {


    std::ofstream rate_file("restaurant_rate.txt" , std::ios::app);
    if(!rate_file.is_open()){
        std::cout << "Currently can not rate." << '\n';
        return;
    }
    std::ifstream amount_file("restaurant_rate.txt" , std::ios::in);
    if(!amount_file.is_open()){
        std::cout << "Currently can not rate." << '\n';
        return;
    }

    std::string amount_line;
    while(std::getline(amount_file, amount_line)){
        if(amount_line.find("Restaurant : ") != std::string::npos){
            (*r.total_rate) ++;
        }
    }


    std::cout << "-------------------------------------" << '\n';
    std::cout << "Thank you for using this application!" << '\n';
    std::cout << "Rate it! Before Quit (1 - 10)" << '\n';
    std::cout << "-------------------------------------" << '\n';
    std::cin >> *r.restaurant_rate;
    while(*r.restaurant_rate < 1 || *r.restaurant_rate > 10 || std::cin.fail()){
        std::cout << "Please enter a number between 1 and 10: ";
        std::cin >> *r.restaurant_rate;
    }

    rate_file << *r.total_rate << ". " << "Restaurant : " << *r.restaurant_name << " - Rate : " << *r.restaurant_rate << '\n';

    std::cout << "Goodbye from : " << *r.restaurant_name << '\n';
}

