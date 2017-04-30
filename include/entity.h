#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <iostream>
#include <vector>
#include <list>

#include "model.h"
#include "maths.h"
#include "glm/glm.hpp"

#define MAX_ENTITIES 1024

namespace gt3d {
	

	class Entity
	{
	public:
		bool inuse = false;
		int uid;    /**<unique id of this entity*/
		char name[128];
		glm::mat4 matrix;
		glm::vec3 position;
		glm::vec3 acceleration;
		glm::vec3 rotation; 
		glm::vec3 scale;
		glm::vec4 color;
		GLchar* objPath;
		graphics::Model model;
		graphics::Model modelAnimation[24];
		int state;
		float frame;
		graphics::Texture *texture;

		/**Entity Constructor*/
		//Entity(glm::vec3 position, std::string path);

		void(*think)(class Entity *self);
		
	};

	/**Player entity function from Entity*/
	Entity *newPlayer(glm::vec3 Position, const char *name);
	
	/**
	* @brief initialize the entity sub system
	* @param maxEntity the maximum number of simultaneously supported entities.
	*/
	void entityInit(int maxEntity);

	static void entityDeinitialize();

	/**
	* @brief get a pointer to a new entity
	* @return NULL on no more entities or error,  a valid entity pointer otherwise
	*/
	Entity *entityNew();

	/**
	* @brief draws all active entities
	*/
	void entityDrawAll(graphics::Shader shaderID);
	void entityThinkAll();

	/**
	* @brief draws an entity
	* @param ent the entity to draw
	*/
	void entityDraw(Entity *ent, graphics::Shader shaderID);

	/**
	* @brief frees an entity
	*/
	void entityFree(Entity *ent);

	int entityIsEntity(void *data);

}
#endif