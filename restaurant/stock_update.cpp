#include "stock_update.hpp"
#include <iostream>
#include <fstream>

void stock_update(RestaurantData &r) {

  std::ifstream check_file (*r.restaurant_name + "_stock.txt" , std::ios::in);
  if (!check_file.is_open()) {
    std::cout << "Unable to update stock condition." << '\n';
    return;
  }

  std::ofstream temp_file ("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Unable to update stock condition." << '\n';
    return;
  }

  std::string amount_line;

  while (std::getline(check_file, amount_line)) {
    if (amount_line.find("Item name : ") != std::string::npos) {
      (*r.item_id) ++;
    }
  }

  check_file.close();
  check_file.open (*r.restaurant_name + "_stock.txt" , std::ios::in);

  std::cout << "Your Current Items : " << '\n';

  std::string line;

  while (std::getline(check_file, line)) {


      std::cout << line << '\n';

  }
  std::cout << "-------------------------" << '\n';
  std::cout << "Your Choice : ";
  std::cin >> *r.stock_choice;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Please enter a number : " ;
    return;
  }

  if(*r.stock_choice > *r.item_id ){
    std::cout << "Opps! We dont have that.";
    return;
  }
  check_file.close();
  check_file.open (*r.restaurant_name + "_stock.txt" , std::ios::in);

  std::string item_name;
  std::string item_line;

  while (std::getline(check_file, item_line)) {
    if (item_line.find(std::to_string(*r.stock_choice) + ". Item Name : ") != std::string::npos) {
      item_name = item_line.substr(item_line.find(": ") + 2);
    }
  }

  std::cout << "Whats the new amount for " << item_name << " : ";
  std::cin >> *r.updated_stock;
  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Please enter a number : " ;
    return;
  }


  check_file.close();
  check_file.open (*r.restaurant_name + "_stock.txt" , std::ios::in);

  std::string final_line;

  while(std::getline(check_file, final_line)){
    if(final_line.find(std::to_string(*r.stock_choice) + ". Item amount : ") != std::string::npos){
      temp_file << *r.stock_choice << ". " << "Item amount : " << *r.updated_stock << '\n';
    }else {
      temp_file << final_line << '\n';
    }
  }

  std::string filename = *r.restaurant_name + "_stock.txt";
  std::remove(filename.c_str());
  std::rename("temp.txt" , filename.c_str());

  std::cout << "Item " << item_name << " amount updated to " << *r.updated_stock ;

}

