#include <stdint.h>

class StdDither
{
public:
    StdDither(uint32_t seed);
    void setSeed(uint32_t seed);
    uint32_t cycle();
private:
    uint32_t state;
};

// inline implementations

inline StdDither::StdDither(uint32_t seed) : state(seed)
{}

inline void StdDither::setSeed(uint32_t seed)
{
    state = seed;
}

inline uint32_t StdDither::cycle()
{
    uint32_t result = state;	// Return old value rather than new just to reduce dependency chains
    // Silent reduction mod 2^32 expected
    // Magic values from Numerical Recipies
    state = state * 1664525 + 1013904223;
    return result;
}