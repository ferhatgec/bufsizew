#include "include/bufsizew.hpp"
#include <iostream>

int main() noexcept {
    __bufsize x;
    x.update();
    std::cout << x.columns << "x" << x.rows << '\n';
}