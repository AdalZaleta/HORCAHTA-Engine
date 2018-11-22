#pragma once

// STD includes
#include <map>
#include <iostream>
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// GLM
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Free Type
#include <ft2build.h>
#include FT_FREETYPE_H
// GL includes
#include "Shader.h"

#include "SDL.h"

class hoText2 {
public:
	void LoadFont(const char* path, FT_UInt w, FT_UInt h);
	void RenderText(Shader shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

	struct Character {
		GLuint TextureID;   // ID del glyph texture
		glm::ivec2 Size;    // Tamaño del glyph
		glm::ivec2 Bearing;  // Offset desde la base a izquierda/arriba del glyph
		GLuint Advance;    // Offset horizontal para avanzar al siguiente glyph
	};
	std::map<GLchar, Character> Characters;
	GLuint VAO, VBO;

	int W;
	int H;

private:

};