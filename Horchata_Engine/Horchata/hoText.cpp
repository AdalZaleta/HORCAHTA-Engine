#include "hoText.h"

//EJEMPLO LIBRO 3
/*void hoText::glTextOut(long start_x, long start_y, char *string)
{
	char file[50];
	long h = 12;
	long w = 8;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for (long idx = 0; idx < (signed)strlen(string); idx++)
	{
		if (string[idx] != ' ')
		{
			sprintf(file, "font1_%c.bmp", tolower(string[idx]));
			glBindTexture(GL_TEXTURE_2D, TextureName[GetTextureID(file)]);
			glBitBlt(GetTextureID(file), start_x + (idx*w), start_y, w, h);
		}
	}
	glDisable(GL_BLEND);
}
*/

//Ejemplo libro 4
int tryText()
{
	TTF_Font *fuente;
	fuente = TTF_OpenFont("Resources/Fonts/bgothm.ttf", 16);

	int w, h;

	TTF_SizeUTF8(fuente, "Hola Mundo", &w, &h);

	SDL_Surface *texto;
	SDL_Color color;

	color.r = 0;
	color.g = 0;
	color.b = 0;

	texto = TTF_RenderText_Blended(fuente, "Hola Mundo", color);

	SDL_Rect dest;
	dest.x = 150;
	dest.y = 100;
	dest.h = texto->h;
	dest.w = texto->w;

	SDL_BlitSurface(texto, NULL, pantalla, &dest);
	SDL_RendererFlip(pantalla);
	SDL_Delay(5000);


	//PAGINA 352 ULTIMO LIBRO
	return 0;
}