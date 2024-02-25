#include <future>
#include <exception>
#include <iostream>

int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error{"Divide by zero exception"};
    }
    return a / b;
}

int main(){
    auto future = std::async(divide, 45, 0);
    try {
        const auto& result = future.get();
        std::cout << "Result: " << result << '\n';
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }
    return 0;
}