#include <iostream>
#include <string>
#include "Header File/Information Input.h"
#include "Header File/Sieve Information.h"
#include "Header File/Base64.h"

#define Information_Size 6

using namespace std;

int main(void) {
    User_Information User;
    string Information[Information_Size];
    Information_Input(Information_Size, Information);
    Sieve_Information(Information_Size, Information, User);

    cout << User.Token << "\n" << User.UserName << "\n" << User.UserTarget << "\n";
    string HEADER = base64_encode(User.UserName + ":" + User.Token);
    cout << HEADER;
    return 0;
}