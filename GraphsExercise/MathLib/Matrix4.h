#pragma once

class Vector4;

class Matrix4
{
public:
	Matrix4();
	Matrix4(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4);
	~Matrix4();
	const bool operator==(const Matrix4 & matA);
	Matrix4 operator*(const Matrix4 & matA);
	//Vector4 & operator*(const Vector4 & matA);
	void setRotateX(float f);
	void setRotateY(float f);
	void setRotateZ(float f);
	operator float*();
	Matrix4 & operator+(const Matrix4 & matA);
	Matrix4 & operator=(const Matrix4 & matA);

	Vector4 operator*(Vector4& rhs);
	
private:
	float m_arr[4][4];
};
