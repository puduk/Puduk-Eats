#include "user_sign_in.hpp"
#include <iostream>
#include <fstream>
#include "choose_restaurant.hpp"

void user_sign_in(CustomerData &c) {

  std::ifstream check_file("customer.txt" , std::ios::in);
  if (!check_file.is_open()) {
    std::cout << "Currently Can Not Sign In" ;
    return;
  }

  std::cout << "Username : " ;
  std::cin >> *c.username;
  std::cout << "Password : " ;
  std::cin >> *c.password;

  std::string check_line;
  std::string found_username;
  std::string found_password;
  bool found = false;

  while(std::getline(check_file, check_line)) {
    if(check_line.find("Username : ")!=std::string::npos) {
      found_username = check_line.substr(check_line.find(": ") + 2);
    }else if (check_line.find("Password : ")!=std::string::npos) {
      found_password = check_line.substr(check_line.find(": ") + 2);
      if(found_username == *c.username && found_password == *c.password) {
        found = true;
      }
    }
  }


  if(!found) {
    std::cout << "Username or Password Is Incorrect" << '\n';
    return;
  }

  std::cout << "Singing..." << '\n';

  choose_restaurant(c);

}