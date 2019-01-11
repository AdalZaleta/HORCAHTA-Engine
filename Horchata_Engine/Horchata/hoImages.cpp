#include "hoImages.h"
#include <iostream>

hoImages::hoImages()
{

}

hoImages::~hoImages()
{

}

hoImages::hoImages(const char* _dirImages)
{
	//dirImage = _dirImages;

}

bool hoImages::LoadImage_(const char *_dirImages)
{
	//This const char will be the prefix of the image
	const char *prefix = "Resources/";
	//This char array will be concatenate the path
	char result[100];
	//Here we concatenate the prefix
	strcpy_s(result, prefix);
	//Here we add the final path
	strcat_s(result, _dirImages);
	//This make a SDL_Surface from the function load with the final path
	SDL_Surface *surface = IMG_Load(result);
	//Verify if the surface is loaded
	if (surface)
	{
		//Is assigned to the variable of the class
		imageSurface = surface;
		//No se que va aquí
		SDL_LockSurface(imageSurface);
	
	} else if(surface == nullptr){
		//The function will be return false it didn't load it
		return false;
	}

	//return true if everything went ok

	glEnable(GL_TEXTURE_2D);

	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	GLuint textures;
	glGenTextures(1, &textures); //Number of textures stored in array name specified

	glBindTexture(GL_TEXTURE_2D, textures);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	int mode = GL_RGB;

	if (imageSurface->format->BytesPerPixel == 4) {
		mode = GL_RGBA;
	}

	// Map the surface to the texture in video memory
	glTexImage2D(GL_TEXTURE_2D, 0, mode, imageSurface->w, imageSurface->h, 0, mode, GL_UNSIGNED_BYTE, imageSurface->pixels); //GL_BITMAP
	//SDL_FreeSurface(imageSurface);
	width = imageSurface->w;
	height = imageSurface->h;


	glBindTexture(GL_TEXTURE_2D, textures);
	return true;
}

void hoImages::DrawImage(int _x, int _y, int _width, int _height)
{
	glPushMatrix(); //Se hace un PushMatrix() para poder trasladarnos en las 4 esquinas de la imagen

	//Renderear el quad
	glBegin(GL_QUADS);
	//maneja las porciones de la img			//maneja el tamaño
	glTexCoord2f(0.0f, 1.0f); glVertex2f(_x + (_width/2.0f), _y - (_height/2.0f)); //Arriba a la izquierda
	glTexCoord2f(1.0f, 1.0f); glVertex2f(_x - (_width/2.0f), _y - (_height/2.0f)); //Arriba a la derecha
	glTexCoord2f(1.0f, 0.0f); glVertex2f(_x - (_width/2.0f), _y + (_height/2.0f)); //Abajo a la derecha
	glTexCoord2f(0.0f, 0.0f); glVertex2f(_x + (_width/2.0f), _y + (_height/2.0f)); //Abajo a la izquierda
	/* Se modificó la convencion de dibujo, para que la imagen no saliera invertida */
	glEnd(); // Le paramos el render del quad


	glPopMatrix(); //Termina la fase de render
}
