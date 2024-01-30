cmake_minimum_required(VERSION 3.27)
project(Github_Auto_Follows)

set(CMAKE_CXX_STANDARD 23)

add_executable(Github_Auto_Follows
        "main.cpp"
        "Sieve Information.cpp"
        "../include/Sieve Information.h"
        "../include/Information Input.h"
        "Information Input.cpp"
        "../include/Base64.h"
        "Base64.cpp"
        "HTTP Request.cpp"
        "../include/HTTP Request.h"
        "../include/User URL.h"
)