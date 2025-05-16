#include "add_stock.hpp"
#include <iostream>
#include <fstream>
#include "restaurant_menu.hpp"

void add_stock(RestaurantData &r) {

  std::ofstream stock_file(*r.restaurant_name + "_stock.txt" , std::ios::app);
  if(!stock_file.is_open()) {
    std::cout << "Unable to add product . " ;
    return;
  }

  std::ifstream amount_file(*r.restaurant_name + "_stock.txt" , std::ios::in);
  if(!amount_file.is_open()) {
    std::cout << "Unable to add product . " ;
    return;
  }

  std::string amount_line;

  while(std::getline(amount_file, amount_line)) {
    if(amount_line.find("Item name : ") != std::string::npos) {
      (*r.item_id)++;
    }
  }

  std::cout << "-------------------------" << '\n';
  std::cout << "How many items you need for (ex. 4) " << *r.product_name  << '\n';
  *r.needed_item = 0;
  std::cin >> *r.needed_item;
  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Please enter a number : ";
    return;
  }

  bool sure = false;

  if(*r.needed_item < 5){
    sure = true;
  }


    while(!sure){
      if(*r.needed_item > 5){
        std::cout << "You will add " << *r.needed_item <<" item are you sure ? (Y - N) : ";
        std::cin >> *r.are_sure;
        *r.are_sure = tolower(*r.are_sure);
        if (*r.are_sure == 'y'){
          sure = true;
        }
        if (*r.are_sure == 'n'){
          sure = false;
          std::cout << "How many item you want to add : " ;
          std::cin >> *r.needed_item;
        }
      }
    }


  int taken_item = 0;

  std::cin.ignore(1000, '\n');

  while(sure && taken_item < *r.needed_item  && !std::cin.fail()){
    std::cin.clear();
    std::cout << "Enter Item name : " << '\n';
    std::cin >> *r.item_name;


    std::ofstream recipe_file (*r.product_name + ".txt" , std::ios::app);
    if (!recipe_file.is_open()) {
      std::cout << "Unable to re-check stock. \n";
      return;
    }

    std::ifstream already_file(*r.restaurant_name + "_stock.txt", std::ios::in);
    if (!already_file.is_open()) {
      std::cout << "Unable to re-check stock. \n";
      return;
    }

    std::string already_line;
    std::string found_item;
    bool exists = false;
    while(std::getline(already_file, already_line)) {
      if(already_line.find("Item name : ") != std::string::npos) {
        found_item = already_line.substr(already_line.find(": ") + 2);
        if(found_item == *r.item_name){
          exists = true;
        }
      }
    }
    already_file.close();
    if(exists){
       std::cout << "This item already exists in your stock. \n";
       std::cout << "Please check your stock condition first. \n";
       return;

    }
    std::cout << "How many " << *r.item_name << " You have : " << '\n';
    std::cin >> *r.item_amount;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number : ";
      return;
    }

    recipe_file << *r.item_id << ". " << "Item name : " << *r.item_name << '\n';

    stock_file << *r.item_id << ". " << "Item name : " << *r.item_name << '\n';
    stock_file << *r.item_id << ". " << "Item amount : " << *r.item_amount << '\n';
    (*r.item_id)++;
    taken_item++;
    stock_file.flush();
    recipe_file.flush();
  }


  stock_file.close();


  std::cout << "All " << taken_item << " items have been added.\n";

  restaurant_menu(r);

}
