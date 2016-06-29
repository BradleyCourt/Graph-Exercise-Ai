#include "Vector2.h"
#include <math.h>


Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
}

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}


Vector2::~Vector2()
{
}

Vector2 & Vector2::operator=(const Vector2 & vecA)
{
	m_x = vecA.m_x;
	m_y = vecA.m_y;
	return *this;
}

const bool Vector2::operator==(const Vector2 & vecA)
{
	return (m_x == vecA.m_x) && (m_y == vecA.m_y);
}

Vector2 & Vector2::operator*(const float f)
{
	return Vector2((m_x * f), (m_y * f));
}

Vector2 & Vector2::operator/(const float f)
{
	return Vector2((m_x / f), (m_y / f));
}

Vector2 & Vector2::operator/(const Vector2 & rhs)
{
	return Vector2((m_x / rhs.m_x), (m_y / rhs.m_y));
	// 90% sure is right
}

Vector2 & Vector2::operator+(const Vector2 & rhs)
{
	return Vector2((m_x + rhs.m_x), (m_y + rhs.m_y));
}

Vector2 & Vector2::operator-(const Vector2 & rhs)
{
	return Vector2((m_x - rhs.m_x), (m_y - rhs.m_y));
}

float Vector2::dot(const Vector2 & vecA)
{
	return ((m_x * vecA.m_x) + (m_y * vecA.m_y));
}

float Vector2::magnitude()
{
	return sqrt(m_x*m_x + m_y*m_y);
}

float Vector2::distance(Vector2 rhs)
{
	return (*this - rhs).magnitude();
}

void Vector2::normalise()
{
	float length = magnitude();

	m_x = m_x / length;
	m_y = m_y / length;
}
Vector2::operator float*()
{	
	return (float*)this;
}

Vector2 & Vector2::operator*(const Matrix2 vecA)
{
	Vector2 result;
	int vec = 2;
	//for int i = 0
	return result;
}

Vector2  operator*(const float f, const Vector2 & vecA)
{
	return Vector2(vecA.m_x * f, vecA.m_y * f);
}
