#pragma once
#include "irrKlang/irrKlang.h"
#include <vector>

using namespace irrklang;

class hoAudioManager
{
	public:
		hoAudioManager();
		~hoAudioManager();

		ISoundEngine* EngineSonido;
		
		ISound* Background;
		
		ISound* Sonidos[];

		// Inicializa el motor de los sonidos
		void InitEngine();

		// Reproduccion, Pausa y Detencion de sonidos
		void Play(const char* clip);
		void Stop();
		void Pause();

		// Musica de Background
		void PlayBackgroundMusic(const char* BackgroundMusic);
		void StopBackgroundMusic();
		void PauseBackgroundMusic();

		// Ajuste de volumen
		void SetVolume(int volumen);
};

