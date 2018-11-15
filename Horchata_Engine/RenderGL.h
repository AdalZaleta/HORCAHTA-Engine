#pragma once

#include "hoText2.h"

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

		Shader shader;

		hoText2 DTMfont;
		hoText2 SAOfont;
		hoText2 OPTfont;
		hoText2 GRSfont;
		hoText2 GSTfont;
		hoText2 CNTfont;
		hoText2 DOMfont;
		hoText2 NJAfont;
		hoText2 SPKfont;
		hoText2 MEXfont;
		hoText2 SGNfont;

		unsigned int texture;
};

extern RenderGL g_renderGL; //Singleton
