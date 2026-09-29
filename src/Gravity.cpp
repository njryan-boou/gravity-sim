#include "Gravity.hpp"

#include <cmath>

namespace {
constexpr double G = 6.67430e-11;
}

Vector2 gravitational_field(
    const Vector2& position,
    double source_mass
) {
    double r = std::sqrt(
        position.x * position.x +
        position.y * position.y
    );

    double factor =
        -G * source_mass / (r * r * r);

    return {
        factor * position.x,
        factor * position.y
    };
}