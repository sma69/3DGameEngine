

#ifndef __OBJECTS_H__
#define __OBJECTS_H__

#include <iostream>
#include <vector>

#include "maths.h"
#include "vertex_array.h"
#include "glm/glm.hpp"


/* Header file for object classes and other resources
- SA
*/
namespace gt3d {

	class Obj
	{
	public:
		bool static loadOBJ(
			const char * path,
			std::vector < glm::vec3 > & out_vertices, std::vector < glm::vec2 > & out_uvs,
			std::vector < glm::vec3 > & out_normals
		);
	};
}




#endif