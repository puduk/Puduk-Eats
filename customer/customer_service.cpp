#include "customer_service.hpp"
#include <iostream>
#include <fstream>
#include "customer_menu.hpp"

void customer_service(CustomerData &c){


  while(true){
    std::cout << "--------------------------" << '\n';
    std::cout << "0 :: for previous page " << '\n';
    std::cout << "1 :: for restaurant number" << '\n';
    std::cout << "2 :: for restaurant address" << '\n';
    std::cout << "3 :: for technique service" << '\n';
    std::cout << "4 :: for how to Top-up money" << '\n';
    std::cout << "5 :: for service info" << '\n';
    std::cout << "--------------------------" << '\n';
    std::cout << "Your choice: ";
    std::cin >> *c.customer_service_choice;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number" << '\n';
      return;
    }

    switch(*c.customer_service_choice){
      case 0:
        return customer_menu(c);
      case 1:
        number_shower(c);
        break;
      case 2:
        address_shower(c);
        break;
      case 3:
        technique(c);
        break;
      case 4:
        top_up_guide(c);
        break;
      case 5:
        service_info(c);
        break;
      default:
        std::cout << "Invalid choice." << '\n';
    }
  }


}



void number_shower(CustomerData &c){
  std::ifstream number_file("restaurant.txt", std::ios::in);
  if(!number_file.is_open()){
    std::cout << "Unable to load restaurant data. " << '\n';
    return;
  }

  std::string number_line;
  std::string found_number;
  while(std::getline(number_file, number_line)){
    if(number_line.find(std::to_string(*c.restaurant_chocie) + ". Restaurant Number : ") != std::string::npos){
      found_number = number_line.substr(number_line.find(": ") + 2);

    }
  }
  std::cout << "You can contact with your restaurant." << '\n';
  std::cout << "Restaurant number: " << found_number << '\n';


}

void address_shower(CustomerData &c){
  std::ifstream address_file("restaurant.txt", std::ios::in);
  if(!address_file.is_open()){
    std::cout << "Unable to load restaurant data. " << '\n';
    return;
  }

  std::string address_line;
  std::string found_address;
  while(std::getline(address_file, address_line)){
    if(address_line.find(std::to_string(*c.restaurant_chocie) + ". Restaurant Address : ") != std::string::npos){
      found_address = address_line.substr(address_line.find(": ") + 2);
    }
  }

  std::cout << "Restaurant address: " << found_address << '\n';

}

void technique(CustomerData &c){
  std::string technique;

  std::cout << "Please tell us your problem." << '\n';
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::getline(std::cin, technique);

  std::ofstream customer_problems("customer_problems.txt", std::ios::app);
  if(!customer_problems.is_open()){
    std::cout << "Currently technique service is very busy we will contact with you soon. " << '\n';
    return;
  }
  std::ifstream amount_problems("customer_problems.txt", std::ios::in);
  if(!customer_problems.is_open()){
    std::cout << "Currently technique service is very busy we will contact with you soon. " << '\n';
    return;
  }

  std::ifstream personal_file(*c.username + "_data.txt", std::ios::in);
  if(!personal_file.is_open()){
    std::cout << "Currently technique service is very busy we will contact with you soon. " << '\n';
    return;
  }

  std::string amount_line;
  int problem_amount = 0;
  while(std::getline(amount_problems, amount_line)){
    if(amount_line.find("Problem : ") != std::string::npos){
      problem_amount ++;
    }
  }

  std::string phone_line;
  std::string found_number;
  while(std::getline(personal_file, phone_line)){
    if(phone_line.find("Phone Number : ") != std::string::npos){
      found_number = phone_line.substr(phone_line.find(": ") + 2);
    }
  }


  customer_problems <<  problem_amount << ". " << "Problem : " << technique << '\n';

  std::cout << "We take your problem to our service." << '\n';
  std::cout << "Customer Service will contact with you soon. " << '\n';
  std::cout << "From : "  << found_number << '\n';
}

void top_up_guide(CustomerData &c){

  std::cout << "-----------------------" << '\n';
  std::cout << "Click 3 from menu." << '\n' << "And then enter the amount for Top-up" << '\n';
  std::cout << "After you can use already saved card or new card.";
  std::cout << "Under any problem please contact with Customer Service." << '\n';
  std::cout << '\n';



}

void service_info(CustomerData &c){
  // here will be customise in the next uptades when will be able to create new customer serives

  std::cout << "Service Number : 222-22-22" << '\n';
  std::cout << "Service Email : customer_service00@mail.com" << '\n';
  std::cout << "Service Social Media Accounts : @customer_service" << '\n';


}
