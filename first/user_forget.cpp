#include "first_data.hpp"
#include <iostream>
#include <fstream>

void user_forget(FirstData& f){

    std::ifstream check_file("customer.txt" , std::ios::in);
    if(!check_file.is_open()){
        std::cout << "This service currently out of service" << '\n';
        return;
    }

    std::cout << "Username : " ;
    std::cin >> *f.username;

    std::string check_line;
    std::string found_username;
    std::string found_id;
    bool found = false;
    while(std::getline(check_file, check_line)){
        if(check_line.find("Username : ") != std::string::npos){
            found_username = check_line.substr(check_line.find(": ") + 2);
            if(found_username == *f.username ){
                found_id = check_line.substr(0 , check_line.find(".") );
                found = true;
            }
        }
    }
    if(!found){
        std::cout << "This user did not exits." << '\n';
        return;
    }

    check_file.close();
    check_file.open("customer.txt" , std::ios::in);

    std::string final_line;
    std::string show_password;
    while(std::getline(check_file, final_line)){
        if(final_line.find(found_id + ". Password : ") != std::string::npos){
            show_password = final_line.substr(final_line.find(": ") + 2);
        }
    }

    std::cout << "Please Note Your Password : " << show_password << '\n';
}

