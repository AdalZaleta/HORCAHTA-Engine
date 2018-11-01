#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <stdio.h>
#include "SDL_ttf.h"
#include <iostream>

class hoText {
public:
	//void glTextOut(long start_x, long start_y, char *string);
	
	static TTF_Font *fuente;

	/*TTF_Font *TTF_OpenFont(const char *file, int ptsize);
	TTF_Font *TTF_OpenFontIndex(const char *file, int ptsize, long index);
	void TTF_Close(TTF_Font *font);

	//FUNCIONES PARA OBTENER INFORMACIÓN DE LA FUENTE
	int TTF_FontHeight(TTF_Font * font);
	int TTF_FontAscent(TTF_Font * font);
	int TTF_FontDescent(TTF_Font * font);

	//FUNCIONES PARA MANEJAR FUENTES
	int TTF_GetFontStyle(TTF_Font * font);
	void TTF_SetFontStyle(TTF_Font *font, int style);
	int TTF_FontLineSkip(TTF_Font *font);
	int TTF_SizeText(TTF_Font *font, const char *text, int *w, int *h);
	int TTF_SizeUTF8(TTF_Font *font, const char *text, int *w, int *h);
	int TTF_SizeUNICODE(TTF_Font *font, const Uint16 * text, int * w, int * h);

	//FUNCIONES PARA RENDERIZADO DE TEXTO
	SDL_Surface * TTF_RenderText_Solid(TTF_Font *font, const char *text, SDL_Color fg);
	SDL_Surface * TTF_RenderText_Shaded(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg);
	SDL_Surface * TTF_RenderText_Blended(TTF_Font *font, const char *text, SDL_Color fg);

	SDL_Surface * TTF_RenderUTF8_Solid(TTF_Font *font, const char *text, SDL_Color fg);
	SDL_Surface * TTF_RenderUNICODE_Solid(TTF_Font *font, const Uint16 *text, SDL_Color fg);
	SDL_Surface * TTF_RenderUTF8_Shaded(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg);
	SDL_Surface * TTF_RenderUNICODE_Shaded(TTF_Font *font, const Uint16 *text, SDL_Color fg, SDL_Color bg);
	SDL_Surface * TTF_RenderUTF8_Blended(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color bg);
	SDL_Surface * TTF_RenderUNICODE_Blended(TTF_Font *font, const Uint16 *text, SDL_Color fg, SDL_Color bg);*/

private:

};