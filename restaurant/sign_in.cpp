#include "sign_in.hpp"
#include <iostream>
#include <fstream>

void sign_in(RestaurantData& r) {

  std::cout << "------------------" << '\n';
  std::cout << "Restaurant Name : " ;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, *r.restaurant_name);
  std::cout << "Restaurant Password : ";
  std::cin >> *r.restaurant_password;

  std::ifstream check_file("restaurant.txt" , std::ios::in | std::ios::binary);
  if (!check_file.is_open()) {
    std::cout << "Unable to sign in.";
    return;
  }

  std::string check_line;
  std::string found_name;
  std::string found_password;
  bool can_enter = false;

  while(std::getline(check_file, check_line)) {
    if(check_line.find("Restaurant Name : ") != std::string::npos) {
      found_name = check_line.substr(check_line.find(": ") + 2);
    }else if (check_line.find("Restaurant Password : ") != std::string::npos) {
      found_password = check_line.substr(check_line.find(": ") + 2);
      if(found_name == *r.restaurant_name && found_password == *r.restaurant_password) {
        can_enter = true;
      }
    }
  }


  if(!can_enter){
    std::cout << "Wrong Restaurant Name or Password.";
    return;
  }

  std::cout << "Welcome." << found_name << ".";
  // restaurant_menu;

}