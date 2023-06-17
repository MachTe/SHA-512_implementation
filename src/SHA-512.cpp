#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <bitset>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <cmath>
#include <string.h>


std::string SHA512(std::istream &inputStream){
    uint64_t M[16];
    uint64_t N[2];
    memset(N, 0, 16);
    std::string myHash = "";

    int i = 0;
    bool messageNotExhausted = true;
    bool oneIncluded = false;
    while (messageNotExhausted){
        memset(M, 0, 128);
        for (int k = 0; k < 16; k++){
            i = 0;
            while (i < 8){
                if (inputStream.read((char*) &M + (7 - i + k*8), 1)){
                    N[1] += 8;
                    if(N[1] == 0){
                        N[0] += 1;
                    }
                    i++;
                }
                else {
                    if(!oneIncluded){
                        uint64_t singleBit = pow(2, 63-8*i);
                        M[k] += singleBit;
                        oneIncluded = true;
                    }
                    i = 8;
                    if (k < 14){
                        M[14] += N[0];
                        M[15] += N[1];
                        messageNotExhausted = false;
                        k = 16;
                    }
                    else{
                        k = 16;
                    }
                }
            }
        }
        //DO STUFF
    }
    return myHash;
}


int main(){
    //text test
    std::stringstream ss;
    std::string a = "test text";
    ss << a;
    //file test
    std::ifstream myfile;
    myfile.open ("test_file.gif", std::ios::in | std::ios::app | std::ios::binary);

    std::string hashed = SHA512(myfile);
    std::cout << hashed;
    return 0; 
}