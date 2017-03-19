#ifndef __VECTOR_H__
#define __VECTOR_H__


	typedef union
	{
		struct
		{
			float x, y;


		};
		float v[2];
	}Vector2D;

	typedef union
	{
		struct
		{
			float x, y, z;
		};
		float v[3];
	}Vector3D;

	typedef union
	{
		struct
		{
			float x, y, z, w;
		};
		float v[4];
	}Vector4D;

	Vector2D vec2d(float x, float y);
	Vector3D vec3d(float x, float y, float z);
	Vector4D vec4d(float x, float y, float z, float w);

#define vector4d_add(a,b,c,d) (a.x = b.x + c.x + d.x, a.y=b.y + c.y + d.y, a.z=b.z + c.z + d.z )
#define vector4d_set(a,b,c,d,e) (a.x = b, a.y = c, a.z = d, a.w = e)

#define vector3d_add(a,b,c) (a.x = b.x + c.x, a.y=b.y + c.y, a.z=b.z + c.z )
#define vector3d_set(a,b,c,d) (a.x = b, a.y = c, a.z = d)

#define vector2d_add(a,b,c) (a.x = b.x + c.x, a.y=b.y + c.y)
#define vector2d_set(a,b,c) (a.x = b, a.y = c)

#endif