#include <iostream>
using namespace std;
#include <math.h>


template <bool head> int reversed_binary_value() { return head; }

template <bool head, bool mid, bool... tail> int reversed_binary_value() {
    return head + (reversed_binary_value<mid, tail...>()<<1);

