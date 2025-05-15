#include "user_quit.hpp"
#include <iostream>
#include <fstream>

void user_quit(CustomerData& c){

  std::ofstream rate_file("customer_rate.txt" , std::ios::app);
  if(!rate_file.is_open()){
    std::cout << "Currently can not rate." << '\n';
    return;
  }
  std::ifstream amount_file("customer_rate.txt" , std::ios::in);
  if(!amount_file.is_open()){
    std::cout << "Currently can not rate." << '\n';
    return;
  }

  std::string amount_line;
  while(std::getline(amount_file, amount_line)){
    if(amount_line.find("Customer : ") != std::string::npos){
      (*c.total_rate) ++;
    }
  }


  std::cout << "-------------------------------------" << '\n';
  std::cout << "Thank you for using this application!" << '\n';
  std::cout << "Rate it! Before Quit (1 - 10)" << '\n';
  std::cout << "-------------------------------------" << '\n';
  std::cin >> *c.customer_rate;
  while(*c.customer_rate < 1 || *c.customer_rate > 10 || std::cin.fail()){
    std::cout << "Please enter a number between 1 and 10: ";
    std::cin >> *c.customer_rate;
  }

  rate_file << *c.total_rate << ". " << "Customer : " << *c.username << " - Rate : " << *c.customer_rate << '\n';

  std::cout << "Goodbye!" << '\n';

}

