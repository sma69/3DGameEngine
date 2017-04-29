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
#include "obj.h"
#include "model.h"
#include "camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace gt3d;

GLFWwindow *w;
// Camera Properties
// Window dimensions
const GLuint screenWidth = 960, screenHeight = 540;

// Camera
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
GLfloat yaw = -90.0f;
GLfloat pitch = 0.0f;

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame
bool keys[1024];
void doMovement(glm::mat4 object);
void do_Movement();

							//initialize the camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main()
{
	
	using namespace glm;
	using namespace graphics;

	Window window(w,"GameTest3D 2017", screenWidth, screenHeight);
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);



	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader shader("basic.vert", "basic.frag");
	Shader shader2("vs1.glsl","fs1.glsl");

	

	/**Initialize my UI shaders*/ 
	
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", glm::translate(glm::mat4(1.0f),glm::vec3(0, 0, 0)));
	
	/** Initialize interface*/
	Renderable2D healthBar(glm::vec3(0, 8, 0), glm::vec2(5, 0.75), glm::vec4(1, 0, 0, 1), shader);
	Renderable2D manaBar(glm::vec3(0, 7.3, 0), glm::vec2(3.5, 0.5), glm::vec4(0, 0, 1, 1), shader);

	Simple2DRenderer renderer;

	/**Sets Color and lighting*/

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.5f, 0.3f, 0.0f, 1.0f));

	renderer.submit(&healthBar);
	renderer.submit(&manaBar);

	renderer.flush();
	
	/** Initialize my Scene Shaders*/
	

	// Pass the matrices to the shader
	shader2.enable();
	glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = camera.getViewMatrix();
	shader2.setUniformMat4("projection", projection);
	shader2.setUniformMat4("view", view);


	/**Initialize Models*/
	Model player("BossModel.obj");


	
	
	// Draw the loaded model
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(0.0f, -3.0f, -3.0f)); // Translate it down a bit so it's at the center of the scene
	model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));	// It's a bit too big for our scene, so scale it down

	/**Game Loop*/
	while (!window.closed())
	{
		
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		//shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		
		
		model = glm::rotate(model, 0.05f ,glm::vec3(0.0f, 1.0f, 0.0f));
		shader2.setUniformMat4("model", model);
		player.Draw(shader2);

	
		
		do_Movement();
		window.update();
	}

	
	return 0;
}

void do_Movement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
}
void doMovement(glm::mat4 object)
{

	// Camera controls
	if (keys[GLFW_KEY_W])
		object = glm::translate(object, glm::vec3(0.0f, 1.0f, 0.0f));
	if (keys[GLFW_KEY_S])
		object = glm::translate(object, glm::vec3(0.0f, -1.0f, 0.0f));
	if (keys[GLFW_KEY_A])
		object = glm::translate(object, glm::vec3(-1.0f, 0.0f, 0.0f));
	if (keys[GLFW_KEY_D])
		object = glm::translate(object, glm::vec3(1.0f, 1.0f, 0.0f));
}