#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include "hoText.h"
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float aspect =(float)w / (float)h;

	if (w >= h)
	{
		clipAreaXLeft=-10.0*aspect;
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
	//Initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	////myFont.TEMP_CreateBitmapFont("Arial", 48);
	fontBoi.LoadFont();
	GLint nbOfColors;
	GLenum texture_format = 0;

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	// Set the texture's stretching properties
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage2D(GL_TEXTURE_2D, 0, nbOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	/*https://stackoverflow.com/questions/16583461/display-a-text-using-a-sdl-surface-converted-in-a-texture*/
}

void RenderGL::liberar()
{
	//delete this
	//myFont.TEMP_ReleaseFont();
}

void RenderGL::update()
{

}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0.0f, 0.0f, -1.0f);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(-0.35f, 0.0f);
	//myFont.TEMP_DrawText("Hello, World!");

	fontBoi.RenderText("Sample Text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
}
