#ifndef CUSTOMER_DATA_H
#define CUSTOMER_DATA_H
#include <string>

class CustomerData {
  public:

    static std::string meal[7];
    int* meal_answer;
    int* meal_score;


    std::string* username;
    std::string* password;
    std::string* address;
    std::string* phone;

    int* customer_id;

    int* restaurant_chocie;
    std::string* choosen_restaurant;
    int* showen_restaurant_amount;
    int* menu_choice;
    int* order_choice;
    int* product_amount;

    double* balance;
    double* extra_balance;
    char* are_sure;
    double* total_balance;
    double* checked_balance;
    double* taken_balance;

    std::string* card_number;
    std::string* card_ccv;
    std::string* card_date;
    char* save_data;

    int* card_amount;
    char* card_choice;
    int* card_id_choice;

    int* capacity ;
    std::string** ingredients;
    int* current;

    std::string* chosen_product;
    int* order_amount;
    double* chosen_price;

    int* customer_service_choice;
    int* change_data_choice;
    std::string* new_address;
    std::string* new_phone;
    int* customer_rate;
    int* total_rate;
    std::string* promo_code ;
    double* last_price;
    std::string* found_activity;




    CustomerData();
    ~CustomerData();
};

#endif