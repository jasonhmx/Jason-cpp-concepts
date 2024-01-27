#include <concepts>

template<typename T>
concept Int = std::integral<T>;

template<typename T, int sz>
requires Int<T>
class RingBuffer {
    static_assert(sz % 2 == 0, "size needs to be multiple of 2");
};