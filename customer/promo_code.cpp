#include "promo_code.hpp"
#include <iostream>
#include <fstream>


void promo_code(CustomerData& c){

  std::ofstream temp_file("temp.txt" , std::ios::out);
  if (!temp_file.is_open()){
    std::cout << "Can not activate promo code1." ;
    return;
  }

  std::ifstream balance_file(*c.username + "_balance.txt" , std::ios::in);
  if (!balance_file.is_open()){
    std::cout << "Can not activate promo code2." ;
    return;
  }

  std::ifstream check_file(*c.choosen_restaurant + "_promo.txt" , std::ios::in);
  if (!check_file.is_open()){
    std::cout << "Can not activate promo code3." ;
    return;
  }

  std::ofstream activate_file(*c.username + "_promo.txt" , std::ios::app);
  if (!activate_file.is_open()){
    std::cout << "Can not activate promo code4." ;
    return;
  }

  std::ifstream customer_file(*c.username + "_promo.txt" , std::ios::in);
  if (!customer_file.is_open()){
    std::cout << "Can not activate promo code5." ;
    return;
  }

  std::cout << "-------------------------" << '\n';
  std::cout << "Enter Your Promo Code : " ;
  std::cin >> *c.promo_code;

  std::string customer_line;
  std::string found_code;
  bool used = false;

  while(std::getline(customer_file, customer_line)){
    if(customer_line.find("Promo Code : ") != std::string::npos){
      found_code = customer_line.substr(customer_line.find(": ") + 2);
      if(found_code == *c.promo_code ){
        used = true;
      }
    }
  }
  if(used){
    std::cout << "Promo code already used. " << '\n';
    return;
  }

  std::string check_line;
  std::string codes;
  std::string code_id;
  bool exist = false;

  while(std::getline(check_file, check_line)){
    if(check_line.find("Promo Code : ") != std::string::npos){
      codes = check_line.substr(check_line.find(": ") + 2);
      if(codes == *c.promo_code ){
        code_id = check_line.substr(0, check_line.find("."));
        exist = true;
      }
    }
  }
  if(!exist){
    std::cout << "Promo code does not exist. " << '\n';
    return;
  }

  std::string amount;
  double cost;

  check_file.close();
  check_file.open(*c.choosen_restaurant + "_promo.txt" , std::ios::in);

  std::string promo_line;


  while(std::getline(check_file, promo_line)){
    if(promo_line.find(code_id + ". Promo Price : ") != std::string::npos){
      amount = promo_line.substr(promo_line.find(": ") + 2);
      cost = stod(amount);

    }
  }


  std::string balance_line;
  std::string balance;
  double balance_price;

  while(std::getline(balance_file, balance_line)){
    if(balance_line.find("Balance : ") != std::string::npos){
      balance = balance_line.substr(balance_line.find(": ") + 2);
      balance_price = stod(balance);
    }
  }

  balance_file.close();
  balance_file.open(*c.username + "_balance.txt" , std::ios::in);

  std::string id_line;
  std::string found_id;
  while(std::getline(balance_file, id_line)){
    if(id_line.find("Balance : ") != std::string::npos){
      found_id = id_line.substr(0 , id_line.find(".") );
    }
  }


  balance_file.close();
  balance_file.open(*c.username + "_balance.txt" , std::ios::in);

  *c.last_price = balance_price + cost;

  std::string final_line;

  while(std::getline(balance_file, final_line)){
    if(final_line.find(found_id + ". Balance : ") != std::string::npos){
      temp_file << found_id << ". " << "Balance : " << *c.last_price << '\n';
      temp_file.flush();
    }else {
      temp_file << final_line << '\n';
      temp_file.flush();
    }
  }

  std::string filename = *c.username + "_balance.txt" ;
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());



  activate_file << "Promo Code : " << *c.promo_code << '\n';
  activate_file.flush();
  activate_file.close();


  std::cout << "Promo price " << cost << " successfully added your balance. " << '\n';

}

