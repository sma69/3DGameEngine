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
#include "simple_logger.h"
#include "graphics3d.h"
#include "shader.h"
#include "obj.h"
#include "vector.h"
#include "sprite.h"
#include "entity.h"


void set_camera(Vector3D position, Vector3D rotation);

void think(Entity *self)
{
	if (!self)return;
	switch (self->state)
	{
	case 0:
		self->frame = 0;
		break;
	case 1:
		self->frame += 0.3;
		if (self->frame >= 24)self->frame = 0;
		break;
	case 2:
		self->frame -= 0.3;
		if (self->frame < 0)self->frame = 23;
		break;
	}
	self->objModel = self->objAnimation[(int)self->frame];
}

int main(int argc, char *argv[])
{
	GLuint vao;
	GLuint triangleBufferObject;
	char bGameLoopRunning = 1;
	SDL_Event e;
	Obj *player;
	Vector3D cameraPosition = { 0,-10,0.3 };
	Vector3D cameraRotation = { 90,0,0 };
	const float triangleVertices[] = {
		0.0f, 0.5f, 0.0f, 1.0f,
		0.5f, -0.366f, 0.0f, 1.0f,
		-0.5f, -0.366f, 0.0f, 1.0f,
		//next part contains vertex colors
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f
	}; //we love you vertices!

	init_logger("gametest3d.log");
	slog("Program begin");
	if (graphics3d_init(1024, 768, 1, "gametest3d", 33) != 0)
	{
		return -1;
	}

	model_init();
	obj_init();
	entity_init(255);

	player = obj_load("models/cube.obj");



	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao); //make our vertex array object, we need it to restore state we set after binding it. Re-binding reloads the state associated with it.

	glGenBuffers(1, &triangleBufferObject); //create the buffer
	glBindBuffer(GL_ARRAY_BUFFER, triangleBufferObject); //we're "using" this one now
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW); //formatting the data for the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0); //unbind any buffers

	slog("glError: %d", glGetError());

	while (bGameLoopRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				bGameLoopRunning = 0;
			else if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					bGameLoopRunning = 0;
				}
				else if (e.key.keysym.sym == SDLK_SPACE)
				{
					cameraPosition.z++;
				}
				else if (e.key.keysym.sym == SDLK_z)
				{
					cameraPosition.z--;
				}
				else if (e.key.keysym.sym == SDLK_w)
				{
					vector3d_add(
						cameraPosition,
						cameraPosition,
						vec3d(
							-sin(cameraRotation.z * DEGTORAD),
							cos(cameraRotation.z * DEGTORAD),
							0
						));
				}
				else if (e.key.keysym.sym == SDLK_s)
				{
					vector3d_add(
						cameraPosition,
						cameraPosition,
						vec3d(
							sin(cameraRotation.z * DEGTORAD),
							-cos(cameraRotation.z * DEGTORAD),
							0
						));
				}
				else if (e.key.keysym.sym == SDLK_d)
				{
					vector3d_add(
						cameraPosition,
						cameraPosition,
						vec3d(
							cos(cameraRotation.z * DEGTORAD),
							sin(cameraRotation.z * DEGTORAD),
							0
						));
				}
				else if (e.key.keysym.sym == SDLK_a)
				{
					vector3d_add(
						cameraPosition,
						cameraPosition,
						vec3d(
							-cos(cameraRotation.z * DEGTORAD),
							-sin(cameraRotation.z * DEGTORAD),
							0
						));
				}
				else if (e.key.keysym.sym == SDLK_LEFT)
				{
					cameraRotation.z += 1;
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					cameraRotation.z -= 1;
				}
				else if (e.key.keysym.sym == SDLK_UP)
				{
					cameraRotation.x += 1;
				}
				else if (e.key.keysym.sym == SDLK_DOWN)
				{
					cameraRotation.x -= 1;
				}
			}

			glClearColor(0.0, 0.0, 0.0, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);

			/* drawing code in here! */
			glUseProgram(graphics3d_get_shader_program());

			glBindBuffer(GL_ARRAY_BUFFER, triangleBufferObject); //bind the buffer we're applying attributes to
			glEnableVertexAttribArray(0); //0 is our index, refer to "location = 0" in the vertex shader
			glEnableVertexAttribArray(1); //attribute 1 is for vertex color data

			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); //tell gl (shader!) how to interpret our vertex data
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)(12 * sizeof(float))); //color data is 48 bytes in to the array

			glDrawArrays(GL_TRIANGLES, 0, 3);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);


			glUseProgram(0);
			/* drawing code above here! */

			entity_draw_all();
			glPushMatrix();
			glTranslatef(-5, 0, 0);
			obj_draw(
				player,
				vec3d(0, 0, 0),
				vec3d(0, 0, 0),
				vec3d(1, 1, 1),
				vec4d(1, 0, 0, 1),
				NULL
			);
			
			graphics3d_next_frame();
		}
		return 0;
	}
}

void set_camera(Vector3D position, Vector3D rotation)
{
	glRotatef(-rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(-rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(-rotation.z, 0.0f, 0.0f, 1.0f);
	glTranslatef(-position.x,
		-position.y,
		-position.z);
}
/*eol@eof*/