#include "order_history.hpp"
#include <fstream>
#include <iostream>

void order_history(CustomerData& c) {

  std::ifstream order_file(*c.username + ".txt" , std::ios::in);
  if(!order_file.is_open()){
    std::cout << "Unable to load order history. " << '\n';
    return;
  }

  if(order_file.peek() == std::ifstream::traits_type::eof()){
    std::cout << "No order history found. " << '\n';
    return;
  }

  std::string line;
  while(std::getline(order_file, line)){
    std::cout << line << '\n';
  }



}

