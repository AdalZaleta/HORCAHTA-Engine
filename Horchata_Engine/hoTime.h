#pragma once
#include "SDL.h"
#include <stdio.h>

/*
Esta clase hace el calculo del deltaTime


Para hacer uso del deltaTime es necesario llamar a la variable de la siguiente manera

EJEMPLO:
contador += hoTime::deltaTime;

NOTA:
La función CalcularDeltaTime() tiene que ser llamada en el ciclo de juego para que funcione

*/


 class hoTime
	{
	public:
		hoTime();
		~hoTime();
	
		//Almacenan el tiempo en milisegundos (actual y anterior) para hacer el calculo del deltaTime
		static uint32_t now;
		static uint32_t last;

		static double deltaTime; //Variable a utilizar como deltaTime
		static void CalcularDeltaTime(); //Funcion que calcula el deltaTime 


	};

