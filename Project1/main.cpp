#include <iostream>

int main(void) {

    int i = 4;
    i >>= 1;
    std::cout << i;
    i <<= 2;
    std::cout << i;
    return 0;
}