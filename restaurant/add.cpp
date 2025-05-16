#include "add.hpp"
#include <iostream>
#include <fstream>
#include "add_stock.hpp"

void add(RestaurantData& r) {

  std::ifstream id_file (*r.restaurant_name + ".txt" , std::ios::in);
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

  id_file.close();
  id_file.open(*r.restaurant_name + ".txt" , std::ios::in);




  std::cout << "-----------------" << '\n';
  std::cout << "Product Name : " ;
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, *r.product_name);


  std::string product_line;

  while (std::getline(id_file, product_line)) {
    if (product_line.find("Product Name : ") != std::string::npos) {
      *r.found_product = product_line.substr(product_line.find(": ") + 2);
    }if (*r.found_product == *r.product_name) {
      std::cout << "Product Already Added :  " << *r.product_name << '\n';
      return;
    }
  }



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

  add_file.flush();
  add_file.close();


  std::cout << "Your product " << *r.product_name << " Successfully added." <<'\n';

  add_stock(r);
}

