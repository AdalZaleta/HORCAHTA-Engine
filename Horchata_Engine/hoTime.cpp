#include "hoTime.h"

/*
INICIALIZACIÓN DE LAS VARIABLES ESTATICAS
*/
uint32_t hoTime::now = 0;
uint32_t hoTime::last = 0;
double hoTime::deltaTime = 0;

//Calcula el deltaTime (Debe de llamarse en el ciclo de juego para que se haga el calculo constante)
void hoTime::CalcularDeltaTime()
{
		now = SDL_GetTicks(); //Regresa el tiempo en milisegundos
		deltaTime = (now - last) * 0.001f; //Se hace el calculo del delta time tomando el tiempo actual en milisegundos
		last = now; 
}
