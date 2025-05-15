#include "add.hpp"
#include <iostream>
#include <fstream>

void add(RestaurantData& r) {

  std::ifstream id_file (*r.restaurant_name + ".txt" , std::ios::in));
  if (!id_file.is_open()) {
    std::cout << "Unable to add product.";
    return;
  }

  std::string id_line;
  while(std::getline(id_file, id_line)) {
    if(id_line.find("Product Name : ") != std::string::npos) {
      (*r.product_id)++;
    }
  }


  std::ofstream add_file (*r.restaurant_name + ".txt" , std::ios::app);
  if(!add_file.is_open()) {
    std::cout << "Unable to add product.";
    return;
  }




  std::cout << "-----------------" << '\n';
  std::cout << "Product Name : " ;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, *r.product_name);
  std::cout << "Product Price : ";
  std::cin >> *r.product_price;
  std::cout << "Calories : ";
  std::cin >> *r.calories;
  std::cout << "Product Porsion (500gr..) : ";
  std::cin >> *r.product_porsion;
  std::cout << "Any Alergetic Reaction : " ;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, *r.alergy_test);





  add_file << *r.product_id << ". " <<"Product Name : " << *r.product_name << '\n';
  add_file << *r.product_id << ". " <<"Product Price : " << *r.product_price << '\n';
  add_file << *r.product_id << ". " <<"Product Calories : " << *r.calories << '\n';
  add_file << *r.product_id << ". " <<"Product Alergy : " << *r.alergy_test << '\n';
  add_file << *r.product_id << ". " <<"Product Porsion : " << *r.product_porsion << '\n';
  add_file << "/-/-/-/" << '\n';


  std::cout << "Your product " << *r.product_name << " Successfully added." <<'\n';

}

