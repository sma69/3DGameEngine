#include "vec4.h"


//This is the two Dimensional vector Class
namespace gt3d {
	namespace maths {

		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;

		}

		//ve2 declaration
		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;

		}

		//vector2 math functions
		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}
		vec4& vec4::subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}
		vec4& vec4::multiply(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}
		vec4& vec4::divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		//overloads math operator to allow addition between vectors
		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);
		}
		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.subtract(right);
		}
		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);
		}
		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}

		//overloads other types of math operators
		vec4& vec4::operator+=(const vec4& other)
		{

			return add(other);
		}
		vec4& vec4::operator-=(const vec4& other)
		{

			return subtract(other);
		}
		vec4& vec4::operator*=(const vec4& other)
		{

			return multiply(other);
		}
		vec4& vec4::operator/=(const vec4& other)
		{

			return divide(other);
		}

		bool vec4::operator==(const vec4& other)
		{

			return x == other.x && y == other.y && z == other.z && w == other.w;
		}
		bool vec4::operator!=(const vec4& other)
		{

			return !(*this == other);
		}
		//overloads output stream to print vector as below
		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << "vec4: (" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")";
			return stream;
		}

	}
}