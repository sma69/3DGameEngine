#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <vector>

#include "model.h"
#include "maths.h"
#include "glm/glm.hpp"

#define MAX_ENTITIES 1024

namespace gt3d {
	/**
	const int maxEntity = 1024;
	static std::vector<Entity> entityList[maxEntity];
	static int entityMax = 0;
	static bool entityInitialized = false;
	*/
	class Entity
	{
	public:
		bool inuse = false;
		int uid;    /**<unique id of this entity*/
		char name[128];
		glm::vec3 acceleration;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::vec3 color;
		graphics::Model model;
		int state;
		float frame;

		

		void(*think)(struct Entity *self);

		
	};
	
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
	void entityDrawAll();
	void entityThinkAll();

	/**
	* @brief draws an entity
	* @param ent the entity to draw
	*/
	void entityDraw(Entity *ent);

	/**
	* @brief frees an entity
	*/
	void entityFree(Entity *ent);

	int entityIsEntity(void *data);

}
#endif