#include "hoAudioManager.h"
#include <iostream>
#include <windows.h>

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
	// Variable para guardar el sonido a reproducir
	ISound* Sonido;

	//Sonido = EngineSonido->addSoundSourceFromFile(clip);

	// Reproducimos el clip recibido y lo guardamos
	Sonido = EngineSonido->play2D(clip);

	return Sonido;
}

void hoAudioManager::Stop(ISound* clip)
{
	// Detiene el sonido recibido
	clip->stop();
}

void hoAudioManager::IsPause(ISound* clip, bool estado)
{
	// Pausa o reanuda el sonido recibido
	clip->setIsPaused(estado);
}

// Musica Background
void hoAudioManager::PlayBackgroundMusic(const char* BackgroundMusic)
{
	/*ISoundSource* Musica;

	Musica = EngineSonido->addSoundSourceFromFile(BackgroundMusic);*/


	// Si no hay musica de background
	if (Background == NULL)
	{
		// Reproduciminos el nuevo
		Background = EngineSonido->play2D(BackgroundMusic, true);
	}
	else
	{
		// Detenemos el anterior
		Background->stop();
		// Reproducimos el nuevo sonido
		Background = EngineSonido->play2D(BackgroundMusic, true);
	}
}

void hoAudioManager::StopBackgroundMusic()
{
	// Detiene la musica de BackGorund
	Background->stop();
}

void hoAudioManager::PauseBackgroundMusic(bool estado)
{
	// Pausa o reanuda la musica de BackGround
	Background->setIsPaused(estado);
}

//Todos Los Sonidos

void hoAudioManager::StopAllSounds()
{
	// Detiene todos los sonidos que se esten reproduciendo
	EngineSonido->stopAllSounds();
}

void hoAudioManager::PauseAllSounds(bool _estado)
{
	// Pausa o reanuda todos los sonidos que tenga el engine
	EngineSonido->setAllSoundsPaused(_estado);
}

//Volumen
void hoAudioManager::SetVolume(float volumen)
{
	// Guardamos el volumen de BackGround
	float VolumenBackground;
	VolumenBackground = Background->getVolume();

	// Seteamos el volumen de todos los sonidos
	EngineSonido->setSoundVolume(volumen);
	
	// Mantenemos el volumen de BackGround
	Background->setVolume(VolumenBackground);
}

void hoAudioManager::SetBackGroundVolume(float volumen)
{
	// Cambiamos el volumen de BackGround
	Background->setVolume(volumen);
}

