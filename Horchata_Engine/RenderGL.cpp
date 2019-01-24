#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>
#include <windows.h>			// standard Windows app include
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRABBABLE_MASK_BIT (1<<31)
cpShapeFilter GRAB_FILTER = { CP_NO_GROUP, GRABBABLE_MASK_BIT, GRABBABLE_MASK_BIT };
cpShapeFilter NON_GRABABLE_FILTER = { CP_NO_GROUP, ~GRABBABLE_MASK_BIT, ~GRABBABLE_MASK_BIT };

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

	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	g_ho.space = cpSpaceNew();
	cpSpaceSetIterations(g_ho.space, 10);
	cpSpaceSetGravity(g_ho.space, cpv(0, -100));

	floor = new hoBody(hoVector2f(0, 0), 0, true);
	floor->AddShape(cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(floor->GetBody(), cpv(-320, -240), cpv(320, -240), 0.0f)));
	floor->SetAllPhysics(1.0f, 1.0f);
	floor->SetAllFilters(testFilter);

	test = new hoBody(hoVector2f(0, 0), 0, false, hoVector2f(5.0f, 100.0f));
	test->AddShape(cpSpaceAddShape(g_ho.space, cpCircleShapeNew(test->GetBody(), 20.0f, cpvzero)));
	test->SetAllCollisionTypes(2);
	test->SetAllPhysics(10, 1);
}

void RenderGL::liberar()
{
	delete test;
	cpSpaceFree(g_ho.space);
}

void RenderGL::update()
{
	hoTime::CalcularDeltaTime();
	test->Update(hoTime::deltaTime);
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	/*glBegin(GL_POINTS);
	glPointSize(5.0f);
	hoVector2f temp = test.GetPosition();
	glVertex2f(temp.x, temp.y);
	glEnd();*/

	g_ho.primitives.DrawCircle(test->GetPosition(), 15, 16);


	//Esto tiene que estar siempre
	g_ho.primitives.DrawAll();
}

//TODO: que se mueva
