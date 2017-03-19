#pragma once
#ifndef __MATRIX4_H__
#define __MATRIX4_H__

#include "vector.h"


typedef struct Matrix4 Matrix4;
struct Matrix4 {


	union
	{
		float elements[4 * 4];
		Vector4D columns[4];
	};

	Matrix4();
	Matrix4(float diagonal);



	Vector4D getColumn(int index)
	{
		index *= 4;
		return Vector4D(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
	}

	//identity matrix
	static Matrix4 identity();

	//math functions for matrices
	Matrix4& multiply(const Matrix4& other);



	//camera view functions
	static Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far);
	static Matrix4 perspective(float fov, float aspectRatio, float near, float far);

	//matrix movement functions
	static Matrix4 translate(const Vector3D& translation);
	static Matrix4 rotation(float angle, const Vector3D& axis);
	static Matrix4 scale(const Vector3D& scale);


};



#endif