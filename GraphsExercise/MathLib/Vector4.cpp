#include "Vector4.h"
#include <math.h>


Vector4::Vector4()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}


Vector4::~Vector4()
{
}

Vector4 & Vector4::operator=(const Vector4 & vecA)
{
	m_x = vecA.m_x;
	m_y = vecA.m_y;
	m_z = vecA.m_z;
	m_w = vecA.m_w;
	return *this;
}

const bool Vector4::operator==(const Vector4 & vecA)
{
	return (m_x == vecA.m_x) && (m_y == vecA.m_y) && (m_z == vecA.m_z) && (m_w == vecA.m_w);
}

Vector4 & Vector4::operator*(const float f)
{
	return Vector4((m_x * f), (m_y * f), (m_z * f), (m_w * f));
}

Vector4 & Vector4::operator/(const float f)
{
	return Vector4((m_x / f), (m_y / f), (m_z / f), (m_w / f));
}

Vector4 & Vector4::operator/(const Vector4 & rhs)
{
	return Vector4((m_x / rhs.m_x), (m_y / rhs.m_y), (m_z / rhs.m_z), (m_w / rhs.m_w));
	// 90% sure is right
}

Vector4 & Vector4::operator+(const Vector4 & rhs)
{
	return Vector4((m_x + rhs.m_x), (m_y + rhs.m_y), (m_z + rhs.m_z), (m_w +rhs.m_w));
}

Vector4 & Vector4::operator-(const Vector4 & rhs)
{
	return Vector4((m_x - rhs.m_x), (m_y - rhs.m_y), (m_z - rhs.m_z), (m_w - rhs.m_w));
}

float Vector4::dot(const Vector4 & vecA)
{
	return ((m_x * vecA.m_x) + (m_y * vecA.m_y) + (m_z * vecA.m_z) + (m_w * vecA.m_w));
}

Vector4 Vector4::cross(const Vector4 & vecA)
{
	Vector4 newVec;
	newVec.m_x = m_y * vecA.m_z - m_z * vecA.m_y;
	newVec.m_y = m_z * vecA.m_x - m_x * vecA.m_z;
	newVec.m_z = m_x * vecA.m_y - m_y * vecA.m_x;
	newVec.m_w = 0;
	return newVec;
}

float Vector4::magnitude()
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
}

void Vector4::normalise()
{
	float length = magnitude();

	m_x = m_x / length;
	m_y = m_y / length;
	m_z = m_z / length;
	m_w = m_w / length;
}

Vector4::operator float*()
{
	return (float*)this;
}

Vector4 operator*(const float f, const Vector4 & vecA)
{
	//return Vector4(vecA.m_x * f, vecA.m_y * f, vecA.m_z * f, vecA.m_w * f);
	Vector4 newVec;
	newVec.m_x = f * vecA.m_x;
	newVec.m_y = f * vecA.m_y;
	newVec.m_z = f * vecA.m_z;
	newVec.m_w = f * vecA.m_w;
	return newVec;
	
}

//Vector4 operator*(const Matrix4 & lhs, const Vector4 & rhs);

