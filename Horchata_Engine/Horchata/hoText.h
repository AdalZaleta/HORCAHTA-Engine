#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <stdio.h>
#include "SDL_ttf.h"

class hoText {
public:
	void glTextOut(long start_x, long start_y, char *string);
	
	int TTF_Init(void);
	void TTF_Quit(void);
	void atexit();
	TTF_Font *TTF_OpenFont(const char *file, int ptsize);
	TTF_Font *TTF_OpenFontIndex(const char *file, int ptsize, long index);
	void TTF_Close(TTF_Font *font);
	int TTF_FontHeight(TTF_Font * font);
	int TTF_FontAscent(TTF_Font * font);
	int TTF_FontDescent(TTF_Font * font);
	//Pagina 347

private:

};