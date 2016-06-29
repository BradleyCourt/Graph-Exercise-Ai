#pragma once

class Vector4

{
//private:
	
public:
	float m_x, m_y, m_z, m_w;
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();
	Vector4& operator=(const Vector4& vecA);
	const bool operator==(const Vector4& vecA);
	Vector4& operator*(const float f);
	Vector4& operator/(const float f);
	Vector4& operator/(const Vector4& rhs);
	Vector4& operator+(const Vector4& rhs);
	Vector4& operator-(const Vector4& rhs);
	friend Vector4 operator*(const float f, const Vector4& vecA);
	float dot(const Vector4& vecA);
	Vector4 cross(const Vector4 & vecA);
	float magnitude();
	void normalise();
	operator float*();
	
};

Vector4 operator*(const float f, const Vector4& vecA);
