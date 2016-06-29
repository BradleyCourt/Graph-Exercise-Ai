#include "Matrix4.h"
#include "Vector4.h"

#include <math.h>

Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m_arr[i][j];
}

Matrix4::Matrix4(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4)
{
	m_arr[0][0] = a1;
	m_arr[0][1] = a2;
	m_arr[0][2] = a3;
	m_arr[0][3] = a4;
	m_arr[1][0] = b1;
	m_arr[1][1] = b2;
	m_arr[1][2] = b3;
	m_arr[1][3] = b4;
	m_arr[2][0] = c1;
	m_arr[2][1] = c2;
	m_arr[2][2] = c3;
	m_arr[2][3] = c4;
	m_arr[3][0] = d1;
	m_arr[3][1] = d2;
	m_arr[3][2] = d3;
	m_arr[3][3] = d4;

}

Matrix4::~Matrix4()
{
}

Matrix4 & Matrix4::operator=(const Matrix4 & matA)
{
	m_arr[0][0] = matA.m_arr[0][0];
	m_arr[0][1] = matA.m_arr[0][1];
	m_arr[0][2] = matA.m_arr[0][2];
	m_arr[0][3] = matA.m_arr[0][3];
	m_arr[1][0] = matA.m_arr[1][0];
	m_arr[1][1] = matA.m_arr[1][1];
	m_arr[1][2] = matA.m_arr[1][2];
	m_arr[1][3] = matA.m_arr[1][3];
	m_arr[2][0] = matA.m_arr[2][0];
	m_arr[2][1] = matA.m_arr[2][1];
	m_arr[2][2] = matA.m_arr[2][2];
	m_arr[2][3] = matA.m_arr[2][3];
	m_arr[3][0] = matA.m_arr[3][0];
	m_arr[3][1] = matA.m_arr[3][1];
	m_arr[3][2] = matA.m_arr[3][2];
	m_arr[3][3] = matA.m_arr[3][3];

	return *this;
}


Matrix4 & Matrix4::operator+(const Matrix4 & matA)
{
	Matrix4 result;
	result.m_arr[0][0] = m_arr[0][0] + matA.m_arr[0][0];
	result.m_arr[0][1] = m_arr[0][1] + matA.m_arr[0][1];
	result.m_arr[0][2] = m_arr[0][2] + matA.m_arr[0][2];
	result.m_arr[0][3] = m_arr[0][3] + matA.m_arr[0][3];
	result.m_arr[1][0] = m_arr[1][0] + matA.m_arr[1][0];
	result.m_arr[1][1] = m_arr[1][1] + matA.m_arr[1][1];
	result.m_arr[1][2] = m_arr[1][2] + matA.m_arr[1][2];
	result.m_arr[1][3] = m_arr[1][3] + matA.m_arr[1][3];
	result.m_arr[2][0] = m_arr[2][0] + matA.m_arr[2][0];
	result.m_arr[2][1] = m_arr[2][1] + matA.m_arr[2][1];
	result.m_arr[2][2] = m_arr[2][2] + matA.m_arr[2][2];
	result.m_arr[2][3] = m_arr[2][3] + matA.m_arr[2][3];
	result.m_arr[3][0] = m_arr[3][0] + matA.m_arr[3][0];
	result.m_arr[3][1] = m_arr[3][1] + matA.m_arr[3][1];
	result.m_arr[3][2] = m_arr[3][2] + matA.m_arr[3][2];
	result.m_arr[3][3] = m_arr[3][3] + matA.m_arr[3][3];

	return result;
}

const bool Matrix4::operator==(const Matrix4 & matA)
{
	return ((m_arr[0][0] == matA.m_arr[0][0]) && (m_arr[0][1] == matA.m_arr[0][1]) && (m_arr[0][2] == matA.m_arr[0][2]) && (m_arr[0][3] == matA.m_arr[0][3]) && (m_arr[1][0] == matA.m_arr[1][0]) && (m_arr[1][1] == matA.m_arr[1][1]) && (m_arr[1][2] == matA.m_arr[1][2]) && (m_arr[1][3] == matA.m_arr[1][3]) && (m_arr[2][0] == matA.m_arr[2][0]) && (m_arr[2][1] == matA.m_arr[2][1]) && (m_arr[2][2] == matA.m_arr[2][2]) && (m_arr[2][3] == matA.m_arr[2][3]) && (m_arr[3][0] == matA.m_arr[3][0]) && (m_arr[3][1] == matA.m_arr[3][1]) && (m_arr[3][2] == matA.m_arr[3][2]) && (m_arr[3][3] == matA.m_arr[3][3]));
}

Matrix4 Matrix4::operator*(const Matrix4 & matA)
{
	Matrix4 result;
	int m_row = 4, m_col = 4;
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




void Matrix4::setRotateX(float f)
{		   
	m_arr[0][0] = 1;
	m_arr[0][1] = 0;
	m_arr[0][2] = 0;
	m_arr[0][3] = 0;
	m_arr[1][0] = 0;
	m_arr[1][1] = cosf(f);
	m_arr[1][2] = sinf(f);
	m_arr[1][3] = 0;
	m_arr[2][0] = 0;
	m_arr[2][1] = -sinf(f);
	m_arr[2][2] = cosf(f);
	m_arr[2][3] = 0;
	m_arr[3][0] = 0;
	m_arr[3][1] = 0;
	m_arr[3][2] = 0;
	m_arr[3][3] = 1;
}		   
void Matrix4::setRotateY(float f)
{		   
	m_arr[0][0] = cosf(f);
	m_arr[0][1] = 0;
	m_arr[0][2] = -sinf(f);
	m_arr[0][3] = 0;
	m_arr[1][0] = 0;
	m_arr[1][1] = 1;
	m_arr[1][2] = 0;
	m_arr[1][3] = 0;
	m_arr[2][0] = sinf(f);
	m_arr[2][1] = 0;
	m_arr[2][2] = cosf(f);
	m_arr[2][3] = 0;
	m_arr[3][0] = 0;
	m_arr[3][1] = 0;
	m_arr[3][2] = 0;
	m_arr[3][3] = 1;
}		   
void Matrix4::setRotateZ(float f)
{		   
	m_arr[0][0] = cosf(f);
	m_arr[0][1] = sinf(f);
	m_arr[0][2] = 0;
	m_arr[0][3] = 0;
	m_arr[1][0] = -sinf(f);
	m_arr[1][1] = cosf(f);
	m_arr[1][2] = 0;
	m_arr[1][3] = 0;
	m_arr[2][0] = 0;
	m_arr[2][1] = 0;
	m_arr[2][2] = 1;
	m_arr[2][3] = 0;
	m_arr[3][0] = 0;
	m_arr[3][1] = 0;
	m_arr[3][2] = 0;
	m_arr[3][3] = 1;
}		   

Matrix4::operator float*()
{
	return *m_arr;
}

Vector4 Matrix4::operator*(Vector4 & rhs)
{
	Vector4 results;

	float tempVecResults[4] = { 0, 0, 0, 0 };
	int vecCol = 4, vecRow = 4;

	results.m_x = m_arr[0][0] * rhs.m_x + m_arr[0][1] * rhs.m_y + m_arr[0][2] * rhs.m_z + m_arr[0][3] * rhs.m_w;
	results.m_y = m_arr[1][0] * rhs.m_x + m_arr[1][1] * rhs.m_y + m_arr[1][2] * rhs.m_z + m_arr[1][3] * rhs.m_w;
	results.m_z = m_arr[2][0] * rhs.m_x + m_arr[2][1] * rhs.m_y + m_arr[2][2] * rhs.m_z + m_arr[2][3] * rhs.m_w;
	results.m_w = m_arr[3][0] * rhs.m_x + m_arr[3][1] * rhs.m_y + m_arr[3][2] * rhs.m_z + m_arr[3][3] * rhs.m_w;

	return results;

}
