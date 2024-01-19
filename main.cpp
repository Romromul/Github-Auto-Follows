#include <iostream>
#include <string>
#include "Information Input.h"
#include "Sieve Information.h"

#define Information_Size 6

using namespace std;

int main(void){
    User_Information User;
    string Information[Information_Size];
    Information_Input(Information_Size, Information);
    parseArguments(Information_Size, Information, User);

    cout << User.Token << "\n" << User.UserName << "\n" << User.UserTarget << "\n";
    return 0;
}