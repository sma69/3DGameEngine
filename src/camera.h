#pragma once
#include <vector>


#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace gt3d {

	class Camera {
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		
	public:
		Camera(glm::vec3 position, glm::vec3 rotation);

	};
}