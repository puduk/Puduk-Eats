#ifndef RESTAURANT_DATA_H
#define RESTAURANT_DATA_H
#include <iostream>

class RestaurantData{
public:

    std::string* restaurant_name;
    std::string* restaurant_password;
    std::string* restaurant_address;
    std::string* restaurant_phone_number;

    int* restaurant_amount;

    int* restaurant_menu_choice;

    std::string* product_name;
    std::string* alergy_test;
    double* product_price;
    double* updated_price;
    int* calories;
    double* product_porsion;
    double* updated_porsion;


    int* product_id;

    int* remove_choice;
    int* update_choice;
    int* update_price_choice;

    std::string* promo_code;
    double* promo_price;
    int* promo_id;

    int* needed_item;
    char* are_sure;

    std::string* item_name;
    int* item_amount;
    int* item_id;

    int* stock_choice;
    int* updated_stock;

    int* active_choice;

    int* restaurant_rate;
    int* total_rate;

    std::string* found_product;






    RestaurantData();
    ~RestaurantData();



};




#endif