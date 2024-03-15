#include "../header_files/Book.h"
#include "../header_files/Library.h"
#include "../header_files/functions.h"
#include<iostream>
#include<vector>
#include<stdlib.h>


int main(){
    
    const std::string filename = "../app/library.csv";
    Library library_with_no_name(filename);
    std::string password;
    int userType;

    std::cout<< "Welcome! Please select how you want to interact with the system:\n 1. Admin\n 2. Client" << std::endl;

    std::cin>>userType;
    switch (userType)
    {
    case 1:
        std::cout << "admin 'password' is 1234\n";
        std::cout<<"Enter password:\n";
        std::cin>>password;
        if(password == "1234"){
            clearConsole();
            library_with_no_name.adminMenu();
            }
        else
            std::cout<<"Wrong password";
        break;
    case 2:
        clearConsole();
        library_with_no_name.clientMenu();
        break;
    default:
        std::cout << "Invalid option";
        break;
    }
}