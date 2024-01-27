#include <iostream>

template<typename Derived>
class Base{
public:
    void interface(){
        static_cast<Derived*>(this)->impl();
    }

    void impl(){
        std::cout << "Default" << "\n";
    }
};

class Derived1 : public Base<Derived1> {
public:
    void impl(){
        std::cout << "Derived1" << "\n";
    }
};

class DerivedDef : public Base<DerivedDef> {

};

template<typename T>
void crtpPrint(Base<T>& t){
    t.interface();
}