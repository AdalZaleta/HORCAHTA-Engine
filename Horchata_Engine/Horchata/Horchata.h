#pragma once
#include "hoPrimitives.h"
#include "hoColor.h"
#include "hoImages.h"
#include "hoAudioManager.h"


class Horchata {
public:
	Horchata();
	~Horchata();

	void Iniciar();

	hoPrimitives primitives;
	hoColor colorchata;
	hoAudioManager SonidosManager;
private:

};

extern Horchata g_ho;