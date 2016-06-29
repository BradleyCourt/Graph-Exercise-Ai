#include "Matrix2.h"
#include "Vector2.h"
#include <math.h>
Matrix2::Matrix2()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			m_arr[i][j];
}

Matrix2::Matrix2(float a1, float a2, float b1, float b2)
{
	m_arr[0][0] = a1;
	m_arr[0][1] = a2;
	m_arr[1][0] = b1;
	m_arr[1][1] = b2;
}

Matrix2 & Matrix2::operator=(const Matrix2 & matA)
{
	m_arr[0][0] = matA.m_arr[0][0];
	m_arr[0][1] = matA.m_arr[0][1];
	m_arr[1][0] = matA.m_arr[1][0];
	m_arr[1][1] = matA.m_arr[1][1];
	return *this;
}

Matrix2::~Matrix2()
{
}

Matrix2 Matrix2::operator+(const Matrix2 & matA)
{
	Matrix2 result;
	result.m_arr[0][0] = m_arr[0][0] + matA.m_arr[0][0];
	result.m_arr[0][1] = m_arr[0][1] + matA.m_arr[0][1];
	result.m_arr[1][0] = m_arr[1][0] + matA.m_arr[1][0];
	result.m_arr[1][1] = m_arr[1][1] + matA.m_arr[1][1];
	return result;
}


const bool Matrix2::operator==(const Matrix2 & matA)
{
	return ((m_arr[0][0] == matA.m_arr[0][0]) && (m_arr[0][1] == matA.m_arr[0][1]) && (m_arr[1][0] == matA.m_arr[1][0]) && (m_arr[1][1] == matA.m_arr[1][1]));
}

Matrix2 Matrix2::operator*(const Matrix2 & matA)
{
	Matrix2 result;
	
	int m_row = 2, m_col = 2;
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

void Matrix2::setRotateZ(float f)
{
	m_arr[0][0] = cosf(f);
	m_arr[0][1] = sinf(f);
	m_arr[1][0] = -sinf(f);
	m_arr[1][1] = cosf(f);
}

Matrix2::operator float*()
{
	return *m_arr;
}

Vector2 Matrix2::operator*(Vector2 & rhs)
{
	Vector2 results;

	float tempVecResults[2] = { 0, 0 };
	int vecCol = 2, vecRow = 2;

	results.m_x = m_arr[0][0] * rhs.m_x + m_arr[0][1];
	results.m_y = m_arr[1][0] * rhs.m_x + m_arr[1][1];


	return results;

}