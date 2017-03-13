#pragma once
#include "matrix.h"

float matrix4_init()
{
	//initialize the matrix
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = 0.0f;
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
