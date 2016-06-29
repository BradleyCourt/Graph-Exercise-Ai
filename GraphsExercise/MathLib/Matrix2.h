#pragma once
class Vector2;
class Matrix2
{
private:
	float m_arr[2][2];
public:
	Matrix2();
	Matrix2(float a1, float a2, float b1, float b2);
	~Matrix2();
	
	const bool operator==(const Matrix2 & matA);
	Matrix2 operator*(const Matrix2 & matA);
	void setRotateZ(float angle);
	operator float*();
	Vector2 operator*(Vector2 & rhs);
	Matrix2 operator+(const Matrix2 & matA);
	Matrix2 & Matrix2::operator=(const Matrix2 & matA);

};