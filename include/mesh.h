#ifndef __MESH_H__
#define __MESH_H__


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "shader.h"
#include "graphics3d.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace gt3d {
	namespace graphics {

		struct Vertex {
			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec2 TexCoords;
		};

		struct Texture {
			GLuint id;
			std::string type;
			aiString path;
		};

		class Mesh {
		public:
			/*  Mesh Data  */
			std::vector<Vertex> vertices;
			std::vector<GLuint> indices;
			std::vector<Texture> textures;
			/*  Functions  */
			/**Constructor */
			Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
			
			/** Draw mesh from file*/
			void Draw(Shader shader);
		private:
			/*  Render data  */
			GLuint VAO, VBO, EBO;
			/*  Functions    */
			void setupMesh();
		};
		/**
		@brief load an obj file into the mesh data type
		@param filename the path to the obj file to load
		@returns NULL on error or an allocated mesh datastructure
		*/
		Mesh * mesh_load_from_obj(char * filename);

		/**
		@brief frees the data associated with the mesh and set the pointer to NULL
		@param mesh a pointer to your mesh pointer
		*/
		void mesh_free(Mesh **mesh);
	}
}
#endif