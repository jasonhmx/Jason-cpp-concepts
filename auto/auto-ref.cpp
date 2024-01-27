class Foo
{
private:
    int m_{}; // list initialisation

public:
    auto& cref() const{ // works because auto carries constness
    // or can use const int& cref() const, first const for const ref
    // second const for const function, since const function can only return
    // const ref
        return m_;
    }
    auto& mref() { // mutable ref
        return m_;
    }
};

int main()
{
    auto x = Foo{};
    auto& ref = x.cref();
    // better to use const auto& ref = x.cref() to make intentions clear
    // ref = 5 doesn't compile since ref is const ref
    const auto& anyref1 = x.cref();
    const auto& anyref2 = x.mref(); // both type deduced to const int ref, binds to anything
    // auto&& also binds to anything but can forward mutable values too. Used when forwarding.
    return 0;
}