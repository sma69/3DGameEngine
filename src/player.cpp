#include "entity.h"

namespace gt3d 
{
	/*Entity *newPlayer(glm::vec3 Position, const char *name)
	{
		Entity *ent;
		char buffer[255];
		int i;
		ent = entityNew();
		if (!ent)
		{
			return NULL;
		}
		ent->matrix = glm::mat4(1.0f);
		ent->objPath = "player/BossModel.obj";
		ent->obj = graphics::Model::Model(ent->objPath);
		ent->position = Position;
		ent->matrix = glm::translate(ent->matrix, ent->position);
		return ent;

	}*/
	Player::Player()
	{
		this->obj = new graphics::Model("player/BossModel.obj");
	};
}