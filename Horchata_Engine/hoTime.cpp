#include "hoTime.h"

uint32_t hoTime::now = 0;
uint32_t hoTime::last = 0;
double hoTime::deltaTime = 0;

hoTime::hoTime()
{

}


hoTime::~hoTime()
{
}


void hoTime::CalcularDT()
{
	now = SDL_GetTicks();
	deltaTime = (now - last) * 0.001f;

}
