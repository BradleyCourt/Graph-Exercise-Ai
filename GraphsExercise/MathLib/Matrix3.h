#pragma once
class Vector3;

class Matrix3
{
public:
	Matrix3();
	Matrix3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3);
	~Matrix3();
	
	const bool operator==(const Matrix3 & matA);
	Matrix3 operator*(const Matrix3 & matA);
	void setRotateX(float f);
	void setRotateY(float f);
	void setRotateZ(float f);
	operator float*();
	Vector3 operator*(Vector3 & rhs);
	Matrix3 &operator+(const Matrix3 & matA);
	Matrix3 & Matrix3::operator=(const Matrix3 & matA);

	// MAKE THESE WORK
	static Matrix3 CreateIdentity();
	static Matrix3 CreateRotation(float angle);
	static Matrix3 CreateScale(const Vector3& scale);
	Matrix3 GetTranspose();

private:
	float m_arr[3][3];
};