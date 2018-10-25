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

		// Inicializa el motor de los sonidos
		void InitEngine();

		// Reproduccion, Pausa y Detencion de sonidos
		ISound* Play(const char* clip);
		void Stop(ISound* clip);
		void IsPause(ISound* clip, bool estado);

		// Musica de Background
		void PlayBackgroundMusic(const char* BackgroundMusic);
		void StopBackgroundMusic();
		void PauseBackgroundMusic(bool estado);

		
		void StopAllSounds();
		void PauseAllSounds(bool _estado);

		// Ajuste de volumen
		void SetVolume(float volumen);
		void SetBackGroundVolume(float Volumen);
};

