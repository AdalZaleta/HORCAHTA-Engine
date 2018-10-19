#pragma once
#include "irrKlang/irrKlang.h"

using namespace irrklang;

class hoAudioManager
{
	public:
		hoAudioManager();
		~hoAudioManager();

		// Reproduccion, Pausa y Detencion de sonidos
		void Play();
		void Stop();
		void Pause();

		// Ajuste de volumen
		void SetVolume(int volumen);


};

