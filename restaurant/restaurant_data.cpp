#include "restaurant_data.hpp"
#include <iostream>

RestaurantData::RestaurantData(){

  restaurant_name = new std::string;
  restaurant_password = new std::string;
  restaurant_address = new std::string;
  restaurant_phone_number = new std::string;


  restaurant_amount = new int(1);
  restaurant_menu_choice = new int;

  product_name = new std::string;
  alergy_test = new std::string;
  product_price = new double;
  calories = new int;
  product_porsion = new double;
  updated_porsion = new double;
  updated_price = new double;


  product_id = new int(1);

  remove_choice = new int;
  update_choice = new int;
  update_price_choice = new int;

  promo_code = new std::string;
  promo_price = new double;
  promo_id = new int(1);

  needed_item = new int;

  are_sure = new char;

  item_name = new std::string;
  item_amount = new int;
  item_id = new int(1);

  stock_choice = new int;
  updated_stock = new int;

  active_choice = new int;
  restaurant_rate = new int;
  total_rate = new int(1);
  found_product = new std::string;


}

RestaurantData::~RestaurantData(){

  delete restaurant_name;
  delete restaurant_password;
  delete restaurant_address;
  delete restaurant_phone_number;

  delete restaurant_amount;
  delete restaurant_menu_choice;

  delete product_name;
  delete alergy_test;
  delete product_price;
  delete calories;

  delete product_id;
  delete remove_choice;
  delete product_porsion;
  delete update_choice;
  delete updated_porsion;
  delete update_price_choice;
  delete updated_price;

  delete promo_code;
  delete promo_price;
  delete promo_id;

  delete needed_item;
  delete are_sure;

  delete item_name;
  delete item_amount;
  delete item_id;

  delete stock_choice;
  delete updated_stock;

  delete active_choice;
  delete restaurant_rate;
  delete total_rate;
  delete found_product;


}
