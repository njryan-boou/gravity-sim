#pragma once

#include "Vector2.hpp"
#include "Mass.hpp"

Vector2 gravitational_field(
    const Vector2& position,
    Mass source_mass
);

double gravitational_potential(
    const Vector2& position,
    const Mass& source_mass
);