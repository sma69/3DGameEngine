#pragma once

#include <GL/glew.h>

#include "buffer.h"

namespace gt3d { namespace graphics {

	/*This class is to make sure each buffer on a Triangle is different.
		This is an array of Buffers.
	*/
	class VertexArray
	{
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers;
	public:
		VertexArray();
		~VertexArray();
		void addBuffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind() const;

	};


} }