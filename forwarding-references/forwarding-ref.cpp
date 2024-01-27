#include <iostream>
#include <vector>

class Foo{
private:
    int i;
    float f;
    bool b;
    std::vector<int> vec;

public:
    Foo(int& newi, float& newf, bool& newb, std::vector<int>& newvec) : 
        i(newi),
        f(newf),
        b(newb),
        vec(newvec)
    {}
};

class Bar{
private:
    std::vector<Foo> fooVec;

public:
    template<typename ... Args>
    void addFoo(Args&& ... args){
        fooVec.emplace_back(std::forward<Args>(args) ...);
    }
};


int main(){
    return 0;
}