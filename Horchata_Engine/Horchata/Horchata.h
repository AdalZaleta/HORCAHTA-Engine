#pragma once
#include "hoText2.h"
#include "hoAudioManager.h"
#include "hoPrimitives.h"
#include "hoColor.h"
#include "hoImages.h"
#include "hoRaycast2D.h"
#include "Chipmunk/include/chipmunk.hpp"

class Horchata {
public:
	Horchata();
	~Horchata();

	void Iniciar();

	hoPrimitives primitives;
	hoColor colorchata;
	hoAudioManager SonidosManager;
	hoRaycast2D raycast2D;
	Shader shader;
	
	cp::Space space;

private:

};

extern Horchata g_ho;