#include <iostream>
using namespace std;

auto pow_n(const auto &v, int n)
{
    auto product = decltype(v){1};
    // decltype(v) product{1};  error, because decltype(v) gives a 
    // const reference that cannot be assigned

    //alternatively, use:
    // typename std::remove_cvref<decltype(v)>::type product{1};
    for (int i = 0; i < n; i++)
    {
        product *= v;
    }
    return product;
}

int main(){
    auto res = pow_n(5, 5);
    cout << res << "\n";
    return 0;
}