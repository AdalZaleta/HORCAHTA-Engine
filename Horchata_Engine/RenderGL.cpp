#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <iostream>
#include <windows.h>			// standard Windows app include
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Metastuff/Meta.h"

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

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Setup para el shader de texto
	g_ho.shader.LoadShader("Resources/Shaders/text.vs", "Resources/shaders/text.frag");


	////-----------------------	HORCHATA SECTION	--------------------------------------
	
	//Init Space
	g_ho.space = cpSpaceNew();
	cpSpaceSetIterations(g_ho.space, 10);
	cpSpaceSetGravity(g_ho.space, cpv(0,0));

	circleB = new hoBody(hoVector2f(),0,false,hoVector2f(100,0));
	circleB->AddCircle(hoVector2f(), 1.0f);
	circleB->SetAllCollisionTypes(2);
	circleB->SetAllPhysics(1, 1);

	box1B = new hoBody();
	box1B->AddSegment(hoVector2f(-300,-50), hoVector2f(-300, 50),0);
	box1B->SetAllPhysics(1, 1);
	box1B->SetAllFilters(NON_GRABABLE_FILTER);

	box2B = new hoBody();
	box2B->AddSegment(hoVector2f(300, -50), hoVector2f(300, 50), 0);
	box2B->SetAllPhysics(1, 1);
	box2B->SetAllFilters(NON_GRABABLE_FILTER);

	//Init Text
	txt.LoadFont(w, h, "Resources/Fonts/DTM.otf", 0, 32, g_ho.shader);
	//Init Font
	sprite.LoadImage_("Bolita.png");
}

void RenderGL::liberar()
{
	cpSpaceFree(g_ho.space);
}

void RenderGL::onClickDown(float _x, float _y)
{
	//CODIGO DE BOTONES Boton.OnClickDown(_x, _y);
}

void RenderGL::update()
{
	box1B->SetPosition(hoVector2f(-300, lPos));
	box2B->SetPosition(hoVector2f(300, rPos));
	hoTime::CalcularDeltaTime();
	circleB->Update(hoTime::deltaTime);
}

float zoom = 10;
void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	g_ho.primitives.DrawCircle(circleB->GetPosition(), 20, 16);
	g_ho.primitives.FillRectColor(box1B->GetPosition(),20, 100, g_ho.colorchata.moonstone);
	g_ho.primitives.FillRectColor(box2B->GetPosition(), 20, 100, g_ho.colorchata.burntSienna);
	g_ho.primitives.DrawAll();

	glColor3f(1.0f, 1.0f, 1.0f);
	sprite.Draw(circleB->GetPosition().x, circleB->GetPosition().y);
	sprite.SetScale(5);

	g_ho.EnableTextShader(); // Activar Shader para renderizar texto
		//ESCRIBIR TEXTOS
		txt.RenderText("PING HORCHATA", 100, h - 70, 1.3, glm::vec3(1, 1, 1));
	g_ho.DisableTextShader(); // Descativar Shader de texto

}

//TODO: que se mueva
