#pragma once

//include veectors and matrices
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"


namespace gt3d { namespace maths {



		//Degrees to radians
		float toRadians(float degrees)
		{
			return degrees * M_PI / 180.0f;
		}


} }
