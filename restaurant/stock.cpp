#include "stock.hpp"
#include <iostream>
#include <fstream>

void stock(RestaurantData &r) {

  std::ifstream stock_file (*r.restaurant_name + "_stock.txt" , std::ios::in);
  if(!stock_file.is_open()) {
    std::cout << "Unable to read stock." << '\n';
    return;
  }

  std::string stock_line;
  while(std::getline(stock_file, stock_line)) {
    std::cout << stock_line << '\n';
  }



}


