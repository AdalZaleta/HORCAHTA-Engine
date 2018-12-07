#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>
#include <windows.h>			// standard Windows app include
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define GRABBABLE_MASK_BIT (1<<31)
cpShapeFilter NOT_GRABBABLE_FILTER = { CP_NO_GROUP, ~GRABBABLE_MASK_BIT, ~GRABBABLE_MASK_BIT };
enum CollisionTypes {
	COLLISION_TYPE_ONE_WAY = 1,
};

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

	float camSize = 250.0f;

	if (w >= h)
	{
		clipAreaXLeft=-camSize *aspect;
		clipAreaXRightt = camSize *aspect;
		clipAreaYBottom = -camSize;
		clipAreaYTop = camSize;
	}
	else
	{
		clipAreaXLeft = -camSize;
		clipAreaXRightt = camSize;
		clipAreaYBottom = -camSize /aspect;
		clipAreaYTop = camSize /aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Compilar el shader para el texto
	// Definicion del shader global
	//g_ho.shader.LoadShader("Resources/shaders/text.vs", "Resources/shaders/text.frag");
	//glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(w), 0.0f, static_cast<GLfloat>(h));
	//g_ho.shader.Use();
	//glUniformMatrix4fv(glGetUniformLocation(g_ho.shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	//testFont.LoadFont("Resources/Fonts/naruto.ttf", 32, 0);

	g_ho.space = cpSpaceNew();
	cpSpaceSetIterations(g_ho.space, 10);
	cpSpaceSetGravity(g_ho.space, cpv(0, -100));
	cpBody *staticBody = cpSpaceGetStaticBody(g_ho.space);;
	cpShape *shape;

	//Contorno de la pantalla
	// Create segments around the edge of the screen.
	shape = cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(staticBody, cpv(-320, -240), cpv(-320, 240), 0.0f));
	cpShapeSetElasticity(shape, 1.0f);
	cpShapeSetFriction(shape, 1.0f);
	cpShapeSetFilter(shape, NOT_GRABBABLE_FILTER);

	shape = cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(staticBody, cpv(320, -240), cpv(320, 240), 0.0f));
	cpShapeSetElasticity(shape, 1.0f);
	cpShapeSetFriction(shape, 1.0f);
	cpShapeSetFilter(shape, NOT_GRABBABLE_FILTER);

	shape = cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(staticBody, cpv(-320, -240), cpv(320, -240), 0.0f));
	cpShapeSetElasticity(shape, 1.0f);
	cpShapeSetFriction(shape, 1.0f);
	cpShapeSetFilter(shape, NOT_GRABBABLE_FILTER);

	//Pelota
	cpFloat radius = 15.0f;
	g_ho.circulo = cpSpaceAddBody(g_ho.space, cpBodyNew(10.0f, cpMomentForCircle(10.0f, 0.0f, radius, cpvzero)));
	cpBodySetPosition(g_ho.circulo, cpv(0, -200));
	cpBodySetVelocity(g_ho.circulo, cpv(0, 170));

	shape = cpSpaceAddShape(g_ho.space, cpCircleShapeNew(g_ho.circulo, radius, cpvzero));
	cpShapeSetElasticity(shape, 0.0f);
	cpShapeSetFriction(shape, 0.9f);
	cpShapeSetCollisionType(shape, 2);

}

void RenderGL::liberar()
{
	cpSpaceFree(g_ho.space);
}

float hue = 0;

void RenderGL::update()
{
	hue += 0.01f;
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPointSize(15.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(g_ho.circulo->p.x, g_ho.circulo->p.y);
	glEnd();


	//------------ PRIMITIVAS EJEMPLOS ------------
	//Esto puede estar en cualquier parte de codigo, no es necesario ponerlo entre glBegin ni glEnd
	g_ho.primitives.DrawLine(hoVector2f(hue, 1), hoVector2f(1, 1));
	g_ho.primitives.DrawLine(hoVector2f(0, hue), hoVector2f(1, 1), g_ho.colorchata.adal);
	g_ho.primitives.DrawCircle(hoVector2f(hue, 0), 3, 64);
	g_ho.primitives.DrawPoint(hoVector2f(2, hue), 1);
	g_ho.primitives.DrawRect(hoVector2f(0, hue), hoVector2f(hue, 4));
	g_ho.primitives.DrawEllipse(hoVector2f(-hue, 3), 3.0f, 6.0f, 64);
	g_ho.primitives.FillCircle(hoVector2f(-hue, 4), 3, 32, g_ho.colorchata.sepia);
	g_ho.primitives.FillRect(hoVector2f(-hue, 2), hoVector2f(2, 3));
	g_ho.primitives.DrawLine(hoVector2f(0, -hue), hoVector2f(3, -hue));

	
	//Esto tiene que estar siempre
	g_ho.primitives.DrawAll();
}
