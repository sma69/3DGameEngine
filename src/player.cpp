#include "entity.h"

namespace gt3d 
{
	Entity *newPlayer(glm::vec3 Position, const char *name)
	{
		Entity *ent;
		char buffer[255];
		int i;
		ent = entityNew();
		if (!ent)
		{
			return NULL;
		}

		ent->objPath = "player/BossModel.obj";
		ent->position = Position;

	}

}