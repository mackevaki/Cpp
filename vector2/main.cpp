#include "vect.h"

int main() {
    Vector2 a(1, 3), b(6, 4);

    std::cout << "(1;3) + (6;4) = " << a + b << "\n";
    std::cout << "(1;3) - (6;4) = " << a - b << "\n";
    std::cout << "(1;3) * (6;4) = " << a * b << "\n";
    std::cout << "(1;3) ^ (6;4) = " << (a ^ b) << "\n";

    double alpha = 0;
    std::cin >> alpha;

    a.rotate(alpha * M_PI / 180);
    std::cout << a << std::endl;

    return 0;
}