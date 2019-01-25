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

/*
	Para poder usar hoText2 se tiene que cargar la fuente en inicializar primero y ya en render
	se habilita el TextShader(), pones el texto que quieres renderear y después finalizas el TextShader()
	usando DisableTextShader()

	Ejemplo:
	-Declarar variable en RenderGL.h
		hoText2 txt;

	-En "RenderGL::Inicializar()"
		txt.LoadFont(w, h, "Resources/Fonts/DTM.otf", 0, 32, g_ho.shader);


	-En "RenderGL::Render()"
		g_ho.EnableTextShader();
			txt.RenderText("00", w/2, h - 70, 1.3, glm::vec3(1, 1, 1));
		g_ho.DisableTextShader();

*/

class hoText2 {
public:
	void LoadFont(int _w, int _h, const char* path, FT_UInt w, FT_UInt h, Shader _shader);
	void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
	void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, float angle, glm::vec3 color);

	Shader shader;

	struct Character {
		GLuint TextureID;   // ID del glyph texture
		glm::ivec2 Size;    // Tamaño del glyph
		glm::ivec2 Bearing;  // Offset desde la base a izquierda/arriba del glyph
		GLuint Advance;    // Offset horizontal para avanzar al siguiente glyph
	};
	std::map<GLchar, Character> Characters;
	GLuint VAO, VBO;

	int screenW, screenH;

private:

};