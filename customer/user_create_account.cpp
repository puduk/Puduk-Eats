#include "user_create_account.hpp"
#include <iostream>
#include <fstream>

void user_create_account(CustomerData &c) {

  std::ifstream customer_file("customer.txt" , std::ios::in);
  if (!customer_file.is_open()) {
    std::cout << "Unable to create customer account" << std::endl;
    return;
  }
  std::ofstream account_file("customer.txt", std::ios::app);
  if (!account_file.is_open()) {
    std::cout << "Unable to create customer account" << std::endl;
    return;
  }

  std::string id_line;
  while(std::getline(customer_file, id_line)) {
    if(id_line.find("Username : ") != std::string::npos) {
      (*c.customer_id )++;
    }
  }

  customer_file.close();
  customer_file.open("customer.txt", std::ios::in);

  std::cout << "Username : " ;
  std::cin >> *c.username ;


  std::string customer_line;
  std::string found_username;
  bool taken = false;

  std::ofstream personal_file(*c.username + "_data.txt", std::ios::app);
  if (!personal_file.is_open()) {
    std::cout << "Currently we are having problem to create customer account" ;
    return;
  }
  std::ofstream balance_file(*c.username + "_balance.txt", std::ios::app);
  if (!personal_file.is_open()) {
    std::cout << "Currently we are having problem to create customer account" ;
    return;
  }

  while(std::getline(customer_file, customer_line)) {
    if(customer_line.find("Username : ") != std::string::npos) {
      found_username = customer_line.substr(customer_line.find(": ") + 2 );
      if(found_username == *c.username ){
        taken = true;
      }
    }
  }

  if(taken){
    std::cout << "This username already exists" ;
    return;
  }


  std::cout << "Password : " ;
  std::cin >> *c.password ;

  account_file << *c.customer_id << ". " << "Username : " << *c.username << '\n';
  account_file << *c.customer_id << ". " << "Password : " << *c.password << '\n';

  std::cout << "Delivery Adderss : " ;
  std::cin.clear();
  std::cin.ignore(1000,'\n');
  std::getline(std::cin,*c.address);

  std::cout << "Phone Number : ";
  std::cin >> *c.phone;


  personal_file << *c.customer_id << ". " << "Delivery Adderss : " << *c.address << '\n';
  personal_file << *c.customer_id << ". " << "Phone Number : " << *c.phone << '\n';

  balance_file << *c.customer_id << ". " << "Username : " << *c.username << '\n';
  balance_file << *c.customer_id << ". " << "Balance : " << *c.balance << '\n';



  std::cout << "Account created successfully" << '\n';
}















