#include "update_price.hpp"
#include <iostream>
#include <fstream>

void update_price(RestaurantData& r){


  std::ifstream update_file(*r.restaurant_name + ".txt" , std::ios::in);
  if(!update_file.is_open()){
    std::cout << "Unable to update price.";
    return;
  }

  std::string amount_line ;
  while(std::getline(update_file, amount_line)){
    if(amount_line.find("Product Name : ") != std::string::npos){
      (*r.product_id)++;
    }
  }

  update_file.seekg(0, std::ios::beg);

  std::cout << "Your Products." << '\n';
  std::string update_line;
  while(std::getline(update_file, update_line)){
    if(update_line.find("Product Name : ") != std::string::npos){
      std::cout << update_line << '\n';
    }else if (update_line.find("Product Price : ") != std::string::npos){
      std::cout << update_line << '\n';
    }
  }
  std::cout << "-----------------------" << '\n';
  std::cin >> *r.update_price_choice;

  if(std::cin.fail()){
    std::cout << "Please enter a number.";
    return;
  }

  if(*r.update_price_choice > *r.product_id || *r.product_id == 0){
    std::cout << "Opps! We dont have that.";
    return;
  }

  std::cout << "Enter New Price: ";
  std::cin >> *r.updated_price;

  std::ofstream temp_file ("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Unable to update price.";
    return;
  }

  std::string final_line;
  std::string updated_product;

  while(std::getline(update_file, final_line)){
    if(final_line.find(std::to_string(*r.update_price_choice) + ". Product Name : ") != std::string::npos){
      updated_product = final_line.substr(final_line.find(": ") + 2);
    }
    if(final_line.find(std::to_string(*r.update_price_choice) + ". Product Price : ") != std::string::npos){
      temp_file << *r.update_price_choice << ". " << "Product Price : " << *r.updated_price << '\n';
    }else{
      temp_file << final_line << '\n';
    }
  }

  update_file.close();
  temp_file.close();

  std::string filename = *r.restaurant_name + ".txt";
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());


  std::cout << updated_product << " Price Successfully Updated." << '\n';



}

