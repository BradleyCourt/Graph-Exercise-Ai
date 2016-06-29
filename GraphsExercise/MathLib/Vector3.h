#pragma once
class Vector3
{
private:
	
public:
	float m_x, m_y, m_z;
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3& operator=(const Vector3& vecA);
	const bool operator==(const Vector3& vecA);
	Vector3& operator*(const float f);
	Vector3& operator/(const float f);
	Vector3& operator/(const Vector3& rhs);
	Vector3& operator+(const Vector3& rhs);
	Vector3& operator-(const Vector3& rhs);
	friend Vector3 operator*(const float f, const Vector3& vecA);
	float dot(const Vector3& vecA);
	Vector3 cross(const Vector3 & vecA);
	float magnitude();
	void normalise();
	operator float*();

};

Vector3 operator*(const float f, const Vector3& vecA);