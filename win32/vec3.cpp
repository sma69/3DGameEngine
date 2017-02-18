#include "vec3.h"


//This is the two Dimensional vector Class
namespace gt3d {
	namespace maths {

		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;

		}

		//ve2 declaration
		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;

		}

		//vector2 math functions
		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}
		vec3& vec3::subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}
		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}
		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		//overloads math operator to allow addition between vectors
		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}
		vec3 operator-(vec3 left, const vec3& right)
		{
			return left.subtract(right);
		}
		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}
		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}

		//overloads other types of math operators
		vec3& vec3::operator+=(const vec3& other)
		{

			return add(other);
		}
		vec3& vec3::operator-=(const vec3& other)
		{

			return subtract(other);
		}
		vec3& vec3::operator*=(const vec3& other)
		{

			return multiply(other);
		}
		vec3& vec3::operator/=(const vec3& other)
		{

			return divide(other);
		}

		bool vec3::operator==(const vec3& other)
		{

			return x == other.x && y == other.y && z == other.z;
		}
		bool vec3::operator!=(const vec3& other)
		{

			return !(*this == other);
		}
		//overloads output stream to print vector as below
		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << "vec3: (" << vector.x << "," << vector.y << "," << vector.z << ")";
			return stream;
		}

	}
}