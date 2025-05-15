#include "top_up.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

void top_up(CustomerData& c){

  std::ifstream account_file(*c.username + "_balance.txt" , std::ios::in);
  if(!account_file.is_open()){
    std::cout << "Unable to load balance " << '\n';
    return;
  }
  std::ofstream temp_file ("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Unable to load balance " << '\n';
    return;
  }

  std::cout << "Current Balance in Your Account" << '\n';
  std::string balance_line;
  while(std::getline(account_file, balance_line)){
    if(balance_line.find("Balance : ") != std::string::npos){
      std::cout << balance_line << '\n';
    }
  }

  account_file.close();
  account_file.open(*c.username + "_balance.txt");


  std::string customer_line;
  *c.customer_id = 1;

  bool sure = false;

  while(!sure){

    std::cout << "How much you want to add your account  " << '\n';
    std::cin >> *c.extra_balance;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number " ;
      return;
    }
    if(*c.extra_balance > 100){
      std::cout << "You want to add " << *c.extra_balance << " are you sure ::  (Y - N)";
      std::cin >> *c.are_sure;
      *c.are_sure = tolower(*c.are_sure);

      if(*c.are_sure == 'y'){
        sure = true;
      }
    }else if (*c.extra_balance <= 0){
      std::cout << "You can not add extra 0 or negatif amount." << '\n';
      return;
    }else {
      std::cout << "Top-up Balance set to : "  << *c.extra_balance << '\n';
      sure = true;
    }

  }



  card_save(c);


  total_balance_calculator(c);


  std::string account_line;
  while(std::getline(account_file, account_line)){

    if(account_line.find("Balance : ") != std::string::npos){
      temp_file << *c.customer_id << ". " << "Balance : " << *c.total_balance << '\n';
    }else{
      temp_file << account_line << '\n';
    }
  }


  account_file.close();
  temp_file.close();

  std::string filename = *c.username + "_balance.txt";
  std::remove(filename.c_str());
  std::rename("temp.txt" , filename.c_str());

  std::cout << "You added " << *c.extra_balance << " to your balance." <<'\n';



}


void total_balance_calculator(CustomerData& c){

  std::ifstream last_file(*c.username + "_balance.txt" , std::ios::in);
  if(!last_file.is_open()) {
    std::cout << "Currently this service not active" << '\n';
    return;
  }

  std::string last_line;


  while (std::getline(last_file,last_line)) {
    if(last_line.find("Balance : ") != std::string::npos) {
      std::string found_balance = last_line.substr(last_line.find(": ") + 2);
      *c.taken_balance += std::stod(found_balance);
    }
  }



  *c.total_balance = *c.taken_balance + *c.extra_balance;

}

void card_save(CustomerData& c){

  std::ofstream card_file(*c.username + "_cards.txt" , std::ios::app);
  if(!card_file.is_open()){
    std::cout << "Unable to load your cards " << '\n';
    return;
  }

  std::ifstream amount_file(*c.username + "_cards.txt" , std::ios::in);
  if(!amount_file.is_open()){
    std::cout << "Unable to load your cards " << '\n';
    return;
  }

  if(amount_file.peek() == std::ifstream::traits_type::eof()){
    std::cout << "You dont have any saved cards." << '\n';
    new_card_adder(c);
  }


  std::string amount_line;
  while(std::getline(amount_file, amount_line)){
    if(amount_line.find("Card Number : ") != std::string::npos){
      (*c.card_amount)++;
    }
  }

  amount_file.close();
  amount_file.open(*c.username + "_cards.txt" , std::ios::in);

  std::cout << "Current Saved Cards." << '\n';

  std::string card_line;
  while(std::getline(amount_file, card_line)){
    if(card_line.find("Card Number : ") != std::string::npos){
      std::cout << card_line << '\n';
    }
  }
  std::cout << "Would you like to use saved card :: (Y - N)" ;
  std::cin >> *c.card_choice;

  *c.card_choice = tolower(*c.card_choice);
  bool new_card = false;

  amount_file.close();

  if(*c.card_choice == 'y'){
    std::cout << "Which card :" << '\n';
    std::cin >> *c.card_id_choice;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number " ;
      return;
    }
    if(*c.card_id_choice > *c.card_amount){
      std::cout << "Opps! You dont have that card." << '\n';
      new_card = true;
    }else{
      std::cout << "Card choosen :: " << *c.card_id_choice << '\n';
    }
  }
  if(*c.card_choice == 'n'){
    new_card = true;
  }


  if(new_card){
    new_card_adder(c);
  }
}

void new_card_adder(CustomerData& c){

  std::ofstream card_file(*c.username + "_cards.txt" , std::ios::app);
  if(!card_file.is_open()){
    std::cout << "Unable to load your cards " << '\n';
    return;
  }

  std::cout << "Please enter your new card number : " << '\n';
    std::cin >> *c.card_number;
    std::cout << "Please enter security number : " << '\n';
    std::cin >> *c.card_ccv;
    std::cout << "Please enter your card date : " << '\n';
    std::cin >> *c.card_date;

    std::cout << "------------" << '\n';
    std::cout << "Do you want to save your card data :: (Y - N)" ;
    std::cin >> *c.save_data;


    *c.save_data = tolower(*c.save_data);

    if(*c.save_data == 'y'){
      card_file << *c.card_amount << ". " << "Card Number : " << *c.card_number << '\n';
      card_file << *c.card_amount << ". " << "Security Number : " << *c.card_ccv << '\n';
      card_file << *c.card_amount << ". " << "Card Date : " << *c.card_date << '\n';
    }else {
      std::cout << "Card not saved." << '\n';
    }



}
