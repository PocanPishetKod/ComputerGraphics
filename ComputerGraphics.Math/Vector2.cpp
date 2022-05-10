module;

#include <cmath>

module Math;

Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{

}

float Vector2::GetX() const
{
	return m_x;
}

float Vector2::GetY() const
{
	return m_y;
}

Vector2 Vector2::operator + (Vector2 &other) const
{
	return Vector2(m_x + other.m_x, m_y + other.m_y);
}

Vector2 Vector2::operator - (Vector2 &other) const
{
	return Vector2(m_x - other.m_x, m_y - other.m_y);
}

Vector2 Vector2::operator * (float number) const
{
	return Vector2(m_x * number, m_y * number);
}

float Vector2::operator * (Vector2 &other) const
{
	return Scalar(*this, other);
}

float Vector2::Scalar(Vector2 left, Vector2 right)
{
	return left.m_x * right.m_x + left.m_y * right.m_y;
}

float Vector2::GetMagnitude() const
{
	return sqrt(Scalar(*this, *this));
}