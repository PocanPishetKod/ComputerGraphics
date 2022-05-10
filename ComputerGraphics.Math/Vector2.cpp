module;

#include <cmath>

module Math;

Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{

}

float const Vector2::GetX()
{
	return m_x;
}

float const Vector2::GetY()
{
	return m_y;
}

Vector2 const Vector2::operator + (Vector2 &other)
{
	return Vector2(m_x + other.m_x, m_y + other.m_y);
}

Vector2 const Vector2::operator - (Vector2 &other)
{
	return Vector2(m_x - other.m_x, m_y - other.m_y);
}

Vector2 const Vector2::operator * (float number)
{
	return Vector2(m_x * number, m_y * number);
}

float const Vector2::operator * (Vector2 &other)
{
	return Scalar(*this, other);
}

float Vector2::Scalar(Vector2 left, Vector2 right)
{
	return left.m_x * right.m_x + left.m_y * right.m_y;
}

float const Vector2::GetMagnitude()
{
	return sqrt(Scalar(*this, *this));
}