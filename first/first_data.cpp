#include "first_data.hpp"


FirstData::FirstData(){

  first_page_choice = new int();
  username = new std::string();
  restaurant_name = new std::string();



}

FirstData::~FirstData(){

  delete first_page_choice;
  delete username;
  delete restaurant_name;

}
