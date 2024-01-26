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
    string User_URL = "https://api.github.com/user";
    string User_Target_Followers_URL = "https://api.github.com/users/" + User.UserTarget + "/followers";
    string User_Following_URL = "https://api.github.com/user/following/";
    string User_Page_Request_Str = HTTP_Request_GET(User_URL, HEADER);

    if (User_Page_Request_Str.length() < 1000) {
        cout << "ERROR";
    } else {
        cout << "Connecting OK!";

    }
    return 0;
}