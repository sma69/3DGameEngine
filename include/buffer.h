#pragma once

#include <vector>
#include <GL/glew.h>

namespace gt3d {
	namespace graphics {

		class Buffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

			void bind() const;
			void unbind() const;

			GLuint getComponentCount() const {return m_ComponentCount;}
		
		};


} }