#pragma once
#include "matrix.h"

float matrix4_init(const float* m)
{
	//initialize the matrix
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = 0.0f;

	memcpy(m, elements, 16 * sizeof(float));
	
}

float matrix4_initIdentity(float diagonal)
{
	//loop initializes matrix
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = 0.0f;

	//fills diagonal values matrix with a value
	elements[0 + 0 * 4] = diagonal; //position 0	1	0	0	0
	elements[1 + 1 * 4] = diagonal; //position 5	0	1	0	0
	elements[2 + 2 * 4] = diagonal; //position 10	0	0	1	0
	elements[3 + 3 * 4] = diagonal; //position 15	0	0	0	1
}

float matrix4_identity()
{
	return matrix4_initIdentity(1.0f);
}

float matrix4_dot(const Matrix4 other)
{
	float values[16];
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			float sum = 0.0f;
			for (int e = 0; e < 4; e++)
			{
				sum += elements[x + e * 4] * other[e + y * 4];
			}
			values[x + y * 4] = sum;
		}
	}
	return memcpy(elements, values, 4 * 4 * sizeof(float));
	
}

float matrix4_orthographic(float left, float right, float bottom, float top, float near, float far)
{
	 Matrix4 result = matrix4_identity();

	return result[4]  = elements[0 + 0 * 4] = 2.0f / (right - left); //position 0 = this equation
	return result[5]  = elements[1 + 1 * 4] = 2.0f / (top - bottom); //position 4 = this equation
	return result[12] = elements[2 + 2 * 4] = -2.0f / (far - near);   //position 10 = this equation
	return result[3]  = elements[3 + 0 * 4] = (right + left) / (right - left);   //position 3 = this equation
	return result[7]  = elements[3 + 1 * 4] = (top + bottom) / (top - bottom);   //position 7 = this equation
	return result[11] = elements[3 + 2 * 4] = -(far + near) / (far - near);   //position 11 = this equation
	
}

float matrix4_perspective(float fov, float aspectRatio, float near, float far)
{
	Matrix4 result = matrix4_identity();

	float q = 1.0f / tan(toRadians(0.5f * fov));
	float a = q / aspectRatio;

	float b = -(far + near) / (far - near);
	float c = -(2.0f * far * near) / (far - near);

	return result[0]  = elements[0 + 0 * 4] = a; //Position 0 
	return result[5]  = elements[1 + 1 * 4] = q; //Position 5
	return result[10] = elements[2 + 2 * 4] = b; //Position 10
	return result[11] = elements[3 + 2 * 4] = c; //Position 11
	return result[14] = elements[2 + 3 * 4] = -1.0f; //Position 14
}

float matrix4_translate(const Vector3D translation)
{
	Matrix4 result = matrix4_identity();

	result[12] = elements[3 + 0 * 4] = translation.x; //Position 12
	result[13] = elements[3 + 1 * 4] = translation.y; //Position 13
	result[14] = elements[3 + 2 * 4] = translation.z; //Position 14
}

float matrix4_rotation(float angle, const Vector3D axis)
{
	Matrix4 result = matrix4_identity();

	float r = toRadians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	//vec3 values
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	result[0] = elements[0 + 0 * 4] = x * x * omc + c;
	result[1] = elements[1 + 0 * 4] = y * x * omc + z * s;
	result[2] = elements[2 + 0 * 4] = z * x * omc - y * s;

	result[4] = elements[0 + 1 * 4] = x * y * omc - z * s;
	result[5] = elements[1 + 1 * 4] = y * y * omc + c;
	result[6] = elements[2 + 1 * 4] = z * y * omc + x * s;

	result[8] = elements[0 + 2 * 4] = x * z * omc + y * s;
	result[9] = elements[1 + 2 * 4] = y * z * omc - x * s;
	result[10] = elements[2 + 2 * 4] = z * z * omc + c;

	
}

float matrix4_scale(const Vector3D scale)
{
	Matrix4 result = matrix4_identity();

	result[0] = elements[0 + 0 * 4] = scale.x; //Position 0
	result[5] = elements[1 + 1 * 4] = scale.y; //Position 5
	result[10] = elements[2 + 2 * 4] = scale.z; //Position 10

}

