#pragma once
#include "hoTime.h"
#include "hoText2.h"
#include "hoAudioManager.h"
#include "hoPrimitives.h"
#include "hoColor.h"
#include "hoSprite.h"
#include "hoImages.h"
#include "chipmunk/chipmunk_private.h"
#include "chipmunk/chipmunk.h"

typedef cpSpace *(*ChipmunkDemoInitFunc)(void);
typedef void(*ChipmunkDemoUpdateFunc)(cpSpace *space, double dt);
typedef void(*ChipmunkDemoDrawFunc)(cpSpace *space);
typedef void(*ChipmunkDemoDestroyFunc)(cpSpace *space);

class Horchata {
public:
	Horchata();
	~Horchata();

	void Iniciar();
	void EnableTextShader();
	void DisableTextShader();

	hoPrimitives primitives;
	hoColor colorchata;
	hoAudioManager SonidosManager;
	Shader shader;
	cpSpace *space;
	cpBody *circulo;

private:

};

extern Horchata g_ho;