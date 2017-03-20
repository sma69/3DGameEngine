#include "mat4.h"




namespace gt3d { namespace maths{

	mat4::mat4()
	{
		//initialize the matrix
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;

	}
	
	
	//gets diagonal line through 4x4 matrix and changes the value accordingly
	//this is how to call the matrix class as  mat4 a(1) = identity matrix
	mat4::mat4(float diagonal) 
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

	//Identity Matrix
	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	//Matrix Multiplication
	mat4& mat4::multiply(const mat4& other) 
	{
		float values[16];
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				values[x + y * 4] = sum;
			}
		}
		memcpy(elements, values, 4 * 4 * sizeof(float));
		return *this;
		
	}

	mat4 operator*(mat4 left, const mat4& right)
	{
		return left.multiply(right);
	}
	mat4& mat4::operator*=(const mat4& other) 
	{
		return multiply(other);
	}
	
	//Orthographic openGL Camera matrix
	mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		mat4 result(1.0f);

		return result.elements[0 + 0 * 4] = 2.0f / (right - left); //position 0 = this equation

		return result.elements[1 + 1 * 4] = 2.0f / (top - bottom); //position 4 = this equation

		return result.elements[2 + 2 * 4] = -2.0f / (far - near);   //position 10 = this equation

		return result.elements[3 + 0 * 4] = (right + left) / (left - right);   //position 3 = this equation
		return result.elements[3 + 1 * 4] = (top + bottom) / (bottom - top);   //position 7 = this equation
		return result.elements[3 + 2 * 4] = -(far + near) / (far - near);   //position 11 = this equation
	}
	
	//perspective camera OpenGL Matrix
	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 result(1.0f);

		float q = 1.0f / tan(toRadians(0.5f * fov));
		float a = q / aspectRatio;

		float b = -(far + near) / (far - near);
		float c = -(2.0f * far * near) / (far - near);

		result.elements[0 + 0 * 4] = a; //Position 0 
		result.elements[1 + 1 * 4] = q; //Position 5
		result.elements[2 + 2 * 4] = b; //Position 10
		result.elements[3 + 2 * 4] = c; //Position 11
		result.elements[2 + 3 * 4] = -1.0f; //Position 14


		return result;
	}

	//translation matrix
	mat4 mat4::translate(const vec3& translation)
	{
		mat4 result(1.0f);

		result.elements[3 + 0 * 4] = translation.x; //Position 12
		result.elements[3 + 1 * 4] = translation.y; //Position 13
		result.elements[3 + 2 * 4] = translation.z; //Position 14

		return result;
	}

	//rotation matrix
	mat4 mat4::rotation(float angle, const vec3& axis)
	{
		mat4 result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		//vec3 values
		float x = axis.x;
		float y = axis.y;
		float z = axis.z;
		
		result.elements[0 + 0 * 4] = x * x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = z * x * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * y * omc + c;
		result.elements[2 + 1 * 4] = z * y * omc + x * s;

		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * z * omc + c;

		return result;
	}
	
	//scaling matrix
	mat4 mat4::scale(const vec3& scale)
	{
		mat4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x; //Position 0
		result.elements[1 + 1 * 4] = scale.y; //Position 5
		result.elements[2 + 2 * 4] = scale.z; //Position 10

		return result;
	}

} }