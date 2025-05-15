#include "customer_menu.hpp"
#include <iostream>
#include <fstream>
#include "change_data.hpp"
#include "order.hpp"
#include "order_history.hpp"
#include "suggest_me.hpp"
#include "top_up.hpp"
#include "user_quit.hpp"
#include "customer_service.hpp"
#include "promo_code.hpp"



void customer_menu(CustomerData& c){


  while (true) {
    std::cout << "-----------------------------" << '\n';
    std::cout << "1 :: for Order :" << '\n';
    std::cout << "2 :: for Order History :" << '\n';
    std::cout << "3 :: for Top-up Account :" << '\n';
    std::cout << "4 :: for Change Personal Data :" << '\n';
    std::cout << "5 :: for Customer Service :" << '\n';
    std::cout << "6 :: for Suggest Me Meal :" << '\n';
    std::cout << "7 :: for Apply Promo Code : " << '\n';
    std::cout << "8 :: for Quit :" << '\n';
    std::cout << "-----------------------------" << '\n';
    std::cout << "Your choice : ";
    std::cin >> *c.menu_choice;
    if(std::cin.fail()){
      std::cout << "Please enter Number : " ;
      return;
    }

    switch(*c.menu_choice){
      case 1:
        order(c);
      break;
      case 2:
        order_history(c);
      break;
      case 3:
        top_up(c);
      break;
      case 4:
        change_data(c);
      break;
      case 5:
        customer_service(c);
      break;
      case 6:
        suggest_me(c);
      break;
      case 7:
        promo_code(c);
      break;
      case 8:
        user_quit(c);
      exit(0);
      default:
        std::cout << "Invalid Choice." << '\n';
    }


  }





}