#include "SDL.h"
#include "RenderGL.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "Horchata/hoTime.h"
#include <windows.h>
#include "Horchata/hoBotones.h"
#include <GL/GL.h>

using namespace std;

float speed = 3.0f;

RenderGL rgl;

//Dimensiones de la ventana
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Inicializa SDL, crea ventana y lo liga a openGL
bool init();
//Manejador de teclado con posicion del mouse
void handleKeys(unsigned char _key, int _x, int _y);
//Manejador de mouse
void handleMouse(SDL_Event* _evt, int _x, int _y);

//Liberar media y SDL
void close();

//Referencia a la ventana de windows
SDL_Window* gWindow = NULL;
//Referencia a OpenGl con SDL
SDL_GLContext gContext;

//------CORE ------------------------------------------------------------------------------------
//use OPENGL

//Teclado
void handleKeys(unsigned char _key, int _x, int _y)
{
	//std::cout << _key << std::endl;
	if (_key == 'w') {
		rgl.lPos += speed;
		std::cout << rgl.lPos << std::endl;
	}
	else if (_key == 's') {
		rgl.lPos -= speed;
	}

	if (_key == 'i') {
		rgl.rPos += speed;
	}
	else if (_key == 'k') {
		rgl.rPos -= speed;
	}
}

//Mouse
void handleMouse(SDL_Event* _evt, int _x, int _y)
{

	//Click mouse izq

	if (_evt->type == SDL_MOUSEBUTTONDOWN)
	{
		if (_evt->button.button == SDL_BUTTON_LEFT)
		{
			//NO TOCAR
			//Conversion de coordenadas SDL a OpenGL en el eje X
			float xtemp= _x/(float)g_renderGL.w;

			float OpGLw = abs(g_renderGL.clipAreaXRightt - g_renderGL.clipAreaXLeft);

			float leftPorcentaje = OpGLw * xtemp;
			float Xgl=g_renderGL.clipAreaXLeft + leftPorcentaje;

			//cout <<"Mi coordenada en X de opgl es: "<< Xgl << endl;

			//Conversion de coordenadas SDL a OpenGL en el eje Y
			float ytemp = _y / (float)g_renderGL.h;

			float OpGLh = abs(g_renderGL.clipAreaYTop - g_renderGL.clipAreaYBottom);

			float BotPercent = OpGLh * ytemp;
			float Ygl = g_renderGL.clipAreaYTop - BotPercent;

			//cout << "Mi coordenada en Y de openGL es " << Ygl << endl;

			g_renderGL.onClickDown(Xgl, Ygl);
		}
	}
}

//------ FIN CORE -------------------------------------------------------------------------------
bool init()
{

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		int flags = IMG_INIT_JPG | IMG_INIT_PNG;
		int initted = IMG_Init(flags);
		if ((initted&flags) != flags) {
			printf("IMG_Init: Failed to init required jpg and png support!\n");
			printf("IMG_Init: %s\n", IMG_GetError());
			// handle error
		}

		//Indicamos que usaremos OPenGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

		//Creamos Ventana
		gWindow = SDL_CreateWindow("Horchata Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{

			//SDL_GetRendererOutputSize(gWindow, &g_renderGL.w, &g_renderGL.h);
			
			g_renderGL.w= SDL_GetWindowSurface(gWindow)->w;
			g_renderGL.h = SDL_GetWindowSurface(gWindow)->h;

			//Creamos COntexto de OpenGL
			gContext = SDL_GL_CreateContext(gWindow);
			if (gContext == NULL)
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{			

				//Activamos VSync
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}

				//Inicializamos OpenGL
				g_ho.Iniciar();
				g_renderGL.inicializar();
			}
		}
	}

	
	
	
	return success;
}

void close()
{
	//Liberamos OpenGL
	g_renderGL.liberar();
	//Destruimos ventana
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	IMG_Quit();
	//Cerramos SDL
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Error al inicializar!\n");
		system("pause");
	}
	else
	{
		//GameLoop
		bool GameLoop = false;
		//Manejador de evento
		SDL_Event e;

		//Se activa deteccion de teclado
		SDL_StartTextInput();

		SDL_Surface* pantalla = SDL_GetWindowSurface(gWindow);

		//GameLoop
		while (!GameLoop)
		{

			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT) //Salir
				{
					GameLoop = true;
				}
				else if (e.type == SDL_TEXTINPUT) //Evento de teclado
				{
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleKeys(e.text.text[0], x, y);
				}
				else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEMOTION)
				{
					//obtenemos mouse
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleMouse(&e, x, y);
				}				
			}

			//Update
			g_renderGL.update();
			

			

			//Dibujamos
			g_renderGL.render();

			//SDL_BlitSurface(texto, NULL, pantalla, &dest);
			
			//Actualizamos pantalla
			SDL_GL_SwapWindow(gWindow);
			
			//Calculamos el deltaTime
						
		
		}

		//Desactivamos detectar teclado
		SDL_StopTextInput();
	}

	//Cerramos y desactivamos SDL
	close();

	return 0;
}