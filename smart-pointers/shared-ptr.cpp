#include <memory>
#include <vector>
#include <iostream>

class MyClass
{
public:
    std::vector<int> vec;
};

void printCount(const std::shared_ptr<MyClass> &ptr)
{
    std::cout << "Current use count: " << ptr.use_count() << std::endl;
}

int main()
{
    auto sharedPtr = std::make_shared<MyClass>();
    sharedPtr->vec.push_back(0);
    printCount(sharedPtr);
    auto shared2 = sharedPtr; // copy assignment
    printCount(sharedPtr);
    auto shared3(shared2); // copy constructor
    printCount(sharedPtr);

    // undefined behaviour: shared pointer will still be created but refcount won't increment
    // when exiting scope, delete will be called on freed memory.

    // auto shared4 = std::shared_ptr<MyClass>(sharedPtr.get());
    return 0;
}