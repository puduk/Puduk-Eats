#include "remove.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

void remove(RestaurantData &r){

  std::ifstream show_file (*r.restaurant_name + ".txt" , std::ios::in);
  if (!show_file.is_open()){
    std::cout << "Unable to delete product.";
    return;
  }

  std::string amount_line;
  while (std::getline(show_file, amount_line)){
    if(amount_line.find("Product Name : ") != std::string::npos){
      (*r.product_id)++;
    }
  }

  show_file.seekg(0, std::ios::beg);


  std::cout << "Your products." << '\n';
  std::string show_line;

  while (std::getline(show_file, show_line)){
    if(show_line.find("Product Name : ") != std::string::npos){
      std::cout << show_line << '\n';
    }
  }

  std::cout << "-----------------------" << '\n';
  std::cout << "Your Choice : ";
  std::cin >> *r.remove_choice;

  if(std::cin.fail()){
    std::cout << "Please enter a number." << '\n';
    return;
  }

  if(*r.remove_choice > *r.product_id || *r.remove_choice == 0 ){
    std::cout << "Opps! We dont have that product." ;
    return;
  }

  show_file.seekg(0, std::ios::beg);
   std::ofstream remove_file (*r.restaurant_name + "_removed.txt" , std::ios::app);
  if (!remove_file.is_open()){
    std::cout << "Unable to delete product.";
    return;
  }

  std::ifstream remover_shower_file (*r.restaurant_name + "_removed.txt" , std::ios::in);
  if (!remover_shower_file.is_open()){
    std::cout << "Unable to delete product.";
    return;
  }

  std::ofstream temp_file("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Unable to delete product.";
    return;
  }

  std::string delete_line;
  std::string found_id;
  int current_id = -1;

  while (std::getline(show_file, delete_line)){

    found_id = delete_line.substr(0, delete_line.find("."));
    if (!found_id.empty() && std::all_of(found_id.begin(), found_id.end(), ::isdigit)) {
      current_id = std::stoi(found_id);
    }


    if(current_id == *r.remove_choice){
      remove_file << "[REMOVED] " << delete_line << '\n';
    }else{
      temp_file << delete_line << '\n';
    }
  }

  show_file.close();
  temp_file.close();
  remove_file.close();

  std::string filename = *r.restaurant_name + ".txt";
  std::remove (filename.c_str());
  std::rename ("temp.txt", filename.c_str());




  std::cout << "Successfully deleted." << '\n';

  std::string deleted_line;


  while (std::getline(remover_shower_file, deleted_line)){
    if(deleted_line.find("[REMOVED] " + std::to_string(*r.remove_choice) + ". Product Name : ") != std::string::npos){
      std::cout << deleted_line << '\n';
    }
  }

  // menu

}














