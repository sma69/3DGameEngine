/**
* gametest3d
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
#include <iostream>
#include <glfw3.h>
#include "graphics3d.h"
#include "shader.h"
#include "maths.h"
#include "simple_logger.h"
#include "buffer.h"
#include "index_buffer.h"
#include "vertex_array.h"

#include "renderer2d.h"
#include "simple2drenderer.h"


int main()
{
	using namespace gt3d;
	using namespace maths;
	using namespace graphics;

	Window window("GameTest3D 2017", 960, 540);
	//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	/**Initialize my shaders*/
	Shader shader("basic.vert", "basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translate(vec3(4, 3, 0)));

	Renderable2D sprite(maths::vec3(0, 0, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	/**Sets Color and lighting*/
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));
	renderer.submit(&sprite);
	renderer.flush();

	while (!window.closed())
	{

		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));

		window.update();
	}


	return 0;
}
