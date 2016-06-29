#pragma once
#include "Matrix2.h"
class Vector2
{
private:
	
public:
	float m_x, m_y;
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2& operator=(const Vector2& vecA);
	const bool operator==(const Vector2& vecA);
	Vector2& operator*(const float f);
	Vector2& operator/(const float f);
	Vector2& operator/(const Vector2& rhs);
	Vector2& operator+(const Vector2& rhs);
	Vector2& operator-(const Vector2& rhs);
	friend Vector2 operator*(const float f, const Vector2& vecA);
	float dot(const Vector2& vecA);
	float magnitude();
	float distance(Vector2 rhs);
	void normalise();
	operator float*();
	Vector2& Vector2::operator*(const Matrix2 vecA);
};

Vector2 operator*(const float f, const Vector2& vecA);
