#include "Vec2.h"

Vec2::Vec2()
{

}

Vec2::Vec2(float xin, float yin)
	:x(xin), y(yin)
{
}


Vec2 Vec2::operator/(const float val) const
{
	return Vec2(x*val, y*val);
}

Vec2 Vec2::operator*(const float val) const
{
	return Vec2(x*val, y*val);
}

bool Vec2::operator==(const Vec2& rhs) const
{
	return (x == rhs.x) && (y == rhs.y);
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}



void Vec2::operator+=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}

void Vec2::operator-=(const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}

void Vec2::operator*=(const float val)
{
	x *= val;
	y *= val;
}

void Vec2::operator/=(const float val)
{
	x /= val;
	y /= val;
}

float Vec2::dist(const Vec2& rhs) const
{
	return sqrtf((x+rhs.x)*(x + rhs.x)+(y+rhs.y)*(y + rhs.y));
}

Vec2 Vec2::normalize() const
{
	return Vec2();
}
