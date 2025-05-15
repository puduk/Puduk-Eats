#include "choose_restaurant.hpp"
#include <iostream>
#include <fstream>
#include "restaurant_condition.hpp"


void choose_restaurant(CustomerData& c){

  std::ifstream file("restaurant.txt" , std::ios::in);
  if(!file.is_open()){
    std::cout << "Unable to load restaurants" ;
    return;
  }

  std::string amount_line;

  while(std::getline(file,amount_line)){
    if(amount_line.find("Restaurant Name : ") != std::string::npos){
      (*c.showen_restaurant_amount)++;
    }
  }

  file.close();
  file.open("restaurant.txt", std::ios::in);

  std::cout << "Restaurants " << '\n';

  std::string restaurant_line;
  while(std::getline(file,restaurant_line)){
    if(restaurant_line.find("Restaurant Name : ") != std::string::npos){
      std::cout << restaurant_line << '\n';
    }
  }
  std::cout << "--------------------------" << '\n';
  std::cout << "Your Choice  " ;
  std::cin >> *c.restaurant_chocie;

  if(std::cin.fail()){
    std::cout << "Please enter a number." ;
    return;
  }

  if(*c.restaurant_chocie > *c.showen_restaurant_amount){
    std::cout << "Opps We dont have that." << '\n';
    return;
  }

  file.close();
  file.open("restaurant.txt", std::ios::in);

  std::string chosen_line;
  while(std::getline(file,chosen_line)){
    if(chosen_line.find(std::to_string(*c.restaurant_chocie) + ". Restaurant Name : ") != std::string::npos){
      *c.choosen_restaurant = chosen_line.substr(chosen_line.find(": ") + 2);
    }
  }



  restaurant_condition(c);



}