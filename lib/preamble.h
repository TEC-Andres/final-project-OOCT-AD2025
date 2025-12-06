#ifndef PREAMBLE_H
#define PREAMBLE_H

#include <string>
#include <iostream>
#include <limits>
#include <tuple>

class Preamble {
public:
    std::tuple<std::string, std::string> clientData();
};

#endif // PREAMBLE_H