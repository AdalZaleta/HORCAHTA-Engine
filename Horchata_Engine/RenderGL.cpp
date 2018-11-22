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
		clipAreaXLeft=-100.0*aspect;
		clipAreaXRightt = 100.0*aspect;
		clipAreaYBottom = -100.0;
		clipAreaYTop = 100.0;
	}
	else
	{
		clipAreaXLeft = -100.0;
		clipAreaXRightt = 100.0;
		clipAreaYBottom = -100.0/aspect;
		clipAreaYTop = 100.0/aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Compilar el shader para el texto
	// Definicion del shader global
	//g_ho.shader.LoadShader("Resources/shaders/text.vs", "Resources/shaders/text.frag");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(w), 0.0f, static_cast<GLfloat>(h));
	//g_ho.shader.Use();
	//glUniformMatrix4fv(glGetUniformLocation(g_ho.shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	//testFont.LoadFont("Resources/Fonts/naruto.ttf", 32, 0);
	if (imagen.LoadImage_("GABO.jpg"))
	{
		std::cout << "Se cargo correctamente" << std::endl;
	}
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

	
	//Esto tiene que estar siempre
	g_ho.primitives.DrawAll();

	imagen.DrawImage(-10, -10, 100, 100);
}
