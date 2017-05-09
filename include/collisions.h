#ifndef __COLLISIONS_H__
#define __COLLISIONS_H__

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace gt3d {
	typedef struct
	{
		float x, y, z;
		float w, h, d;
	}Cube;

#define cube_set(cube,a,b,c,l,m,n) (cube.x=a,cube.y=b,cube.z=c,\
                                    cube.w=l,cube.h=m,cube.d=n)
	int sphere_sphere_intersection(
		glm::vec3 c1, float r1,   /*sphere 1*/
		glm::vec3 c2, float r2    /*sphere 2*/
	);

	int cube_cube_intersection(
		Cube a,
		Cube b);

		
	int point_cube_intersection(
		glm::vec3 point,            /*point*/
		glm::vec3 box, glm::vec3 size); /*cube*/

	int sphere_cube_intersection(
		glm::vec3 center, float r,   /*sphere*/
		glm::vec3 box, glm::vec3 size);  /*axis aligned 3d cube*/
}

#endif