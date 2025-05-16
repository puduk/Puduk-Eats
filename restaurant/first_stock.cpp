#include "first_stock.hpp"
#include <iostream>
#include <fstream>
#include "restaurant_menu.hpp"

void first_stock(RestaurantData &r ) {

  std::ofstream stock_file(*r.restaurant_name + "_stock.txt" , std::ios::app);
  if(!stock_file.is_open()) {
    std::cout << "Unable to add product . " ;
    return;
  }


  std::cout << "-------------------------" << '\n';
  std::cout << "How many items you need for (ex. 4) " << *r.product_name  << '\n';
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

  while(sure && taken_item < *r.needed_item && !std::cin.fail()){
    std::cout << "Enter Item name : " << '\n';
    std::cin >> *r.item_name;
    std::cout << "How many " << *r.item_name << " You have : " << '\n';
    std::cin >> *r.item_amount;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number : ";
      return;
    }
    std::ofstream recipe_file(*r.product_name + ".txt" , std::ios::app);
    if(!recipe_file.is_open()){
      std::cout << "Unable to add product . " ;
      return;
    }
    recipe_file << *r.item_id << ". " << "Item name : " << *r.item_name << '\n';

    stock_file << *r.item_id << ". " << "Item name : " << *r.item_name << '\n';
    stock_file << *r.item_id << ". " << "Item amount : " << *r.item_amount << '\n';
    (*r.item_id)++;
    taken_item++;

  }

  stock_file.flush();
  stock_file.close();


  std::cout << "All " << taken_item << " items have been added.\n";




  restaurant_menu(r);



}