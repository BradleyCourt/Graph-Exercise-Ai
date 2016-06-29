#include "Matrix3.h"
#include "Vector3.h"
#include <math.h>
Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m_arr[i][j];
}

Matrix3::Matrix3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
	m_arr[0][0] = a1;
	m_arr[0][1] = a2;
	m_arr[0][2] = a3;
	m_arr[1][0] = b1;
	m_arr[1][1] = b2;
	m_arr[1][2] = b3;
	m_arr[2][0] = c1;
	m_arr[2][1] = c2;
	m_arr[2][2] = c3;
}

Matrix3 & Matrix3::operator=(const Matrix3 & matA)
{
	m_arr[0][0] = matA.m_arr[0][0];
	m_arr[0][1] = matA.m_arr[0][1];
	m_arr[0][2] = matA.m_arr[0][2];
	m_arr[1][0] = matA.m_arr[1][0];
	m_arr[1][1] = matA.m_arr[1][1];
	m_arr[1][2] = matA.m_arr[1][2];
	m_arr[2][0] = matA.m_arr[2][0];
	m_arr[2][1] = matA.m_arr[2][1];
	m_arr[2][2] = matA.m_arr[2][2];

	return *this;
}

Matrix3 Matrix3::CreateIdentity()
{
	Matrix3 Mat;
	1, 0, 0,
	0, 1, 0,
	0, 0, 1;
	return Mat;
}

Matrix3 Matrix3::GetTranspose()
{
	Matrix3 Mat;
	for (int i = 0; i < 3; i++)
	{
		for (int index = 0; index < 3; index)
		{
			
			Mat.m_arr[i][index] = m_arr[i][index];
			m_arr[i][index] = m_arr[index][i];
			m_arr[index][i] = Mat.m_arr[index][i];
		}
	}
	return Mat;
}

Matrix3::~Matrix3()
{
}

Matrix3 & Matrix3::operator+(const Matrix3 & matA)
{
	Matrix3 result;
	result.m_arr[0][0] = m_arr[0][0] + matA.m_arr[0][0];
	result.m_arr[0][1] = m_arr[0][1] + matA.m_arr[0][1];
	result.m_arr[0][2] = m_arr[0][2] + matA.m_arr[0][2];
	result.m_arr[1][0] = m_arr[1][0] + matA.m_arr[1][0];
	result.m_arr[1][1] = m_arr[1][1] + matA.m_arr[1][1];
	result.m_arr[1][2] = m_arr[1][2] + matA.m_arr[1][2];
	result.m_arr[2][0] = m_arr[2][0] + matA.m_arr[2][0];
	result.m_arr[2][1] = m_arr[2][1] + matA.m_arr[2][1];
	result.m_arr[2][2] = m_arr[2][2] + matA.m_arr[2][2];

	return result;
}


const bool Matrix3::operator==(const Matrix3 & matA)
{
	return ((m_arr[0][0] == matA.m_arr[0][0]) && (m_arr[0][1] == matA.m_arr[0][1]) && (m_arr[0][2] == matA.m_arr[0][2]) && (m_arr[1][0] == matA.m_arr[1][0]) && (m_arr[1][1] == matA.m_arr[1][1]) && (m_arr[1][2] == matA.m_arr[1][2]) && (m_arr[2][0] == matA.m_arr[2][0]) && (m_arr[2][1] == matA.m_arr[2][1]) && (m_arr[2][2] == matA.m_arr[2][2]));
}

Matrix3 Matrix3::operator*(const Matrix3 & matA)
{
	Matrix3 result;
	int m_row = 3, m_col = 3;
	for (int j = 0; j < m_row; j++)
	{
		for (int i = 0; i < m_col; i++)
		{
			float temp = 0.0f;
			for (int k = 0; k < m_col; k++)
			{
				temp = temp + (m_arr[k][j] * matA.m_arr[i][k]);
			}
			result.m_arr[i][j] = temp;
		}
	}
	return result;
}

void Matrix3::setRotateX(float f)
{
	m_arr[0][0] = 1;
	m_arr[0][1] = 0;
	m_arr[0][2] = 0;
	m_arr[1][0] = 0;
	m_arr[1][1] = cosf(f);
	m_arr[1][2] = sinf(f);
	m_arr[2][0] = 0;
	m_arr[2][1] = -sinf(f);
	m_arr[2][2] = cosf(f);
}
void Matrix3::setRotateY(float f)
{
	m_arr[0][0] = cosf(f);
	m_arr[0][1] = 0;
	m_arr[0][2] = -sinf(f);
	m_arr[1][0] = 0;
	m_arr[1][1] = 1;
	m_arr[1][2] = 0;
	m_arr[2][0] = sinf(f);
	m_arr[2][1] = 0;
	m_arr[2][2] = cosf(f);
}
void Matrix3::setRotateZ(float f)
{
	m_arr[0][0] = cosf(f);
	m_arr[0][1] = sinf(f);
	m_arr[0][2] = 0;
	m_arr[1][0] = -sinf(f);
	m_arr[1][1] = cosf(f);
	m_arr[1][2] = 0;
	m_arr[2][0] = 0;
	m_arr[2][1] = 0;
	m_arr[2][2] = 1;

}

Matrix3::operator float*()
{
	return *m_arr;
}

Vector3 Matrix3::operator*(Vector3 & rhs)
{
	Vector3 results;

	float tempVecResults[3] = { 0, 0, 0 };
	int vecCol = 3, vecRow = 3;

	results.m_x = m_arr[0][0] * rhs.m_x + m_arr[0][1] * rhs.m_y + m_arr[0][2];
	results.m_y = m_arr[1][0] * rhs.m_x + m_arr[1][1] * rhs.m_y + m_arr[1][2];
	results.m_z = m_arr[2][0] * rhs.m_x + m_arr[2][1] * rhs.m_y + m_arr[2][2];

	return results;

}