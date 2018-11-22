#include "Horchata.h"

Horchata g_ho;

Horchata::Horchata()
{
}

Horchata::~Horchata()
{
}

void Horchata::Iniciar()
{
	SonidosManager.InitEngine();
}

void Horchata::EnableTextShader(int _w, int _h) {
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(_w), 0.0f, static_cast<GLfloat>(_h));
	g_ho.shader.Use();
	glUniformMatrix4fv(glGetUniformLocation(g_ho.shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}

void Horchata::DisableTextShader() {
	glUseProgram(0);
}
