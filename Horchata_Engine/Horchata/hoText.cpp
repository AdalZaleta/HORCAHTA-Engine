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
