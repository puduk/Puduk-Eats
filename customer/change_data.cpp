#include "change_data.hpp"
#include <iostream>
#include <fstream>
#include "customer_menu.hpp"

void change_data(CustomerData &c){

  while(true){
    std::cout << "--------------------------------" << '\n';
    std::cout << "1 :: for change Delivery Address" << '\n';
    std::cout << "2 :: for change Phone Number" << '\n';
    std::cout << "3 :: for previous page" << '\n';
    std::cout << "--------------------------------" << '\n';
    std::cout << "Your choice : ";
    std::cin >> *c.change_data_choice;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number." << '\n';
      return;
    }
    switch(*c.change_data_choice){
      case 1:
        change_address(c);
        break;
      case 2:
        change_number(c);
        break;
      case 3:
        return customer_menu(c);
      default:
        std::cout << "Invalid Choice." << '\n';
    }
  }
}

void change_address(CustomerData &c){


  std::ifstream address_file(*c.username + "_data.txt", std::ios::in);
  if(!address_file.is_open()){
    std::cout << "Current you can not change your address." << '\n';
    return;
  }
  std::ofstream temp_file("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Current you can not change your address." << '\n';
    return;
  }
  std::cout << "Enter your new address : " << '\n';
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, *c.new_address);

  int current_id = 1;
  std::string address_line;
  while(std::getline(address_file, address_line)){
    if(address_line.find("Delivery Adderss : ") != std::string::npos){
      temp_file << current_id << ". " << "Delivery Adderss : " << *c.new_address << '\n';
    }else{
      temp_file << address_line << '\n';
    }
  }

  std::string filename = *c.username + "_data.txt";
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());

  std::cout << "Your address successfully changed " << '\n';

}

void change_number(CustomerData &c){

  std::ifstream phone_file(*c.username + "_data.txt", std::ios::in);
  if(!phone_file.is_open()){
    std::cout << "Currently you can not change your phone number." << '\n';
    return;
  }
  std::ofstream temp_file("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Currently you can not change your phone number." << '\n';
    return;
  }

  std::cout << "Enter your new number : " << '\n';
  std::cin >> *c.new_phone;
  int current_id = 1;

  std::string number_line;

  while(std::getline(phone_file, number_line)){
    if(number_line.find("Phone Number : ") != std::string::npos){
      temp_file << current_id << ". " << "Phone Number : " << *c.new_phone << '\n';
    }else {
      temp_file << number_line << '\n';
    }
  }

  std::string filename = *c.username + "_data.txt";
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());

  std::cout << "Your phone number successfully changed " << '\n';
}
