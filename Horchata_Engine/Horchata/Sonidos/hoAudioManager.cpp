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
void hoAudioManager::Play(const char* clip)
{
	ISoundSource* Sonido;

	Sonido = EngineSonido->addSoundSourceFromFile(clip);

	// Reproducimos el clip recibido
	EngineSonido->play2D(Sonido);
}

void hoAudioManager::Stop()
{

}

// Musica Background
void hoAudioManager::PlayBackgroundMusic(const char* BackgroundMusic)
{
	ISoundSource* Musica;

	Musica = EngineSonido->addSoundSourceFromFile(BackgroundMusic);

	Background = EngineSonido->play2D(Musica, true);
}

void hoAudioManager::StopBackgroundMusic()
{
	Background->stop();
}

void hoAudioManager::PauseBackgroundMusic()
{
	Background->setIsPaused(true);
}