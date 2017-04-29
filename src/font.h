#pragma once

#include "ft2build.h"
#include "shader.h"
#include <map>

#include FT_FREETYPE_H

namespace gt3d {
	GLuint VAO, VBO;

	/*Render in each character of text that needs to be printed to screen*/
	struct Character {
		GLuint     TextureID;  /* ID handle of the glyph texture*/
		glm::ivec2 Size;       /* Size of glyph*/
		glm::ivec2 Bearing;    /* Offset from baseline to left/top of glyph*/
		GLuint     Advance;    /* Offset to advance to next glyph*/
	};
	std::map<GLchar, Character> Characters;

	void ftload(FT_Library ftLib, FT_Face ftFace);

	void RenderText(graphics::Shader &shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

	void ftdone(FT_Library ftlib, FT_Face ftFace);

}