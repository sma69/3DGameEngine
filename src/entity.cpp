#include "entity.h"

namespace gt3d {

	/*const int maxEntity = 1024;
	static std::vector<Entity> entityList[maxEntity];

	static int entityMax = 0;
	static bool entityInitialized = false;*/

	static Entity *entityList = NULL;
	static int entityMax = 0;
	static int entityInitialized = 0;

	static void entityDeinitialize();

	void entityInit(int maxEntity)
	{
		if (entityInitialized)
		{
			printf("already initialized");
			return;
		}
		entityMax = maxEntity;
		entityInitialized = true;
	}
	
	void entityFree(Entity *ent)
	{
		if (!ent)
		{
			printf("passed a null entity");
			return;
		}
	}

	static void entityDeinitialize()
	{
		int i;
		for (i = 0; i < entityMax; i++)
		{
			if (entityList[i].inuse)
			{
				entityFree(&entityList[i]);
			}
		}
		free(entityList);
		entityMax = 0;
		entityInitialized = 0;
	}

	Entity *entityNew()
	{
		int i;
		for (i = 0; i < entityMax; i++)
		{
			if (!entityList[i].inuse)
			{
				memset(&entityList[i], 0, sizeof(Entity));
				entityList[i].inuse = 1;
				entityList[i].scale = glm::vec3(1, 1, 1);
				entityList[i].color = glm::vec4(1, 1, 1, 1);
				return &entityList[i];
			}
		}
	}

	void entityThinkAll()
	{
		int i;
		for (i = 0; i < entityMax; i++)
		{
			if ((entityList[i].inuse) && (entityList[i].think != NULL))
			{
				entityList[i].think(&entityList[i]);
			}
		}
	}
	
	void entityDrawAll(graphics::Shader shaderID)
	{
		int i;
		for (i = 0; i < entityMax; i++)
		{
			if (entityList[i].inuse)
			{
				entityDraw(&entityList[i],shaderID);
			}
		}
	}

	void entityDraw(Entity *ent, graphics::Shader shaderID)
	{
		if (!ent)
		{
			return;
		}
		ent->model = graphics::Model::Model(ent->objPath);
		shaderID.setUniformMat4("model", ent->matrix);
		ent->model.Draw(shaderID);
	}
	
	int entityIsEntity(void *data)
	{
		if (!data)
			return 0;
		if (!entityInitialized)
			return 0;
		if ((Entity *)data < entityList)
			return 0;
		if ((Entity *)data >= (entityList + entityMax))
			return 0;
		return 1;
	}

}