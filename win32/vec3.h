#pragma once


#include <iostream>


//this si the two-dimensional vector header
namespace gt3d {
	namespace maths
	{

		struct vec3
		{
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);
			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			//operator overloads to math functions
			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			//operaator overloads to comparison functions
			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);

		};
	}
}
#pragma once
