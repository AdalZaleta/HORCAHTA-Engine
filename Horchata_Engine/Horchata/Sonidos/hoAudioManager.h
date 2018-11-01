#pragma once
#include "irrKlang/irrKlang.h"
#include <string>

using namespace irrklang;

class hoAudioManager
{
	public:
		hoAudioManager();
		~hoAudioManager();

		// El engine que reproducira todos los sonidos
		ISoundEngine* engineSonido;
		
		// Musica de BackGround
		ISound* background;

		// Inicializa el motor de los sonidos
		void InitEngine();

		// Reproduccion, Pausa y Detencion de sonidos
		ISound* Play(const char* _clip);
		void Stop(ISound* _clip);
		void IsPause(ISound* _clip, bool _estado);

		// Musica de Background
		void PlayBackgroundMusic(const char* _BackgroundMusic);
		void StopBackgroundMusic();
		void PauseBackgroundMusic(bool _estado);

		// Detener y pausar todos los sonidos
		void StopAllSounds();
		void PauseAllSounds(bool _estado);

		// Ajuste de volumen
		void SetVolume(float _volumen);
		void SetBackGroundVolume(float _Volumen);
};

