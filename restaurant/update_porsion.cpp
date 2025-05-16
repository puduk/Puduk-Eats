#include "update_porsion.hpp"
#include <iostream>
#include <fstream>

void update_porsion (RestaurantData& r){

  std::ifstream update_file (*r.restaurant_name + ".txt" , std::ios::in);
  if (!update_file.is_open()){
    std::cout << "Unable to update product" ;
    return;
  }

  std::string amount_line;
  while(std::getline(update_file, amount_line)){
    if(amount_line.find("Product Name : ") != std::string::npos){
      (*r.product_id)++;
    }
  }

  update_file.close();
  update_file.open(*r.restaurant_name + ".txt" , std::ios::in);

  std::cout << "Choose Product You Want to Change : " << '\n';
  std::string update_line;
  while (std::getline(update_file, update_line)){
    if(update_line.find("Product Name : ")!=std::string::npos){
      std::cout << update_line << '\n';
    }else if (update_line.find("Product Porsion : ")!=std::string::npos){
      std::cout << update_line << '\n';
    }
  }
  std::cout << "----------------------------" << '\n';
  std::cout << "Your Choice : " ;
  std::cin >> *r.update_choice;


  if(std::cin.fail()){
    std::cout << "Please enter a number." ;
    return;
  }

  if(*r.update_choice > *r.product_id || *r.update_choice == 0){
    std::cout << "Opps! We dont have that." ;
    return;
  }
  std::cout << "Whats the new porsion : " ;
  std::cin >> *r.updated_porsion;

  update_file.close();
  update_file.open(*r.restaurant_name + ".txt" , std::ios::in);

  std::ofstream temp_file ("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Unable to update product" ;
    return;
  }
  std::string final_line;
  std::string updated_product;

  while(std::getline(update_file, final_line)){
    if(final_line.find(std::to_string(*r.update_choice) + ". Product Name : ")!=std::string::npos){
      updated_product = final_line.substr(final_line.find(": ") + 2);
    }
    if(final_line.find(std::to_string(*r.update_choice) + ". Product Porsion : ")!=std::string::npos){
      temp_file << *r.update_choice << ". " << "Product Porsion : " << *r.updated_porsion << '\n';
    }else {
      temp_file << final_line << '\n';
    }
  }

  temp_file.close();
  update_file.close();

  std::string filename = *r.restaurant_name + ".txt";
  std::remove (filename.c_str());
  std::rename ("temp.txt", filename.c_str());

  std::cout << updated_product << " Porsion Successfully Updated." << '\n';


}

