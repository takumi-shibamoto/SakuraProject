#pragma once

namespace sakura::math
{
    /// @brief 2D vector structure
    struct Vector2D
    {
        //data member
        float x, y;

        Vector2D() = default;
        Vector2D(float x, float y);

        Vector2D& operator+=(Vector2D rhs);
        Vector2D& operator-=(Vector2D rhs);
        Vector2D& operator*=(float rhs);
        Vector2D& operator/=(float rhs);
    };
}