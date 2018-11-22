#pragma once
#include "hoText2.h"
#include "hoAudioManager.h"
#include "hoPrimitives.h"
#include "hoColor.h"
#include "hoImages.h"
#include "hoRaycast2D.h"


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
private:

};

extern Horchata g_ho;