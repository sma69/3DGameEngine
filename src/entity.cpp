#include "entity.h"

namespace gt3d {

	/**

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

	*/
}