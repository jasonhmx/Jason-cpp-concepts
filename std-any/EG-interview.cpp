/*
how would you go about implementing std::any?
this was the interview qn I got at Engineers Gate which I failed terribly at
I've tried to recover what they walked me through. It's probably not
how std implemented theirs, but this approach using templated constructor
and dynamic cast is quite interesting nontheless.
*/


#include <memory>
#include <optional>
#include <iostream>
#include <string>

class Parent
{
    // we want this parent class to be the parent of all classes
public:
    virtual ~Parent() {} // Adding a virtual destructor. Needed for dynamic casting to work
    // since it needs to be polymorphic, with at least one virtual function
};

template <typename ValueType>
class Child : public Parent
{
public:
    Child(ValueType v) : val(v) {}
    ValueType val;
};

class Any
{
    // class itself cannot be templated to contain another type
    // since we need to contain any type we want

    // constructor needs to be templated to actually store the class
    // we need a pointer that points to a class that everything inherits from
    // then use dynamic cast to check what it actually is.
public:
    template <typename ValueType>
    Any(ValueType v)
    {
        anyPtr = std::make_unique<Child<ValueType>>(v);
    }
    std::unique_ptr<Parent> anyPtr{};
};

template <typename dst>
std::optional<dst> cast(Any &a)
{
    auto res = dynamic_cast<Child<dst>*>(a.anyPtr.get());
    if (res)
    {
        std::cout << "casted successfully" <<'\n';
        return res->val;
    }
    else
    {
        std::cout << "casted unsuccessfully" <<'\n';
        return std::nullopt;
    }
}

int main(){
    Any a{11};
    Any b{15.0};
    Any c{std::string{"Look at that!"}};
    cast<int>(a);
    cast<float>(a);
    cast<double>(b);
    cast<int>(b);
    cast<std::string>(c);
    cast<int>(c);
    return 0;
}