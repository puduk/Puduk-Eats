#include "create_account.hpp"
#include <iostream>
#include <fstream>
#include "first_add.hpp"

void restaurant_create_account(RestaurantData &r){


  std::ifstream check_file("restaurant.txt" , std::ios::in);
  if (!check_file.is_open()){
    std::cout << "Unable to create account" << '\n';
    return;
  }

  std::string amount_line;

  while (std::getline(check_file, amount_line)){
    if(amount_line.find("Restaurant Name : ") != std::string::npos){
      (*r.restaurant_amount)++;
    }
  }

  check_file.clear();
  check_file.seekg(0, std::ios::beg);

  std::cout << "Restaurant Name: " << '\n';
  std::cin.clear();
  std::cin.ignore(1000 , '\n');
  std::getline(std::cin, *r.restaurant_name);

  std::string found_name;
  std::string name_line;
  bool name_found = false;

  while(std::getline(check_file, name_line)){
    if(name_line.find("Restaurant Name : ") != std::string::npos){
      found_name = name_line.substr(name_line.find(": ") + 2);
      if(found_name == *r.restaurant_name ){
        name_found = true;
      }
    }
  }
  if(name_found){
    std::cout << "This Restaurant Name is Already Taken.";
    return;
  }

  check_file.clear();
  check_file.seekg(0, std::ios::beg);

  std::cout << "Restaurant Password: " << '\n';
  std::cin >> *r.restaurant_password;

  std::cout << "Restaurant Address: " << '\n';
  std::cin.clear();
  std::cin.ignore(1000 , '\n');
  std::getline(std::cin, *r.restaurant_address);

  std::string found_address;
  std::string address_line;
  bool address_found = false;

  while(std::getline(check_file, address_line)){
    if(address_line.find("Restaurant Address: ") != std::string::npos){
      found_address = address_line.substr(address_line.find(": ") + 2);
      if(found_address == *r.restaurant_address ){
        address_found = true;
      }
    }
  }
  if(address_found){
    std::cout << "This Address is Already Taken.";
    return;
  }

  check_file.clear();
  check_file.seekg(0, std::ios::beg);

  std::cout << "Restaurant Phone Number: " << '\n';
  std::cin >> *r.restaurant_phone_number;


  std::string found_phone_number;
  std::string number_line;
  bool phone_number_found = false;

  while(std::getline(check_file, number_line)){
    if(number_line.find("Restaurant Number: ") != std::string::npos){
      found_phone_number = number_line.substr(number_line.find(": ") + 2);
      if(found_phone_number == *r.restaurant_phone_number ){
        phone_number_found = true;
      }
    }
  }

  if(phone_number_found){
    std::cout << "This Phone Number is Already Taken.";
    return;
  }

  std::ofstream write_file("restaurant.txt" , std::ios::app);
  if(!write_file.is_open()){
    std::cout << "Unable to create account" ;
    return;
  }

  std::ofstream status_file("restaurant_statu.txt" , std::ios::app);
  if(!status_file.is_open()){
    std::cout << "Unable to create account";
    return;
  }


  (*r.restaurant_amount)++; // on the previous lines i found total restaurant and in here i am adding one this number for new created restaurant
// primary id

  write_file << *r.restaurant_amount << ". " << "Restaurant Name : " << *r.restaurant_name << '\n';
  write_file << *r.restaurant_amount << ". " << "Restaurant Password : " << *r.restaurant_password << '\n';
  write_file << *r.restaurant_amount << ". " << "Restaurant Address : " << *r.restaurant_address<< '\n';
  write_file << *r.restaurant_amount << ". " << "Restaurant Number : " << *r.restaurant_phone_number << '\n';


  status_file << *r.restaurant_amount << ". " << "Restaurant Name : " << *r.restaurant_name << '\n';
  status_file << *r.restaurant_amount << ". " << "Restaurant Statu : " << "OPEN" << '\n';

  first_add(r);


}










