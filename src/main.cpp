#include "Gravity.hpp"
#include "Mass.hpp"

#include <cmath>
#include <fstream>
#include <filesystem>
#include <vector>

int main() {
    std::vector<Mass> masses = {
        {{-3.0e6, 0.0}, 5.972e24},
        {{ 3.0e6, 0.0}, 5.972e24},
        {{ 0.0, 5.0e6}, 5.972e24}
    };
    std::filesystem::create_directories("data");
    
    std::ofstream file("data/field.csv");

    file << "x,y,gx,gy,potential\n";

    constexpr double min_distance = 1.0;

    for (double y = -1.0e7; y <= 1.0e7; y += 5.0e5) {
        for (double x = -1.0e7; x <= 1.0e7; x += 5.0e5) {
            Vector2 position{x, y};

            double total_gx = 0.0;
            double total_gy = 0.0;
            double total_potential = 0.0;

            bool too_close_to_mass = false;

            for (const Mass& mass : masses) {
                double dx = x - mass.position.x;
                double dy = y - mass.position.y;

                double distance = std::sqrt(
                    dx * dx +
                    dy * dy
                );

                if (distance < min_distance) {
                    too_close_to_mass = true;
                    break;
                }

                Vector2 field =
                    gravitational_field(position, mass);

                total_gx += field.x;
                total_gy += field.y;

                total_potential +=
                    gravitational_potential(position, mass);
            }

            if (too_close_to_mass) {
                continue;
            }

            file
                << x << ','
                << y << ','
                << total_gx << ','
                << total_gy << ','
                << total_potential << '\n';
        }
    }
}