#pragma once


#include <iostream>


	//this si the two-dimensional vector header
	namespace gt3d {
		namespace maths
		{

			struct vec2
			{
				float x, y;

				vec2();
				vec2(const float& x, const float& y);
				vec2& add(const vec2& other);
				vec2& subtract(const vec2& other);
				vec2& multiply(const vec2& other);
				vec2& divide(const vec2& other);


				friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);

			};
		}
	}
