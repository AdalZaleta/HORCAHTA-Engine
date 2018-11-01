#include "hoText.h"

TTF_Font* hoText::fuente = NULL;

//Ejemplo libro 4
int tryText()
{
	TTF_Font *fuente;
	fuente = TTF_OpenFont("Resources/Fonts/bgothm.ttf", 16);

	int w, h;

	TTF_SizeUTF8(fuente, "Hola Mundo", &w, &h);

	SDL_Surface *texto;
	SDL_Color color;

	color.r = 255;
	color.g = 255;
	color.b = 255;

	texto = TTF_RenderText_Blended(fuente, "Hola Mundo", color);

	SDL_Rect dest;
	dest.x = 150;
	dest.y = 100;
	dest.h = texto->h;
	dest.w = texto->w;

	//PAGINA 352 ULTIMO LIBRO
	return 0;
}