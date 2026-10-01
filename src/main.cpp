#include "Gravity.hpp"
#include "Mass.hpp"

#include <fstream>

int main() {
    Mass m0
    {
    .position = {0.0, -5e6},
    .mass = 5.972e24
    };

    Mass m1
    {
    .position = {0, 0},
    .mass = 5.972e24
    };

    double px = m0.position.x + m1.position.x;
    double py = m0.position.y + m1.position.y;



    std::ofstream file("data/field.csv");

    file << "x,y,gx,gy,potential\n";

    for (double y = -1.0e7; y <= 1.0e7; y += 5.0e5) {
        for (double x = -1.0e7; x <= 1.0e7; x += 5.0e5) {

            if (x == px && y == py)
                continue;

            Vector2 position{x, y};

            Vector2 g0 =
                gravitational_field(position, m0);
            Vector2 g1 =
                gravitational_field(position, m1);
            double gx = g0.x + g1.x;
            double gy = g1.y + g1.y;

            double phi0 = gravitational_potential(position, m0);
            double phi1 = gravitational_potential(position, m1);

            double phi_total = phi0 + phi1;

            file
                << x << ','
                << y << ','
                << gx << ','
                << gy << ','
                << phi_total << '\n';
        }
    }
}