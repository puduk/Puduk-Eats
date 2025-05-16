#include "create_promo_code.hpp"
#include <iostream>
#include <fstream>

void create_promo_code(RestaurantData& r){

  std::ofstream promo_file (*r.restaurant_name + "_promo.txt" , std::ios::app);
  if (!promo_file.is_open()){
    std::cout << "Can not create promo code." ;
    return;
  }

  std::ifstream check_file (*r.restaurant_name + "_promo.txt" , std::ios::in);
  if (!check_file.is_open()){
    std::cout << "Can not create promo code." ;
    return;
  }

  std::string amount_line;
  while(std::getline(check_file, amount_line)){
    if(amount_line.find("Promo Code : ") != std::string::npos){
      (*r.promo_id) ++;
    }
  }

  check_file.seekg(0 , std::ios::beg);

  std::cout << "Enter your Promo Code: ";
  std::cin >> *r.promo_code;

  std::string promo_line;
  std::string found_promo;
  bool taken = false;
  while(std::getline(check_file, promo_line)){
    if(promo_line.find("Promo Code : ") != std::string::npos){
      found_promo = promo_line.substr(promo_line.find(": ") + 2);
      if(found_promo == *r.promo_code){
        taken = true;
      }
    }
  }

  if(taken){
    std::cout << "This promo code already taken : " << *r.promo_code << '\n';
    return;
  }

  std::cout << "Enter Discount Amount (-$20) : ";
  std::cin >> *r.promo_price;

  if(std::cin.fail()){
    std::cout << "Please enter a number" << '\n';
    return;
  }

  promo_file << *r.promo_id << ". " << "Promo Code : " << *r.promo_code << '\n';
  promo_file << *r.promo_id << ". " << "Promo Price : " << *r.promo_price << '\n';

  promo_file.flush();
  promo_file.close();


  std::cout << "Promo code : " << *r.promo_code << " created with discount: " << *r.promo_price << '\n';


}
