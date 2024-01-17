#include <string>
#include "information.h"

bool parseArguments(int argc, std::string argv[], Arguments &args) {
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-t" || arg == "--token") {
            if (i + 1 < argc) {
                args.token = argv[++i];
            } else {
                std::cerr << "Error: Missing value for token option" << std::endl;
                return false;
            }
        } else if (arg == "-m" || arg == "--my-username") {
            if (i + 1 < argc) {
                args.myUsername = argv[++i];
            } else {
                std::cerr << "Error: Missing value for my-username option" << std::endl;
                return false;
            }
        } else if (arg == "-u" || arg == "--user-target") {
            if (i + 1 < argc) {
                args.userTarget = argv[++i];
            } else {
                std::cerr << "Error: Missing value for user-target option" << std::endl;
                return false;
            }
        }
    }
    return true;
}
