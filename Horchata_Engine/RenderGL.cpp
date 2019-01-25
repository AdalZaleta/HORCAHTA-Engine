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

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Setup para el shader de texto
	g_ho.shader.LoadShader("Resources/Shaders/text.vs", "Resources/shaders/text.frag");

	//g_ho.space = cpSpaceNew();
	//cpSpaceSetIterations(g_ho.space, 10);
	//cpSpaceSetGravity(g_ho.space, cpv(0, -100));
	//cpBody *staticBody = cpSpaceGetStaticBody(g_ho.space);;
	//cpShape *shape;

	////Contorno de la pantalla
	//// Create segments around the edge of the screen.
	//shape = cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(staticBody, cpv(-320, -240), cpv(-320, 240), 0.0f));
	//cpShapeSetElasticity(shape, 1.0f);
	//cpShapeSetFriction(shape, 1.0f);
	//cpShapeSetFilter(shape, NOT_GRABBABLE_FILTER);

	//shape = cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(staticBody, cpv(320, -240), cpv(320, 240), 0.0f));
	//cpShapeSetElasticity(shape, 1.0f);
	//cpShapeSetFriction(shape, 1.0f);
	//cpShapeSetFilter(shape, NOT_GRABBABLE_FILTER);

	//shape = cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(staticBody, cpv(-320, -240), cpv(320, -240), 0.0f));
	//cpShapeSetElasticity(shape, 1.0f);
	//cpShapeSetFriction(shape, 1.0f);
	//cpShapeSetFilter(shape, NOT_GRABBABLE_FILTER);

	////Pelota
	//cpFloat radius = 15.0f;
	//g_ho.circulo = cpSpaceAddBody(g_ho.space, cpBodyNew(10.0f, cpMomentForCircle(10.0f, 0.0f, radius, cpvzero)));
	//cpBodySetPosition(g_ho.circulo, cpv(0, -200));
	//cpBodySetVelocity(g_ho.circulo, cpv(0, 170));

	//shape = cpSpaceAddShape(g_ho.space, cpCircleShapeNew(g_ho.circulo, radius, cpvzero));
	//cpShapeSetElasticity(shape, 0.0f);
	//cpShapeSetFriction(shape, 0.9f);
	//cpShapeSetCollisionType(shape, 2);

	////-----------------------	HORCHATA SECTION	--------------------------------------
	 
	//Init Text
	txt.LoadFont(w, h, "Resources/Fonts/DTM.otf", 0, 32, g_ho.shader);
	//Init Font
	sprite.LoadImage_("Bolita.png");
}

void RenderGL::liberar()
{
	cpSpaceFree(g_ho.space);
}

float hue = 0;

void RenderGL::update()
{
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	g_ho.primitives.FillRectColor(hoVector2f(-300, 0), 20, 100, g_ho.colorchata.moonstone);
	g_ho.primitives.FillRectColor(hoVector2f(300, 0), 20, 100, g_ho.colorchata.burntSienna);
	g_ho.primitives.DrawAll();

	glColor3f(1.0f, 1.0f, 1.0f);
	sprite.Draw(0, 0);
	sprite.SetScale(5);

	g_ho.EnableTextShader(); // Activar Shader para renderizar texto
		//ESCRIBIR TEXTOS
		txt.RenderText("00", w/2, h - 70, 1.3, glm::vec3(1, 1, 1));
	g_ho.DisableTextShader(); // Descativar Shader de texto

}
