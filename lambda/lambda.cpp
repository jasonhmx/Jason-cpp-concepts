#include <iostream>


auto lambda = [](int a, int b) {return a < b;};

int main() {
    std::cout << lambda(5, 6) << std::endl;
}