#include "restaurant_condition.hpp"
#include <iostream>
#include <fstream>
#include "customer_menu.hpp"

void restaurant_condition(CustomerData& c){

  std::ifstream file( *c.choosen_restaurant +"_statu.txt"  , std::ios::in);
  if (!file.is_open()) {
    std::cout << "Unable to load restaurant menu " << '\n';
    return;
  }


  std::string active_line;

  bool active = true ;

  while (std::getline(file, active_line)) {
    if(active_line.find(std::to_string(*c.restaurant_chocie) + ". Restaurant Statu : " ) != std::string::npos){
      *c.found_activity = active_line.substr(active_line.find(": ") + 2);
      if(*c.found_activity == "CLOSED"){
        active = false;
      }
    }
  }



  if(!active){
    std::cout << "Currently this restaurant is not open" << '\n';
    return;
  }



  customer_menu(c);

}

