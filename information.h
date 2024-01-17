#pragma once

#include <iostream>
#include <string>

struct Arguments {
    std::string token;
    std::string myUsername;
    std::string userTarget;
};

bool parseArguments(int argc, std::string argv[], Arguments &args);
