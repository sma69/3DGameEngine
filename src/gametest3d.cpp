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
#include "entity.h"
#include "camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace gt3d;
using namespace graphics;
using namespace glm;

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
void doMovement(Window *window, glm::mat4 object);
void cameraMovement(Window *window, Camera cam, GLfloat dt);
void doMovement(Window *window, Entity *object)
{
	if (window->m_Keys[GLFW_KEY_W])
		object->transform = glm::translate(object->transform, glm::vec3(0.0f, 0.0f, -1.0f));
	if (window->m_Keys[GLFW_KEY_S])
		object->transform = glm::translate(object->transform, glm::vec3(0.0f, 0.0f, 1.0f));
	if (window->m_Keys[GLFW_KEY_A])
		object->transform = glm::translate(object->transform, glm::vec3(-1.0f, 0.0f, 0.0f));
	if (window->m_Keys[GLFW_KEY_D])
		object->transform = glm::translate(object->transform, glm::vec3(1.0f, 0.0f, 0.0f));
	if(window->m_Keys[GLFW_KEY_Q])
		object->transform = glm::rotate(object->transform, -0.05f, glm::vec3(0.0f, 1.0f, 0.0f));
	if (window->m_Keys[GLFW_KEY_E])
		object->transform = glm::rotate(object->transform, 0.05f, glm::vec3(0.0f, 1.0f, 0.0f));
	if (window->m_Keys[GLFW_KEY_SPACE])
		object->transform = glm::translate(object->transform, glm::vec3(0.0f, 1.0f, 0.0f));
	if (window->m_Keys[GLFW_KEY_LEFT_SHIFT])
		object->transform = glm::translate(object->transform, glm::vec3(0.0f, -1.0f, 0.0f));

}

							//initialize the camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main()
{
	
	

	Window window(w,"GameTest3D 2017", screenWidth, screenHeight);
	Window* pWindow = &window;
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
	
	entityInit(1024);

	glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = camera.getViewMatrix();

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader shader("basic.vert", "basic.frag");
	Shader shader2("vs1.glsl","fs1.glsl");
	Shader lightingShader("lightingVert.glsl", "lightingFrag.glsl");

	

	/**Initialize my UaI shaders*/ 
	
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


	
	/** Initialize my Scene Shaders*/
	

	


	/**Initialize Models*/
	Player *player = new Player();
	Entity *stage = new Entity();
	FireEnemy *enemy = new FireEnemy();
	ShockEnemy *enemy2 = new ShockEnemy();
	IceEnemy *enemy3 = new IceEnemy();

	

	
	// Draw the loaded  player model
	
	player->transform = glm::translate(player->transform, glm::vec3(0.0f, -3.0f, -3.0f)); // Translate it down a bit so it's at the center of the scene
	player->transform = glm::scale(player->transform, glm::vec3(0.4f, 0.4f, 0.4f));	// It's a bit too big for our scene, so scale it down

	stage->obj = new Model("forestStage/forestStage.obj");
	stage->transform = glm::scale(player->transform, glm::vec3(3.0f, 1.0f, 3.0f));


	enemy->transform = glm::translate(enemy->transform, glm::vec3(3.0f, -3.0f, -7.0f)); // Translate it down a bit so it's at the center of the scene
	enemy->transform = glm::scale(enemy->transform, glm::vec3(0.4f, 0.4f, 0.4f));	// It's a bit too big for our scene, so scale it down

	enemy2->transform = glm::translate(enemy2->transform, glm::vec3(-5.0f, -2.0f, -7.0f)); // Translate it down a bit so it's at the center of the scene
	enemy2->transform = glm::scale(enemy2->transform, glm::vec3(0.5f, 0.5f, 0.5f));	// It's a bit too big for our scene, so scale it down

	enemy3->transform = glm::translate(enemy3->transform, glm::vec3(5.0f, -1.0f, -5.0f)); // Translate it down a bit so it's at the center of the scene
	enemy3->transform = glm::scale(enemy3->transform, glm::vec3(0.7f, 0.7f, 0.7f));	// It's a bit too big for our scene, so scale it down
	
	/**Game Loop*/
	while (!window.closed())
	{
		/**Set frame Time*/
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		window.clear();
		double x, y;
		window.getMousePosition(x, y);
	/*	shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		
		renderer.submit(&healthBar);
		renderer.submit(&manaBar);
		renderer.flush();*/


		projection = glm::perspective(camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		view = camera.getViewMatrix();
		// Pass the matrices to the shader
		shader2.enable();
		shader2.setUniformMat4("projection", projection);
		shader2.setUniformMat4("view", view);
		
		enemy->transform = glm::rotate(enemy->transform, 0.05f ,glm::vec3(0.0f, 1.0f, 0.0f));
		//enemy2->transform = glm::rotate(enemy2->transform, 0.05f, glm::vec3(0.0f, 1.0f, 0.0f));
		enemy3->transform = glm::rotate(enemy3->transform, 0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
		//player->transform = glm::rotate(player->transform, 0.05f, glm::vec3(0.0f, 1.0f, 0.0f));
	

	//shader2.setUniformMat4("model", stage->transform);
		(*stage).draw(shader2);
		(*player).draw(shader2);
		(*enemy).draw(shader2);
		(*enemy2).draw(shader2);
		(*enemy3).draw(shader2);

		//Camera lookAt player
		glm::lookAt(camera.Position, player->position, camera.Up);
		//player controls
		doMovement(pWindow, player);

		// Camera controls
		if (pWindow->m_Keys[GLFW_KEY_UP])
			camera.ProcessKeyboard(FORWARD, deltaTime);
		if (pWindow->m_Keys[GLFW_KEY_DOWN])
			camera.ProcessKeyboard(BACKWARD, deltaTime);
		if (pWindow->m_Keys[GLFW_KEY_LEFT])
			camera.ProcessKeyboard(LEFT, deltaTime);
		if (pWindow->m_Keys[GLFW_KEY_RIGHT])
			camera.ProcessKeyboard(RIGHT, deltaTime);

		cameraMovement(pWindow, camera, deltaTime);
		
		window.update();
	}

	
	return 0;
}

void cameraMovement(Window *window, Camera cam, GLfloat dt)
{
	// Camera controls
	if (window->m_Keys[GLFW_KEY_UP])
		cam.ProcessKeyboard(FORWARD, dt);
	if (window->m_Keys[GLFW_KEY_DOWN])
		cam.ProcessKeyboard(BACKWARD, dt);
	if (window->m_Keys[GLFW_KEY_LEFT])
		cam.ProcessKeyboard(LEFT, dt);
	if (window->m_Keys[GLFW_KEY_RIGHT])
		cam.ProcessKeyboard(RIGHT, dt);

}