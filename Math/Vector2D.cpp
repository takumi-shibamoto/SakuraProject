#include "Vector2D.h"

namespace sakura::math
{
    Vector2D::Vector2D(float valX, float valY)
        : x{valX}
        , y{valY}
    {
    }

    Vector2D& Vector2D::operator+=(Vector2D rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Vector2D& Vector2D::operator-=(Vector2D rhs)
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    Vector2D& Vector2D::operator*=(float rhs)
    {
        this->x *= rhs;
        this->y *= rhs;
        return *this;
    }

    Vector2D& Vector2D::operator/=(float rhs)
    {
        this->x /= rhs;
        this->y /= rhs;
        return *this;
    }
}