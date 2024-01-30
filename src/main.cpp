#include <iostream>
#include <string>
#include "../Header File/Information Input.h"
#include "../Header File/Sieve Information.h"
#include "../Header File/Base64.h"
#include "../Header File/HTTP Request.h"
#include "../Header File/User URL.h"
#define Information_Size 6

using namespace std;

int main(void) {
    User_Information User;
    User_URL User_URL;
    string Information[Information_Size];
    Information_Input(Information_Size, Information);
    Sieve_Information(Information_Size, Information, User);

    string HEADER = base64_encode(User.UserName + ":" + User.Token);
    string User_Page_Request_Str = HTTP_Request_GET(User_URL.User_API_URL, HEADER);

    if (User_Page_Request_Str.length() < 1000) {
        cout << "ERROR";
    } else {
        cout << "Connecting OK!";
    }
    return 0;
}