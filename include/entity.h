#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <iostream>
#include <vector>
#include <list>

#include "model.h"
#include "maths.h"
#include "body.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#define MAX_ENTITIES 1024

namespace gt3d {
	/**EntitySystem variables*/
	
	/**Entity SysClass*/
	class Entity
	{
	public:
		bool inuse = false;
		int uid;    /**<unique id of this entity*/
		char name[128];
		glm::mat4 transform = glm::mat4();
		
		glm::vec3 position;
		glm::vec3 acceleration; 
		glm::vec3 rotation; 
		glm::vec3 scale;
		glm::vec4 color;
		GLchar* objPath;
		graphics::Model *obj;	
		int state;
		float frame;
		graphics::Texture *texture;
		Body body;

		/**Entity Constructor*/
		Entity();

		virtual void draw(graphics::Shader shaderID);
		//virtual void update();
		
		
	};

	static Entity* entityList = NULL;
	static int entityMax = 0;
	static int entityInitialized = 0;

	static void entityDeinitialize();
	void entityInit(int maxEntity);

	class Player : public Entity {
	public:
		Player();

	/**Player entity functions from Entity*/
		//virtual void draw();
		//virtual void update();
			
	};

	class Enemy : public Entity {
	public:
		Enemy();


	};
	class FireEnemy : public Enemy {
	public:
		FireEnemy();

	};
	class ShockEnemy : public Enemy {
	public:
		ShockEnemy();

	};
	class IceEnemy : public Enemy {
	public:
		IceEnemy();
	};



	
	
	/**
	* @brief initialize the entity sub system
	* @param maxEntity the maximum number of simultaneously supported entities.
	*/
	//void entityInit(int maxEntity);

	//static void entityDeinitialize();

	///**
	//* @brief get a pointer to a new entity
	//* @return NULL on no more entities or error,  a valid entity pointer otherwise
	//*/
	//Entity *entityNew();

	///**
	//* @brief draws all active entities
	//*/
	//void entityDrawAll(graphics::Shader shaderID);
	//void entityThinkAll();

	///**
	//* @brief draws an entity
	//* @param ent the entity to draw
	//*/
	//void entityDraw(Entity *ent, graphics::Shader shaderID);

	///**
	//* @brief frees an entity
	//*/
	//void entityFree(Entity *ent);

	//int entityIsEntity(void *data);

}
#endif