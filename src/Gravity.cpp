#include "Gravity.hpp"
#include "Mass.hpp"

#include <cmath>

namespace {
constexpr double G = 6.67430e-11;
}

Vector2 gravitational_field(
    const Vector2& position,
    Mass source_mass
) {
    double delta_x = position.x - source_mass.position.x;
    double delta_y = position.y - source_mass.position.y;
    double r = std::sqrt(
        delta_x * delta_x +
        delta_y * delta_y
    );

    double factor =
        -G * source_mass.mass / (r * r * r);

    return {
        factor * delta_x,
        factor * delta_y
    };
}

double gravitational_potential(
    const Vector2& position,
    const Mass& source_mass
) {
    double delta_x = position.x - source_mass.position.x;
    double delta_y = position.y - source_mass.position.y;

    double r = std::sqrt(
        delta_x * delta_x +
        delta_y * delta_y
    );

    return -G * source_mass.mass / r;
}