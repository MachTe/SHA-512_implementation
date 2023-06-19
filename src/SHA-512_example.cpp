#include "SHA-512.h"
#include <iostream>

int main(){
    //text test
    std::stringstream ss;
    std::string a = "abc";
    ss << a;
    std::cout << SHA512(ss) << std::endl;

    //file test
    std::ifstream myfile;
    myfile.open ("test_file.gif", std::ios::in | std::ios::app | std::ios::binary);
    std::cout << SHA512(myfile) << std::endl;

    return 0; 
}