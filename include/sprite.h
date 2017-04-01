#pragma once

#include "graphics3d.h"
#include "glfw3.h"
#include "maths.h"
#include "SOIL.h"
#include "glm/glm.hpp"

#define MAXSPRITEFILENAME 512
#define MaxSprite 1024

namespace gt3d {
	/**This is the header for my Image/Texture loading sprite class - SA*/

	class Sprite {

		GLFWimage image;
	public:
		int width, height;
		
		/**This is my sprite loading loading function which takes in the file name 
			@brief    and the size vector of length followed by width*/


		Sprite* loadSprite(const char *fileName, glm::vec2 size);
		
		void freeSprite(Sprite* sprite);
		
	};
	



}