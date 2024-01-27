#include "DitherTest.h"
#include <iostream>
#include <bitset>

int main(){
    StdDither dither(0);

    for (int i = 0; i < 100; i++){
        std::bitset<32> x(dither.cycle());
        std::cout << x << "\n";
    }
    return 0;
}