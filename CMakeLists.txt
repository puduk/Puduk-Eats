cmake_minimum_required(VERSION 3.10)
project(Puduk_Eats)

set(CMAKE_CXX_STANDARD 20)

add_executable(Puduk_Eats
        main.cpp

        first/first_data.cpp
        first/first_page.cpp
        first/restaurant_forget.cpp
        first/user_forget.cpp

        customer/change_data.cpp
        customer/choose_restaurant.cpp
        customer/customer_data.cpp
        customer/customer_menu.cpp
        customer/customer_service.cpp
        customer/order.cpp
        customer/order_history.cpp
        customer/promo_code.cpp
        customer/restaurant_condition.cpp
        customer/suggest_me.cpp
        customer/top_up.cpp
        customer/user_create_account.cpp
        customer/user_quit.cpp
        customer/user_sign_in.cpp

        restaurant/active.cpp
        restaurant/add.cpp
        restaurant/add_stock.cpp
        restaurant/create_account.cpp
        restaurant/create_promo_code.cpp
        restaurant/first_add.cpp
        restaurant/first_stock.cpp
        restaurant/quit.cpp
        restaurant/remove.cpp
        restaurant/restaurant_data.cpp
        restaurant/restaurant_menu.cpp
        restaurant/sign_in.cpp
        restaurant/stock.cpp
        restaurant/stock_update.cpp
        restaurant/update_porsion.cpp
        restaurant/update_price.cpp
)
