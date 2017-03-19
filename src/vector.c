#include "vector.h"


Vector2D vec2d(float x, float y)
{
	Vector2D v = { x,y };
	return v;
}

Vector3D vec3d(float x, float y, float z)
{
	Vector3D v = { x,y,z };
	return v;
}

Vector4D vec4d(float x, float y, float z, float w)
{
	Vector4D v = { x,y,z,w };
	return v;
}
