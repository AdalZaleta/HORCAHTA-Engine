#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>


#include <windows.h>			// standard Windows app include
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{

}
RenderGL::~RenderGL()
{

}

void RenderGL::inicializar()
{
	GLenum error = GL_NO_ERROR;
	//Para obtener error: error = glGetError();

	//Inicializamos Matrix
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect =(float)w / (float)h;

	if (w >= h)
	{
		clipAreaXLeft = -10.0*aspect;
		clipAreaXRightt = 10.0*aspect;
		clipAreaYBottom = -10.0;
		clipAreaYTop = 10.0;
	}
	else
	{
		clipAreaXLeft = -10.0;
		clipAreaXRightt = 10.0;
		clipAreaYBottom = -10.0/aspect;
		clipAreaYTop = 10.0/aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Setup para el shader de texto
	g_ho.shader.LoadShader("Resources/Shaders/text.vs", "Resources/shaders/text.frag");

	//TEMP
	testFont.LoadFont(w, h, "Resources/Fonts/DTM.otf", 0, 32, g_ho.shader);
}

void RenderGL::liberar()
{
}

void RenderGL::update()
{
	
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	g_ho.EnableTextShader(); // Activar Shader para renderizar texto
		// Aqui va todo el texto
		testFont.RenderText("[ - test - ]", 0, 0, 1, 15, glm::vec3(1, 1, 1));
		testFont.RenderText("[ - test - ]", 100, 0, 1, 15, glm::vec3(1, 1, 1));
		testFont.RenderText("[ - test - ]", 200, 0, 1, 15, glm::vec3(1, 1, 1));
		testFont.RenderText("[ - test - ]", 300, 0, 1, 15, glm::vec3(1, 1, 1));
		testFont.RenderText("[ - test - ]", 400, 0, 1, 15, glm::vec3(1, 1, 1));
	g_ho.DisableTextShader(); // Descativar Shader de texto

	//Esto tiene que estar siempre
	g_ho.primitives.DrawAll();

	glColor3f(0.7f, 0.0f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(0.0f, 0.75f);
	glVertex2f(1.0f, -1.0f);
	glEnd();
}
