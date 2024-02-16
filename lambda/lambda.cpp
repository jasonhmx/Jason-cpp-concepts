#include <iostream>

auto lambda = [](int a, int b)
{ return a < b; };

auto templated_lambda = []<class T>(const T &v, int n)
{
    auto product = T{1};
    for (int i = 0; i < n; i++)
    {
        product *= v;
    }
    return product;
}; // template after capture clause, avoids using decltype inside

int main()
{
    std::cout << lambda(5, 6) << std::endl;
    return 0;
}