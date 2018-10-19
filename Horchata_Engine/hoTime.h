#pragma once
#include "SDL.h"
#include <stdio.h>

class hoTime
	{
	public:
		hoTime();
		~hoTime();

		static uint32_t now;
		static uint32_t last;

		static double deltaTime;



		static void CalcularDT();


	};


