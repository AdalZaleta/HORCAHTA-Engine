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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

	// Compilar el shader para el texto
	// Definicion del shader global
	shader.LoadShader("Resources/shaders/text.vs", "Resources/shaders/text.frag");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(WIDTH), 0.0f, static_cast<GLfloat>(HEIGHT));
	shader.Use();
	glUniformMatrix4fv(glGetUniformLocation(shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	// Cargar fuentes con su ancho y alto
	DTMfont.LoadFont("Resources/Fonts/DTM.otf", 0, 28);
	SAOfont.LoadFont("Resources/Fonts/SAO.otf", 0, 64);
	OPTfont.LoadFont("Resources/Fonts/OptimusPrinceps.ttf", 0, 82);
	GRSfont.LoadFont("Resources/Fonts/GrapeSoda.ttf", 0, 128);
	GSTfont.LoadFont("Resources/Fonts/webdings.ttf", 0, 32);
	CNTfont.LoadFont("Resources/Fonts/CounterDial.ttf", 0, 128);
	DOMfont.LoadFont("Resources/Fonts/Doom.ttf", 0, 256);
	NJAfont.LoadFont("Resources/Fonts/naruto.ttf", 0, 128);
	SPKfont.LoadFont("Resources/Fonts/fears.ttf", 0, 164);
	MEXfont.LoadFont("Resources/Fonts/Mex.ttf", 0, 32);
	SGNfont.LoadFont("Resources/Fonts/badSignal.otf", 0, 64);

	/*
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
	*/
	/* https://stackoverflow.com/questions/16583461/display-a-text-using-a-sdl-surface-converted-in-a-texture */
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

	// Dibujar texto
	DOMfont.RenderText(shader, "D", 100.0f, 300.0f, 1.0f, glm::vec3(0.43f, 0.43f, 0.43f));
	CNTfont.RenderText(shader, "Hello, World!", 250.0f, 50.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	NJAfont.RenderText(shader, "NARUTO", 300.0f, 700.0f, 1.0f, glm::vec3(0.88f, 0.48f, 0.0f));
	SPKfont.RenderText(shader, "SPOOKD", 800.0f, 700.0f, 1.0f, glm::vec3(0.80f, 0.03f, 0.03f));
	MEXfont.RenderText(shader, "ora puto no me estes picoteando!", 800.0f, 250.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	SGNfont.RenderText(shader, "ERROR", 500.0f, 1000.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	GSTfont.RenderText(shader, "DARK DARKER YET DARKER", 0.0f, 0.0f, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	//SAOfont.RenderText(shader, "This is SAO", 25.0f, 50.0f, 1.0f, glm::vec3(0.25f, 0.52f, 0.95f));
	//OPTfont.RenderText(shader, "This is Optimus Princeps", 25.0f, 100.0f, 0.75f, glm::vec3(0.68f, 0.08f, 0.05f));
	//GRSfont.RenderText(shader, "This is Grape Soda", 25.0f, 150.0f, 0.6f, glm::vec3(0.47f, 0.03f, 0.62f));
}
