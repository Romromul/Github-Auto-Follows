#include <iostream>
#include <string>
#include "Header File/Information Input.h"
#include "Header File/Sieve Information.h"
#include "Header File/Base64.h"
#include "Header File/HTTP Request.h"

#define Information_Size 6

using namespace std;

int main(void) {
    User_Information User;
    string Information[Information_Size];
    Information_Input(Information_Size, Information);
    Sieve_Information(Information_Size, Information, User);
    string HEADER = base64_encode(User.UserName + ":" + User.Token);
    string URL = "https://api.github.com/user";
    cout << HTTP_Request_GET(URL, HEADER);
    return 0;
}