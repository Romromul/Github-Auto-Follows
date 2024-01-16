#include <iostream>
#include <string>

using namespace std;

struct Arguments {
    string token;
    string myUsername;
    string userTarget;
    string file;
    string maxFollowers;
};

int main(/*int argc, char* argv[]*/) {
    Arguments args;
    int argc = 10;
    string argv[] = {"-t", "A", "-m", "dongwook", "-u", "dongwookkim3", "-f", "file.json", "-mf", "100K"};
    for (int i = 0; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "-t" || arg == "--token") {
            if (i + 1 < argc) {
                args.token = argv[++i];
            } else {
                cerr << "Error: Missing value for token option" << endl;
                return 1;
            }
        } else if (arg == "-m" || arg == "--my-username") {
            if (i + 1 < argc) {
                args.myUsername = argv[++i];
            } else {
                cerr << "Error: Missing value for my-username option" << endl;
                return 1;
            }
        } else if (arg == "-u" || arg == "--user-target") {
            if (i + 1 < argc) {
                args.userTarget = argv[++i];
            } else {
                cerr << "Error: Missing value for user-target option" << endl;
                return 1;
            }
        } else if (arg == "-f" || arg == "--file") {
            if (i + 1 < argc) {
                args.file = argv[++i];
            } else {
                cerr << "Error: Missing value for file option" << endl;
                return 1;
            }
        } else if (arg == "-mf" || arg == "--max-followers") {
            if (i + 1 < argc) {
                args.maxFollowers = argv[++i];
            } else {
                cerr << "Error: Missing value for max-followers option" << endl;
                return 1;
            }
        }
    }
    cout << args.token << "\n" << args.myUsername << "\n" << args.userTarget << "\n" << args.file << "\n" << args.maxFollowers;
    return 0;
}
