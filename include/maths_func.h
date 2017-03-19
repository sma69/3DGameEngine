#pragma once
#include "maths.h"
#include <math.h>

namespace gt3d {
	namespace maths {



		//Degrees to radians
		inline float toRadians(float degrees)
		{
			return degrees * M_PI / 180.0f;
		}


	}
}