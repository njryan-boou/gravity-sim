#include "Gravity.hpp"

#include <fstream>

int main() {
    constexpr double mass = 5.972e24;

    std::ofstream file("data/field.csv");

    file << "x,y,gx,gy\n";

    for (double y = -1.0e7; y <= 1.0e7; y += 5.0e5) {
        for (double x = -1.0e7; x <= 1.0e7; x += 5.0e5) {

            if (x == 0.0 && y == 0.0)
                continue;

            Vector2 position{x, y};

            Vector2 g =
                gravitational_field(position, mass);

            file
                << x << ','
                << y << ','
                << g.x << ','
                << g.y << '\n';
        }
    }
}