#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>

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

	g_ho.primitives.SetPixelDimentions((clipAreaXRightt - clipAreaXLeft) / w, (clipAreaYTop - clipAreaYBottom)/h);
	g_ho.primitives.SetWindowDimentions(w, h);

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);
	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

}

void RenderGL::liberar()
{
	//delete this
}

void RenderGL::update()
{
	
}

void RenderGL::render()
{
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT);


	//------------ PRIMITIVAS EJEMPLOS ------------
	//Esto puede estar en cualquier parte de codigo, no es necesario ponerlo entre glBegin ni glEnd
	g_ho.primitives.DrawLine(hoVector2f(0, 1), hoVector2f(1, 1));
	g_ho.primitives.DrawLine(hoVector2f(0, 0), hoVector2f(1, 1));
	g_ho.primitives.DrawCircle(hoVector2f(0, 0), 3, 64);
	g_ho.primitives.DrawPoint(hoVector2f(2, 1), 1);
	g_ho.primitives.DrawRect(hoVector2f(0, 0), hoVector2f(2, 4));
	g_ho.primitives.DrawEllipse(hoVector2f(-3, 3), 3.0f, 6.0f, 64);
	g_ho.primitives.FillCircle(hoVector2f(4, 4), 3, 16, g_ho.colorchata.adal);
	g_ho.primitives.FillRect(hoVector2f(-2, 2), hoVector2f(2, 3));

	//Esto tiene que estar siempre
	g_ho.primitives.DrawAll();
}


