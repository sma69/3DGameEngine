#ifndef __BODY_H__
#define __BODY_H__


#include "collisions.h"
#include "mglCallback.h"

namespace gt3d {


	typedef struct
	{
		glm::vec3 position;
		glm::vec3 velocity;
		Cube bounds;
		MglCallback touch;
		int  _needsBackoff;
		int  _done;
		glm::vec3 _stepOffVector;
	}Body;

	/**
	* @brief resets a body pre-physics calculation
	* @param body the body to reset
	*/
	void body_reset(Body *body);

	/**
	* @brief applies any post physics processing needed for the body
	* @param body the body to process
	*/
	void body_process(Body *body);
}
#endif