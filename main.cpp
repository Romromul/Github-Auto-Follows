#include <iostream>
#include <string>
#include "information.h"

#define argc_size 6

int main() {
    Arguments args;
    int argc=argc_size;
    std::string argv[argc_size];
    for (int i=0;i<argc;i++){
        std::cin >> argv[i];
    }
    if (parseArguments(argc, argv, args)) {
        std::cout << args.token << "\n" << args.myUsername << "\n" << args.userTarget << std::endl;
    } else {
        std::cerr << "Error parsing command-line arguments." << std::endl;
        return 1;
    }
    return 0;
}
