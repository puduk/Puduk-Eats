#include "suggest_me.hpp"
#include <iostream>

void suggest_me(CustomerData &c){

  std::cout << "Welcome to the Suggest Me Test!" << '\n';
  std::cout << "-------------------------------" << '\n';


    for(int i = 0 ; i < 7 ; i ++){
      std::cout << CustomerData::meal[i] << '\n';
      std::cin >> *c.meal_answer;
      while(std::cin.fail() || *c.meal_answer < 0 || *c.meal_answer > 5){
        std::cin.clear();
        std::cin.ignore(1000 , '\n');
        std::cout << "Please enter between 1 and 5" << '\n';
        std::cin >> *c.meal_answer;
      }
      *c.meal_score += *c.meal_answer;
    }



  if (*c.meal_score <= 10)
    std::cout << "Our suggestion: Salad and lemon water 🥗🍋";
  else if (*c.meal_score <= 15)
    std::cout << "Our suggestion: Margherita pizza and cola 🍕🥤";
  else if (*c.meal_score <= 20)
    std::cout << "Our suggestion: Cheeseburger and fries 🍔🍟";
  else if (*c.meal_score <= 25)
    std::cout << "Our suggestion: Sushi and green tea 🍣🍵";
  else if (*c.meal_score <= 30)
    std::cout << "Our suggestion: Chicken burrito and iced soda 🌯🥤";
  else
    std::cout << "Our suggestion: Double beef burger with extra fries and cold cola 🔥🍔🍟🥤";
}

