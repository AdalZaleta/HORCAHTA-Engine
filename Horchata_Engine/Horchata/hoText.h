#pragma once

#include "SDL.h"
#include "SDL_opengl.h"
#include <stdio.h>
#include <stdlib.h>

class hoText {
public:

	void TEMP_CreateBitmapFont(const char *_fontName, int _fontSize);
	void TEMP_DrawText(const char *_str);
	void TEMP_ReleaseFont();

	HDC hDC;

private:
	
	unsigned int base;
};