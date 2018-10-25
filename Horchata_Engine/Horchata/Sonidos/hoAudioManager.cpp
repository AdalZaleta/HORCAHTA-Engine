#include "hoAudioManager.h"

hoAudioManager::hoAudioManager()
{

}


hoAudioManager::~hoAudioManager()
{

}

void hoAudioManager::InitEngine()
{
	// Creamos el Engine
	EngineSonido = createIrrKlangDevice();
}

// Sonidos
ISound* hoAudioManager::Play(const char* clip)
{
	ISound* Sonido;

	//Sonido = EngineSonido->addSoundSourceFromFile(clip);

	// Reproducimos el clip recibido
	Sonido = EngineSonido->play2D(clip);

	return Sonido;
}

void hoAudioManager::Stop(ISound* clip)
{
	clip->stop();
}

void hoAudioManager::IsPause(ISound* clip, bool estado)
{
	clip->setIsPaused(estado);
}

// Musica Background
void hoAudioManager::PlayBackgroundMusic(const char* BackgroundMusic)
{
	/*ISoundSource* Musica;

	Musica = EngineSonido->addSoundSourceFromFile(BackgroundMusic);*/
	if (Background == NULL)
	{
		Background = EngineSonido->play2D(BackgroundMusic, true);
	}
	else
	{
		Background->stop();
		Background = EngineSonido->play2D(BackgroundMusic, true);
	}
}

void hoAudioManager::StopBackgroundMusic()
{
	Background->stop();
}

void hoAudioManager::PauseBackgroundMusic(bool estado)
{
	Background->setIsPaused(estado);
}