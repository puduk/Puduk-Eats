#include "restaurant_menu.hpp"
#include <iostream>
#include "update_price.hpp"
#include "update_porsion.hpp"
#include "stock_update.hpp"
#include "stock.hpp"
#include "quit.hpp"
#include "remove.hpp"
#include "active.hpp"
#include "add.hpp"
#include "create_promo_code.hpp"

void restaurant_menu(RestaurantData& r){

  while(true){
    std::cout << "-------------------------" << '\n';
    std::cout << "0 :: for quit" << '\n';
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
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      std::cout << "Please enter a number." << '\n';
      return;
    }

    switch(*r.restaurant_menu_choice){
      case 0:
        quit(r);
      exit(0);
      case 1:
        add(r);
      break;
      case 2:
        remove(r);
      break;
      case 3:
        update_porsion(r);
      break;
      case 4:
        update_price(r);
      break;
      case 5:
        create_promo_code(r);
      break;
      case 6:
        stock(r);
      break;
      case 7:
        stock_update(r);
      break;
      case 8:
        close(r);
      break;
      case 9:
        open(r);
      break;
      default:
        std::cout << "Invalid choice." << '\n';

    }
  }
}









