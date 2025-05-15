#include "first_add.hpp"
#include <iostream>
#include <fstream>

void first_add(RestaurantData& r) {

    std::ofstream first_file (*r.restaurant_name + ".txt" , std::ios::app);
    if (!first_file.is_open()) {
      std::cout << "Unfortunately can not create account.";
      return;
    }


  std::cout << "Add your first product." << '\n';
  std::cout << "-----------------------" << '\n';
  std::cin.clear();
  std::cin.ignore(1000 , '\n');
  std::cout << "Product Name : " ;
  std::getline(std::cin, *r.product_name);
  std::cout << "Product Price : ";
  std::cin >> *r.product_price;
  std::cout << "Product Calories : ";
  std::cin >> *r.calories;
  std::cout << "Any alergetic effect?" ;
  std::cin.clear();
  std::cin.ignore(1000 , '\n');
  std::getline(std::cin, *r.alergy_test);
  std::cout << "Product Porsion (500gr..) : ";
  std::cin >> *r.product_porsion;



  first_file << *r.product_id << ". " <<"Product Name : " << *r.product_name << '\n';
  first_file << *r.product_id << ". " <<"Product Price : " << *r.product_price << '\n';
  first_file << *r.product_id << ". " <<"Product Calories : " << *r.calories << '\n';
  first_file << *r.product_id << ". " <<"Product Alergy : " << *r.alergy_test << '\n';
  first_file << *r.product_id << ". " <<"Product Porsion : " << *r.product_porsion << '\n';
  first_file << "/-/-/-/" << '\n';

  std::cout << "Your first product " << *r.product_name << " Successfully added." <<'\n';





}
