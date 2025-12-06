#include "preamble.h"

std::tuple<std::string, std::string> Preamble::clientData() {
    std::string custName, custEmail;
    std::cout << "Enter your name: ";
    std::getline(std::cin, custName);
    std::cout << "Enter your email: ";
    std::getline(std::cin, custEmail);
    std::cout << "------------------------" << std::endl;
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
    return std::make_tuple(custName, custEmail);
}