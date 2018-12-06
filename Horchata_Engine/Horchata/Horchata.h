#pragma once
#include "hoText2.h"
#include "hoAudioManager.h"
#include "hoPrimitives.h"
#include "hoColor.h"
#include "hoImages.h"

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
private:

};

extern Horchata g_ho;