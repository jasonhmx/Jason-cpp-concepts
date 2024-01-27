#pragma once
#include <concepts>

/* // base case used for recursive unpacking, if not using fold exp
template<typename T>
requires std::floating_point<T>
double sum(T t){
    return t;
}
 */

// variadic template definition + fold expression requirements
template<typename ... Targs>
requires (... && std::floating_point<Targs>)
double sum(const Targs& ... args){
    return (... + args);
}

