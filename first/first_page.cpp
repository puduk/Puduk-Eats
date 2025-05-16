#include "first_page.hpp"
#include <iostream>
#include "../restaurant/create_account.hpp"
#include "../restaurant/sign_in.hpp"
#include "../customer/user_create_account.hpp"
#include "../customer/user_sign_in.hpp"
#include "../restaurant/restaurant_data.hpp"
#include "../customer/customer_data.hpp"
#include "restaurant_forget.hpp"
#include "user_forget.hpp"


void first_page(FirstData& f , RestaurantData& r , CustomerData& c) {

  while(true){
    std::cout << "------------------------------------" << '\n';
    std::cout << "1 :: for user sign in." << '\n';
    std::cout << "2 :: for restaurant sign in ." << '\n';
    std::cout << "3 :: for create user account." << '\n';
    std::cout << "4 :: for create restaurant account." << '\n';
    std::cout << "5 :: for user password forget." << '\n';
    std::cout << "6 :: for restaurant password forget." << '\n';
    std::cout << "7 :: for quit..." << '\n';
    std::cout << "------------------------------------" << '\n';
    std::cout << "Your choice: ";
    std::cin >> *f.first_page_choice;

    if(std::cin.fail()){
      std::cout << "Please enter a number.";
      return first_page(f , r , c);
    }

    switch(*f.first_page_choice){
      case 1:
        user_sign_in(c);
      break;
      case 2:
        sign_in(r);
      break;
      case 3:
        user_create_account(c);
      break;
      case 4:
        restaurant_create_account(r);
      break;
      case 5:
        user_forget(f);
      break;
      case 6:
        restaurant_forget(f);
      break;
      case 7:
        std::cout << "Goodbye!" << '\n';
      exit(0);
      default:
        std::cout << "Invalid choice." << '\n';
    }
  }
}
