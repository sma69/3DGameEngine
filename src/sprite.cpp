#include "sprite.h"

namespace gt3d {
	/**
	Sprite* loadSprite(const char *fileName, glm::vec2 size)
	{
		Sprite* sprite;
		int m_width = size.x;
		int m_height = size.y;
		unsigned char* image;

		image = SOIL_load_image(fileName, &m_width, &m_height, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB,
			GL_UNSIGNED_BYTE, image);
		
		return sprite;
	}
	*/

}