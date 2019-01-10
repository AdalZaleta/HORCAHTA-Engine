#pragma once
#include "Horchata/Horchata.h"

class RenderGL
{
	public:
		RenderGL();
		~RenderGL();

		float clipAreaXLeft;
		float clipAreaYTop;
		float clipAreaXRightt;
		float clipAreaYBottom;
		int h;
		int w;
		//Funcion encarga de inicializar OpenGL
		//Regresa True si se inicio correctamente o false en caso cotrario
		void inicializar();
		//Se llama al momento de libarse
		void liberar();

		//Funcion que se actualiza cada frame
		void update();
		//Funcion encargado de dibujar
		void render();
		
		const GLuint WIDTH = 1500, HEIGHT = 1000;

		hoSprite sprite;
		hoImages image;

		
};

extern RenderGL g_renderGL; //Singleton
