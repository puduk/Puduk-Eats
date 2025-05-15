#include "active.hpp"
#include <iostream>
#include <fstream>

void active(RestaurantData& r){

  std::ifstream active_file(*r.restaurant_name + "_statu.txt" , std::ios::in);
  if (!active_file.is_open()) {
    std::cout << "Unable to change activity.";
    return;
  }

  std::cout << "Your Restaurant Statu : " << '\n';
  std::string active_line;
  while (std::getline(active_file, active_line)) {
    std::cout << active_line << '\n';
  }

  std::cout << "-------------------------------" << '\n';
  std::cout << "1 :: for opened restaurant" << '\n';
  std::cout << "2 :: for closing restaurant" << '\n';
  std::cout << "-------------------------------" << '\n';
  std::cout << "Your Choice : " ;
  std::cin >> *r.active_choice;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(1000 , '\n');
    std::cout << "Please enter a number : " ;
    return;
  }

  switch (*r.active_choice) {
    case 1:
      open(r);
      break;
    case 2:
      close(r);
      break;
    default:
      std::cout << "Please enter a valid input : " << '\n';
      return;
  }
}

void open (RestaurantData& r){

  std::ifstream open_file(*r.restaurant_name + "_statu.txt" , std::ios::in);
  if (!open_file.is_open()) {
    std::cout << "Unable to open the restaurant.";
    return;
  }

  std::ofstream temp_file ("temp.txt" , std::ios::out);
  if (!temp_file.is_open()) {
    std::cout << "Unable to open the restaurant.";
    return;
  }

  std::string open_line;

  while (std::getline(open_file, open_line)) {
    if(open_line.find("Restaurant Statu : ") != std::string::npos){
      temp_file << "Restaurant Statu : " << "OPEN" << '\n';
    }else {
      temp_file << open_line << '\n';
    }
  }

  temp_file.close();
  open_file.close();

  std::string filename = *r.restaurant_name + "_statu.txt";
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());

  std::cout << "Restaurant Statu Changed to : OPEN " << '\n';

}

void close (RestaurantData& r){

  std::ifstream close_file(*r.restaurant_name + "_statu.txt" , std::ios::in);
  if (!close_file.is_open()) {
    std::cout << "Unable to close the restaurant.";
    return;
  }

  std::ofstream temp_file ("temp.txt" , std::ios::out);
  if (!temp_file.is_open()) {
    std::cout << "Unable to close the restaurant.";
    return;
  }

  std::string close_line;

  while (std::getline(close_file, close_line)) {
    if(close_line.find("Restaurant Statu : ") != std::string::npos){
      temp_file << "Restaurant Statu : " << "CLOSED" << '\n';
    }else {
      temp_file << close_line << '\n';
    }
  }

  temp_file.close();
  close_file.close();

  std::string filename = *r.restaurant_name + "_statu.txt";
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());

  std::cout << "Restaurant Statu Changed to : CLOSED " << '\n';

}














