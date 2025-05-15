#include "first_page.hpp"
#include <iostream>

void first_page(FirstData& f){

  while(true){
    std::cout << "------------------------------------" << '\n';
    std::cout << "1 :: for user sign in." << '\n';
    std::cout << "2 :: for restaurant sign in ." << '\n';
    std::cout << "3 :: for create user account." << '\n';
    std::cout << "4 :: for create restaurant account." << '\n';
    std::cout << "5 :: for user password forget." << '\n';
    std::cout << "6 :: for restaurant password forget." << '\n';
    std::cout << "------------------------------------" << '\n';
    std::cout << "Your choice: ";
    std::cin >> *f.first_page_choice;

    if(std::cin.fail()){
      std::cout << "Please enter a number.";
      return;
    }

    switch(*f.first_page_choice){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      default:
        std::cout << "Invalid choice." << '\n';
    }
  }
}
