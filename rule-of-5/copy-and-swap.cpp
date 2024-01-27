#include <algorithm>

class String
{
    char *str;

public:
    String &operator=(String s) // the pass-by-value parameter serves as a temporary
    {
        s.swap(*this); // Non-throwing swap
        return *this;
    }                             // Old resources released when destructor of s is called.
    void swap(String &s) noexcept // Also see non-throwing swap idiom
    {
        std::swap(this->str, s.str);
    }
    ~String()
    {
        delete[] str;
    }
};