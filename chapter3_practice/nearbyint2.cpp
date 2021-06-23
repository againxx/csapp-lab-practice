#include <cmath>
#include <iostream>

int main() {
    std::size_t result = static_cast<std::size_t>(std::nearbyint(10223372036854775800.3));
    std::cout << result << '\n';
    return 0;
}
