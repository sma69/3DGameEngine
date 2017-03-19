#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include "maths.h"
#include "fileutils.h"

namespace gt3d { namespace graphics {


	class Shader
	{
	private:
		GLuint m_ShaderID;
		const char *m_VertPath;
		const char *m_FragPath;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		/**Functions set values for shaders in file*/
		void setUniform1f(const GLchar* name, float value);
		void setUniform1i(const GLchar* name, int value);
		void setUniform2f(const GLchar* name, const maths::vec2& vector);
		void setUniform3f(const GLchar* name, const maths::vec3& vector);
		void setUniform4f(const GLchar* name, const maths::vec4& vector);
		void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

		void enable() const;
		void disable() const;
	private:
		GLuint load();
		/**Gets values for shaders in function*/
		GLint getUniformLocation(const GLchar* name);

	};




} }