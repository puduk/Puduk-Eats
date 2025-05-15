#include "order.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

void order(CustomerData &c) {

  std::ifstream restaurant_file(*c.choosen_restaurant + ".txt" , std::ios::in);
  if(!restaurant_file.is_open()){
    std::cout << "Unable to load restaurant menu. " << '\n';
    return;

  }

  std::string amount_line;
  while(std::getline(restaurant_file, amount_line)){
    if(amount_line.find("Product Name : ") != std::string::npos){
      (*c.product_amount)++;
    }
  }

  restaurant_file.close();
  restaurant_file.open(*c.choosen_restaurant + ".txt" , std::ios::in);


  std::ofstream order_file (*c.username + ".txt" , std::ios::app);
  if(!order_file.is_open()){
    std::cout << "Unable to load restaurant menu. " << '\n';
    return;
  }

  std::ifstream order_amount_file(*c.username + ".txt" , std::ios::in);
  if(!order_amount_file.is_open()){
    std::cout << "Unable to load restaurant menu. " << '\n';
    return;
  }

  std::string order_amount_line;
  while(std::getline(order_amount_file, order_amount_line)){
    if(order_amount_line.find("Ordered Before : ") != std::string::npos){
      (*c.order_amount)++;
    }
  }

  std::string line;

  std::cout << "Menu :: " << '\n';
  std::cout << "-------------------------" << '\n';
  while(std::getline(restaurant_file, line)){
    if(line.find("Product Name : ") != std::string::npos) {
      std::cout << line << '\n';
    }else if (line.find("Product Price : ") != std::string::npos) {
      std::cout << line << '\n';
    }
  }
  std::cout << "-------------------------" << '\n';
  std::cout << "Your Choice :: " ;
  std::cin >> *c.order_choice;

// burda menuye geri atti

  if(std::cin.fail()){
    std::cout << "Please enter a valid choice. " << '\n';
    return;
  }
  if(*c.order_choice > *c.product_amount){
    std::cout << "Opps! We dont have that." << '\n';
    return;
  }

  restaurant_file.close();
  restaurant_file.open(*c.choosen_restaurant + ".txt", std::ios::in);

  std::string chosen_line;

  std::string price;

  while(std::getline(restaurant_file, chosen_line)){
    if(chosen_line.find(std::to_string(*c.order_choice) + ". Product Name : ") != std::string::npos) {
      *c.chosen_product = chosen_line.substr(chosen_line.find(": ") + 2);
    }else if (chosen_line.find(std::to_string(*c.order_choice) + ". Product Price : ") != std::string::npos){
      price = chosen_line.substr(chosen_line.find(": ") + 2);
      *c.chosen_price = stod(price);
    }
  }

  std::ifstream balance_file(*c.username + "_balance.txt" , std::ios::in);
  if(!balance_file.is_open()){
    std::cout << "Unable to order. " << '\n';
    return;
  }
  std::string balance_line;
  std::string balance;


  while(std::getline(balance_file, balance_line)){
    if(balance_line.find("Balance : ") != std::string::npos) {
      balance = balance_line.substr(balance_line.find(":") + 2);
      *c.checked_balance = std::stod(balance);

    }
  }

  std::cout << *c.chosen_product << '\n';

  if(*c.checked_balance < *c.chosen_price ){
    std::cout << "Opps! You dont have enough money in your account." << '\n';
    std::cout << "Please Top-up. " <<'\n';
    return;

  }
// no bug
  std::ifstream product_file(*c.chosen_product  + ".txt" , std::ios::in);
  if(!product_file.is_open()){
    std::cout << "Current we having problem with ordering. " << '\n';
    return;
  }

  std::string file_name_check = *c.chosen_product  + ".txt";
  std::cout << "Opened file : " << file_name_check << '\n';

  // opened file Big Mac.txt


  std::string check_line;
  std::string needed_products;


  // while (std::getline(product_file, check_line)) {
  //   if (check_line.find("Product Name : ") != std::string::npos) {
  //     c.ingredients[*c.current] = new std::string(check_line.substr(check_line.find(": ") + 2));
  //     (*c.current)++;
  //
  //     // resize gerekiyorsa
  //     if (*c.current == *c.capacity) {
  //       int new_capacity = *c.capacity * 2;
  //       std::string** temp = new std::string*[new_capacity];
  //
  //       // yeni dizinin başına eski pointer'ları taşı
  //       for (int i = 0; i < *c.current; i++) {
  //         temp[i] = c.ingredients[i];
  //       }
  //
  //       // eski dizi yapısını sil (elemanları değil)
  //       delete[] c.ingredients;
  //       c.ingredients = temp;
  //       *c.capacity = new_capacity;
  //
  //       // yeni yerleri null'a setle (güvenli olsun)
  //       for (int i = *c.current; i < *c.capacity; i++) {
  //         c.ingredients[i] = nullptr;
  //       }
  //     }
  //   }
  // }




  while(std::getline(product_file, check_line)){
    if(check_line.find("Item name : ") != std::string::npos) {

      c.ingredients[*c.current] = new std::string(check_line.substr(check_line.find(": ") + 2));
      (*c.current)++;
    }

    if(*c.current == *c.capacity){
      *c.capacity *= 2;
      std::string** temp = new std::string*[*c.capacity];

      for(int i = 0; i < *c.current; i++){
        temp[i] = c.ingredients[i];
      }
      for (int j = 0; j < *c.current; j++){
        delete c.ingredients[j];
      }
      delete c.ingredients;


      c.ingredients = temp;

    }


  }



  for(int i = 0; i < *c.current; i++) {
    std::cout << *c.ingredients[i] << '\n';
  }

  std::ifstream stock_file(*c.choosen_restaurant + "_stock.txt" , std::ios::in);
  if(!stock_file.is_open()){
    std::cout << "Current we having problem with ordering. " << '\n';
    return;
  }

  std::ofstream temp_file("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Current we having problem with ordering. " << '\n';
    return;
  }


  std::string stock_line;

  std::string stocks;
  int stock_amount ;
  std::string current_id;




  while (std::getline(stock_file, stock_line)){
    bool found = false;

   for(int i = 0; i < *c.current; i++){   // a product may need 4-5 or more items so we need to check all in stocks
     if(stock_line.find(*c.ingredients[i]) != std::string::npos) {
      current_id = stock_line.substr(0, stock_line.find(".") );

      std::string stock_amount_line;

      std::getline(stock_file, stock_amount_line);

      temp_file << stock_line << '\n';
      if(stock_amount_line.find(current_id + ". Item amount : ") != std::string::npos) {
        stocks = stock_amount_line.substr(stock_amount_line.find(": ") + 2);
        stock_amount = std::stoi(stocks);

        if (stock_amount <= 0){
          std::cout << "Canceled!" << '\n';
          std::cout << "Currently Restaurant does not have enough stocks for this delivery!" << '\n';
          return;
        }
        stock_amount--;

        temp_file << current_id << ". Item amount : " << stock_amount << '\n';
      }

      found = true;
      break;

   }
  }
  if(!found){
    temp_file << stock_line << '\n';
  }
  }

  std::string file_name = *c.choosen_restaurant + "_stock.txt";
  std::remove(file_name.c_str());
  std::rename("temp.txt", file_name.c_str());

  std::time_t now = std::time(0);
  std::string current_time = std::ctime(&now);
  current_time.pop_back();



  order_file << *c.order_amount << ". " << "Ordered Before : " << *c.chosen_product << " - [ " << current_time << " ] -"<< '\n';
  std::cout << "You ordered : " << *c.chosen_product << '\n';
  std::cout << "Your order will be delivered in 15-25M" << '\n';

}

// pointer deleted with in array in deconstructor
//

// while(std::getline(product_file, check_line)){
//   if(check_line.find("Product Name : ") != std::string::npos) {
//
//     c.ingredients[*c.current] = new std::string(check_line.substr(check_line.find(": ") + 2));
//     (*c.current)++;
//   }
//
//   if(*c.current == *c.capacity){
//     *c.capacity *= 2;
//     std::string** temp = new std::string*[*c.capacity];
//
//     for(int i = 0; i < *c.current; i++){
//       temp[i] = c.ingredients[i];
//     }
//     for (int j = 0; j < *c.current; j++){
//       delete c.ingredients[j];
//     }
//     delete c.ingredients;
//
//
//     c.ingredients = temp;
//
//   }
//
//
// }