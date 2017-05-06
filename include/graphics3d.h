#ifndef __GRAPHICS3D_H__
#define __GRAPHICS3D_H__

/**
* simple_logger
* @license The MIT License (MIT)
*   @copyright Copyright (c) 2015 EngineerOfLies
*    Permission is hereby granted, free of charge, to any person obtaining a copy
*    of this software and associated documentation files (the "Software"), to deal
*    in the Software without restriction, including without limitation the rights
*    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*    copies of the Software, and to permit persons to whom the Software is
*    furnished to do so, subject to the following conditions:
*    The above copyright notice and this permission notice shall be included in all
*    copies or substantial portions of the Software.
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*    SOFTWARE.
*/
#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>

#include "camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

/**
* @brief initialize the 3d graphics system
* @param sw the screen width you want
* @param sh the screen height you want
* @param fullscreen set true to initialize to fullscreen
* @param project the name to appear on the game window
* @param frameDelay the desired delay (in ms) between frames
* @return -1 on error, 0 otherwise
*/

namespace gt3d {
	namespace graphics {

#define MAX_KEYS		1024
#define MAX_BUTTONS		32





		class Window
		{

		private:
			friend struct GLFWwindow;
			const char *m_Title;
			int m_Width, m_Height;
			bool m_Closed;

			


			/*Define Keys and buttons*/
		public:
			GLFWwindow *m_Window;
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double mx, my;

			
		


			Window(GLFWwindow *window, const char *name, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			/*Screen Width*/
			int getWidth() const { return m_Width; }
			int getHeight() const { return m_Height; }
			
			/*Key is Pressed*/
			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;
			void doMovement();
		
		private:
			bool init();

			/*Input Callbacks*/
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mode);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

			

		};

		
	}
}
#endif