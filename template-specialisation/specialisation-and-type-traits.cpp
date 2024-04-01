#include <type_traits>
#include <iostream>
#include <string>

/*
This file aims to show a possible implementation of c++ type traits
*/
struct MyType
{
    void message()
    {
        std::cout << "Congrats I'm your type!" << "\n";
    }
};

template <typename T>
struct is_MyType
{
    static const bool value = false;
};

// full/explicit specialisation
template <>
struct is_MyType<MyType>
{
    static const bool value = true;
};

template <typename T>
struct is_pointer
{
    static const bool value = false;
};

// partial specialisation of is_pointer class
template <typename T>
struct is_pointer<T *>
{
    static const bool value = true;
};

template <typename A, typename B>
struct Thing
{
    static const bool value = false;
};

template <typename A>
struct Thing<A, int>
{
    static const bool value = true;
};



int main()
{
    if constexpr (is_MyType<MyType>::value)
    {
        std::cout << "Hooray this is your type!" << "\n";
    }
    else
    {
        std::cout << "This ain cho type bruh." << "\n";
    }

    if constexpr (is_pointer<int>::value){
        std::cout << "Hooray this is a pointer!" << "\n";
    } else {
        std::cout << "This ain't a pointer bruh" << "\n";
    }

    Thing<float, int> thing1;
    Thing<float, float> thing2;
    std::cout << "Is thing1's B an int? " << thing1.value << "\n";
    std::cout << "Is thing2's B an int? " << thing2.value << "\n";
    return 0;
}
