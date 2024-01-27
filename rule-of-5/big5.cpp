#include <iostream>

using namespace std;
class A
{
public:
    int field;
    A(int field = 0)
    {
        this->field = field;
        cout << "Constructor"
             << "\n";
    }

    A(const A &other) : field(other.field)
    {
        cout << "Copy constructor"
             << "\n";
    }

    A &operator=(const A &other)
    {
        field = other.field;
        cout << "Copy assignment"
             << "\n";
        return *this;
    }

    A(A &&other)
    {
        cout << "Move constructor"
             << "\n";
        field = other.field; // in this case the field doesn't need to be moved since it's an int
    }

    A &operator=(A &&other)
    {
        cout << "Move assignment"
             << "\n";
        field = other.field;
        return *this;
    }
};

int main()
{
    A a1;           // constructor
    A a2(a1);       // copy constructor
    A a3 = a2;      // copy constructor
    a3 = a1;        // copy assignment
    A a4(move(a1)); // move constructor
    a4 = move(a2);  // move assignment
    return 0;
}
