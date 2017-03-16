#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "vector.h"


	typedef float Matrix3[9];

	typedef float Matrix4[16];

	/**Elements matrix used to get matrix functions*/
	float elements[4*4];

	float matrix4_init();

	float matrix4_initIdentity(float diagonal);

	/**Identity Matrix*/
	float matrix4_identity();

	/**
	@brief performs a dot product between these two matrices
	@param a the multiplier
	@param b the multiplicant
	@returns the dot product
	*/


	float matrix4_dot(const Matrix4 other);

	/**Camera view Matrices*/
	float matrix4_orthographic(float left, float right, float bottom, float top, float near, float far);
	float matrix4_perspective(float fov, float aspectRatio, float near, float far);

	/**Transform Matrices*/
	float matrix4_translate(const Vector3D translation);
	float matrix4_rotation(float angle, const Vector3D axis);
	float matrix4_scale(const Vector3D scale);

#endif