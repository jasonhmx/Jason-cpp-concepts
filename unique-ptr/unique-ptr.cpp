#include <memory>
#include <vector>
#include <iostream>
using namespace std;
class A{
public:
    vector<int> vec;
};

void func(A& ref, unique_ptr<A>& ptr){
    ptr = make_unique<A>(ref);
}

int main(){
    unique_ptr<A> a = make_unique<A>();
    a->vec.push_back(0);

    // error, cannot call make_unique on existing raw pointer; can only do new
    unique_ptr<A> b = make_unique<A>(a.get());
    cout << a->vec[0] << endl;
    cout << b->vec[0] << endl; 
}