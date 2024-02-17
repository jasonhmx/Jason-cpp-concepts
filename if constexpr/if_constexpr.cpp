#include <concepts>
#include <cmath>

template <typename T>
auto generic_mod(const T& v, const T& n) -> T {
    assert(n!=0);
    if constexpr (std::is_floating_point_v<T>) { // just generates std::fmod if incoming type is floating point
        return std::fmod(v, n);
    } else { // integer type would result in compiling this code instead
        return v % n;
    }
}

int main() {

    return 0;
}