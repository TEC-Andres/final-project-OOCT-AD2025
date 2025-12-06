#include "preamble.h"

/**
 * This function collects client data: name, ID, and email.
 * It returns the data as a tuple for easier management in main.
 */
std::tuple<std::string, int, std::string> Preamble::clientData() {
    std::string custName, custEmail, custIdStr;
    int custId;
    std::cout << "Enter your name: ";
    std::getline(std::cin, custName);
    std::cout << "Enter your ID: ";
    std::getline(std::cin, custIdStr);
    custId = (custIdStr.empty() ? 0 : (std::stoi(custIdStr))); // if empty, it sets it to 0
    std::cout << "Enter your email: ";
    std::getline(std::cin, custEmail);
    
    std::cout << "------------------------" << std::endl;
    Preamble::clear();
    return std::make_tuple(custName, custId, custEmail);
}

/**
 * checks whether the client data matches with what there hardcoded on the program
 */
bool Preamble::checkIfClientDataExists(const std::string& custName) {
    return !custName.empty();
}

/** 
 *  Capitalizes the first letter of each word in the name.
 */
std::string Preamble::capitalizeName(const std::string& name) {
    std::string capitalized = name;
    bool newWord = true;
    for (size_t i = 0; i < capitalized.length(); ++i) {
        if (std::isspace(capitalized[i])) {
            newWord = true;
        } else if (newWord) {
            capitalized[i] = std::toupper(capitalized[i]);
            newWord = false;
        } else {
            capitalized[i] = std::tolower(capitalized[i]);
        }
    }
    return capitalized;
}

/** 
 * Clears the console screen.
 */
void Preamble::clear() {
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}