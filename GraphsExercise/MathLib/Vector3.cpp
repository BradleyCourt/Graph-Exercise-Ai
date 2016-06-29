#include "Vector3.h"
#include <math.h>



Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}


Vector3::~Vector3()
{
}

Vector3 & Vector3::operator=(const Vector3 & vecA)
{
	m_x = vecA.m_x;
	m_y = vecA.m_y;
	m_z = vecA.m_z;
	return *this;
}

const bool Vector3::operator==(const Vector3 & vecA)
{
	return (m_x == vecA.m_x) && (m_y == vecA.m_y) && (m_z == vecA.m_z);
}

Vector3 & Vector3::operator*(const float f)
{
	return Vector3((m_x * f), (m_y * f), (m_z * f));
}

Vector3 & Vector3::operator/(const float f)
{
	return Vector3((m_x / f), (m_y / f), (m_z / f));
}

Vector3 & Vector3::operator/(const Vector3 & rhs)
{
	return Vector3((m_x / rhs.m_x), (m_y / rhs.m_y), (m_z / rhs.m_z));
	// 90% sure is right
}

Vector3 & Vector3::operator+(const Vector3 & rhs)
{
	return Vector3((m_x + rhs.m_x), (m_y + rhs.m_y), (m_z + rhs.m_z));
}

Vector3 & Vector3::operator-(const Vector3 & rhs)
{
	return Vector3((m_x - rhs.m_x), (m_y - rhs.m_y), (m_z - rhs.m_z));
}

float Vector3::dot(const Vector3 & vecA)
{
	return ((m_x * vecA.m_x) + (m_y * vecA.m_y) + (m_z * vecA.m_z));
}

Vector3 Vector3::cross(const Vector3 & vecA)
{
	Vector3 newVec;
	newVec.m_x = m_y * vecA.m_z - m_z * vecA.m_y;
	newVec.m_y = m_z * vecA.m_x - m_x * vecA.m_z;
	newVec.m_z = m_x * vecA.m_y - m_y * vecA.m_x;
	return newVec;
}

float Vector3::magnitude()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

void Vector3::normalise()
{
	float length = magnitude();

	m_x = m_x / length;
	m_y = m_y / length;
	m_z = m_z / length;
}
Vector3::operator float*()
{
	return (float*)this;
}

Vector3 operator*(const float f, const Vector3 & vecA)
{
	return Vector3(vecA.m_x * f, vecA.m_y * f, vecA.m_z * f);
}

