#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "obj.h"
#include "maths.h"
#include "glm/glm.hpp"

namespace gt3d {
	typedef struct Entity
	{
		int inuse;
		int uid;    /**<unique id of this entity*/
		char name[128];
		glm::vec3 acceleration;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::vec3 color;
		Obj *objModel;
		Obj *objAnimation[24];
		int state;
		float frame;

		void(*think)(struct Entity *self);
	};

	/**
	* @brief initialize the entity sub system
	* @param maxEntity the maximum number of simultaneously supported entities.
	*/
	void entity_init(int maxEntity);

	/**
	* @brief get a pointer to a new entity
	* @return NULL on no more entities or error,  a valid entity pointer otherwise
	*/
	Entity *entity_new();

	/**
	* @brief draws all active entities
	*/
	void entity_draw_all();
	void entity_think_all();

	/**
	* @brief draws an entity
	* @param ent the entity to draw
	*/
	void entity_draw(Entity *ent);

	/**
	* @brief frees an entity
	*/
	void entity_free(Entity *ent);

	int entity_is_entity(void *data);
}
#endif