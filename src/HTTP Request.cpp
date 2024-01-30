#include <string>
#include <cstdio>

using namespace std;

string HTTP_Request_GET(string URL, string GET_Code) {
    string Result;
    string command = "curl -s \"" + URL + "\" -H \"Authorization: Basic " + GET_Code + "\"";
    FILE *pipe = popen(command.c_str(), "r");
    char buffer[128];
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL) {
            Result += buffer;
        }
    }
    pclose(pipe);
    return Result;
}