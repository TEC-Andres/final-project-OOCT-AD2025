#ifndef PREAMBLE_H
#define PREAMBLE_H

#include <string>
#include <iostream>
#include <limits>
#include <tuple>

class Preamble {
public:
    std::tuple<std::string, int, std::string> clientData();
    std::string capitalizeName(const std::string& name);
    bool checkIfClientDataExists(const std::string& custName);
    void clear();
};

#endif // PREAMBLE_H