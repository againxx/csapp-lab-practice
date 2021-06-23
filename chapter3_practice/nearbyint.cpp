#include <iostream>
#include <cmath>

std::size_t convert(double x, double y) {
    std::size_t x_index = static_cast<std::size_t>(std::nearbyint(x));
    std::size_t y_index = static_cast<std::size_t>(std::nearbyint(y));
    return x_index * 5 + y_index;
}

int main() {
    std::size_t result = convert(3.2, 2.4);
    std::cout << result << '\n';
    return 0;
}
