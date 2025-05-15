#include "restaurant_menu.hpp"
#include <iostream>

void restaurant_menu(RestaurantData& r){


  while(true){
    std::cout << "-------------------------" << '\n';
    std::cout << "1 :: for add product." << '\n';
    std::cout << "2 :: for delete product." << '\n';
    std::cout << "3 :: for update porsion." << '\n';
    std::cout << "4 :: for update price." << '\n';
    std::cout << "5 :: for create promotion." << '\n';
    std::cout << "6 :: for stock check." << '\n';
    std::cout << "7 :: for stock update." << '\n';
    std::cout << "8 :: for close restaurant." << '\n';
    std::cout << "9 :: for open restaurant." << '\n';
    std::cout << "-------------------------" << '\n';
    std::cin >> *r.restaurant_menu_choice;

    if(std::cin.fail()){
      std::cout << "Please enter a number." << '\n';
      return;
    }

    switch(*r.restaurant_menu_choice){
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
      case 7:
        break;
      case 8:
        break;
      case 9:

      default:
        std::cout << "Invalid choice." << '\n';

    }
  }
}









