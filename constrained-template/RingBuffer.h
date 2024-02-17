#include <concepts>

template<typename T>
concept Int = std::integral<T>;

template<Int T, int sz>
class RingBuffer {
    static_assert(sz % 2 == 0, "size needs to be multiple of 2");
};