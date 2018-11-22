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

void Horchata::EnableTextShader() {
	g_ho.shader.Use();
}

void Horchata::DisableTextShader() {
	glUseProgram(0);
}
