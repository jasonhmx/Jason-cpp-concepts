#include <memory>
#include <vector>
#include <iostream>
using namespace std;
class A
{
public:
    vector<int> vec;
};

int main()
{
    auto a = make_unique<A>();
    a->vec.push_back(0);

    // this line will compile but leads to undefined beahviour when delete is called later
    auto b = std::unique_ptr<A>(a.get());
    cout << a->vec[0] << endl;
    cout << b->vec[0] << endl;
}