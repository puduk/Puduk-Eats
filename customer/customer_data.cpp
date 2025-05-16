#include "customer_data.hpp"
#include <iostream>

std::string CustomerData::meal[7] = {
    "1. Do you like spicy food? (1: Not at all - 5: Love it)",
    "2. How hungry are you right now? (1: Not really - 5: Starving)",
    "3. Meat or veggies? (1: Only vegetables - 5: Only meat)",
    "4. Light or filling meal? (1: Light - 5: Heavy)",
    "5. Home-cooked or fast food? (1: Home - 5: Fast food)",
    "6. Are you open to new flavors? (1: Not really - 5: Always up for it)",
    "7. How's your mood today? (1: Terrible - 5: Amazing)"
};


CustomerData::CustomerData(){

  meal_answer = new int;
  meal_score = new int(0);

  username = new std::string;
  password = new std::string;
  address = new std::string;
  phone = new std::string;

  customer_id = new int(1);
  restaurant_chocie = new int;
  choosen_restaurant = new std::string;
  showen_restaurant_amount = new int;
  menu_choice = new int;
  order_choice = new int;
  product_amount = new int;

  balance = new double(0);
  extra_balance = new double;
  total_balance = new double;



  are_sure = new char;

  card_number = new std::string;
  card_ccv = new std::string;
  card_date = new std::string;

  save_data = new char;

  card_amount = new int(1);
  card_choice = new char;
  card_id_choice = new int;

  capacity = new int(5);
  ingredients = new std::string*[*capacity];
  chosen_product = new std::string;

  for (int i = 0; i < *capacity; i++) {
    ingredients[i] = nullptr;
  }


  current = new int(0);
  order_amount = new int(1);
  chosen_price = new double;

  checked_balance = new double;
  customer_service_choice = new int;
  change_data_choice = new int;
  new_address = new std::string;
  new_phone = new std::string;
  customer_rate = new int;
  total_rate = new int(1);
  promo_code = new std::string;
  last_price = new double;
  taken_balance = new double(0.0);
  found_activity = new std::string;


}
CustomerData::~CustomerData(){

  delete username;
  delete password;
  delete address;
  delete phone;

  delete customer_id;
  delete restaurant_chocie;
  delete choosen_restaurant;
  delete showen_restaurant_amount;
  delete menu_choice;
  delete order_choice;
  delete product_amount;
  delete balance;
  delete extra_balance;
  delete total_balance;

  delete are_sure;
  delete card_number;
  delete card_ccv;
  delete card_date;
  delete save_data;
  delete card_amount;
  delete card_choice;
  delete card_id_choice;
  delete capacity;

  delete chosen_product;

  if (ingredients  && current ){
    for (int i = 0; i < *current; i++) {
    delete ingredients[i];
    }
    delete[] ingredients;
}


  delete current;
  delete order_amount;
  delete chosen_price;
  delete checked_balance;
  delete customer_service_choice;
  delete change_data_choice;
  delete new_address;
  delete new_phone;
  delete meal_answer;
  delete meal_score;
  delete customer_rate;
  delete total_rate;
  delete promo_code;
  delete last_price;
  delete taken_balance;
  delete found_activity;
}

