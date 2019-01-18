#include "hoPrimitives.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>


hoPrimitives::hoPrimitives()
{

}


hoPrimitives::~hoPrimitives()
{
	for (int i = 0; i < drawables.size(); i++) //Borro todos los apuntadores de drawables
		delete drawables[i];
}

void hoPrimitives::DrawAll()
{
	for (int i = 0; i < drawables.size(); i++)	//Mando a dibujar todos los drawables activos de el vector drawables
	{
		if (drawables[i]->isActive) {
			drawables[i]->Draw();
			drawables[i]->isActive = false;
		}
	}
}

void hoPrimitives::SetPixelDimentions(float _w, float _h)
{
	pixelWidth = _w;
	pixelHeight = _h;	
}

void hoPrimitives::SetWindowDimentions(float _w, float _h)
{
	windowWidth = _w;
	windowHeight = _h;
}

float hoPrimitives::GetWindowWidth()
{
	return windowWidth;
}

float hoPrimitives::GetWindowHeight()
{
	return windowHeight;
}

//-------- En todas las funciones que empiezan con Draw o Fill ----------
//Busco si hay un drawable del tipo que estoy intentando dibujar ya creado que este inactivo con GetFirstInactive, regresa el indice de donde lo encontro o -1 si no encontro nada.
//Cuando encuentro uno inactivo, le cambio sus valores a los que me estan mandando y lo vuelvo activo.
//Si no encuentro uno que no este activo, creo uno nuevo y le asigno los valores que me mandaron.
//La diferencia entre Draw y Fill es que en Fill hago true el booleano fill de la clase padre de Drawables, y en Draw lo hago false;

void hoPrimitives::DrawLine(float _x1, float _y1, float _x2, float _y2)
{
	DrawLine(hoVector2f(_x1, _y1), hoVector2f(_x2, _y2), 0.0f);
}

void hoPrimitives::DrawLine(hoVector2f _pos1, hoVector2f _pos2)
{
	DrawLine(_pos1, _pos2, 0.0f);
}

void hoPrimitives::DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rot)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		hoLine* temp = dynamic_cast<hoLine*>(drawables[index]);
		if (temp)
			*temp = hoLine(_pos1, _pos2);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = false;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoLine(_pos1, _pos2));
	}
}

void hoPrimitives::DrawCircle(float _x, float _y, float _r, int _seg)				//Explicacion de Draws y Fills mas arriba
{
	DrawCircle(hoVector2f(_x, _y), _r, _seg);
}

void hoPrimitives::DrawCircle(hoVector2f _pos, float _r, int _seg)
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		hoCircle* temp = dynamic_cast<hoCircle*>(drawables[index]);
		if (temp)
			*temp = hoCircle(_pos, _r, _seg);
		drawables[index]->isActive = true;
		drawables[index]->fill = false;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg));
	}
}

void hoPrimitives::DrawPoint(float _x, float _y, float _size)				//Explicacion de Draws y Fills mas arriba
{
	DrawPoint(hoVector2f(_x, _y), _size);
}

void hoPrimitives::DrawPoint(hoVector2f _pos, float _size)
{
	int index = GetFirstInactive(HO_POINT);
	if (index != -1) {
		hoPoint* temp = dynamic_cast<hoPoint*>(drawables[index]);
		if (temp)
			*temp = hoPoint(_pos, _size);
		drawables[index]->isActive = true;
		drawables[index]->fill = false;
	}
	else
	{
		drawableTypes.push_back(HO_POINT);
		drawables.push_back(new hoPoint(_pos, _size));
	}
}

void hoPrimitives::DrawRect(float _x, float _y, float _w, float _h)
{
	DrawRect(hoVector2f(_x, _y), hoVector2f(_w, _h));
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h)					//Explicacion de Draws y Fills mas arriba
{
	DrawRect(_pos, _w, _h, 0.0f);
}

void hoPrimitives::DrawRect(hoVector2f _pos, hoVector2f _sizes)
{
	DrawRect(_pos, _sizes.x, _sizes.y, 0.0f);
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h, float _rot)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		hoRect* temp = dynamic_cast<hoRect*>(drawables[index]);
		if (temp)
			*temp = hoRect(_pos, hoVector2f(_w, _h));
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = false;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h)));
	}
}

void hoPrimitives::DrawEllipse(float _x, float _y, float _w, float _h, int _seg)
{
	DrawEllipse(hoVector2f(_x, _y), _w, _h, _seg, 0.0f);
}

void hoPrimitives::DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg)					//Explicacion de Draws y Fills mas arriba
{
	DrawEllipse(_pos, _w, _h, _seg, 0.0f);
}

void hoPrimitives::DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot)
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		hoEllipse* temp = dynamic_cast<hoEllipse*>(drawables[index]);
		if (temp)
			*temp = hoEllipse(_pos, hoVector2f(_w, _h), _seg);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = false;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg));
	}
}

void hoPrimitives::FillCircle(float _x, float _y, float _r, int _seg)
{
	FillCircle(hoVector2f(_x, _y), _r, _seg);
}

void hoPrimitives::FillCircle(hoVector2f _pos, float _r, int _seg)			
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		hoCircle* temp = dynamic_cast<hoCircle*>(drawables[index]);
		if (temp)
			*temp = hoCircle(_pos, _r, _seg);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(float _x, float _y, float _w, float _h)			////Explicacion de Draws y Fills mas arriba
{
	FillRect(hoVector2f(_x, _y), hoVector2f(_w, _h));
}

void hoPrimitives::FillRect(hoVector2f _pos, float _w, float _h)
{
	FillRect(_pos, _w, _h, 0.0f);
}

void hoPrimitives::FillRect(hoVector2f _pos, hoVector2f _sizes)
{
	FillRect(_pos, _sizes.x, _sizes.y, 0.0f);
}

void hoPrimitives::FillRect(hoVector2f _pos, float _w, float _h, float _rot)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		hoRect* temp = dynamic_cast<hoRect*>(drawables[index]);
		if (temp)
			*temp = hoRect(_pos, hoVector2f(_w, _h));
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h)));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillEllipse(float _x, float _y, float _w, float _h, int _seg)				//Explicacion de Draws y Fills mas arriba
{
	FillEllipse(hoVector2f(_x, _y), _w, _h, _seg, 0.0f);
}

void hoPrimitives::FillEllipse(hoVector2f _pos, float _w, float _h, int _seg)
{
	FillEllipse(_pos, _w, _h, _seg, 0.0f);
}

void hoPrimitives::FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot)
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		hoEllipse* temp = dynamic_cast<hoEllipse*>(drawables[index]);
		if (temp)
			*temp = hoEllipse(_pos, hoVector2f(_w, _h), _seg);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg));
		drawables[drawables.size() - 1]->fill = true;
	}
}

//With color

void hoPrimitives::DrawLine(float _x1, float _y1, float _x2, float _y2, float _rgba[4])			//Explicacion de Draws y Fills mas arriba
{
	DrawLine(hoVector2f(_x1, _y1), hoVector2f(_x2, _y2), 0.0f, _rgba);
}

void hoPrimitives::DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rgba[4])
{
	DrawLine(_pos1, _pos2, 0.0f, _rgba);
}

void hoPrimitives::DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rot, float _rgba[4])
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		hoLine* temp = dynamic_cast<hoLine*>(drawables[index]);
		if (temp)
			*temp = hoLine(_pos1, _pos2, _rgba);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoLine(_pos1, _pos2, _rgba));
	}
}

void hoPrimitives::DrawCircle(float _x, float _y, float _r, int _seg, float _rgba[4])
{
	DrawCircle(hoVector2f(_x, _y), _r, _seg, _rgba);
}

void hoPrimitives::DrawCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4])				//Explicacion de Draws y Fills mas arriba
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		hoCircle* temp = dynamic_cast<hoCircle*>(drawables[index]);
		if (temp)
			*temp = hoCircle(_pos, _r, _seg, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg, _rgba));
	}
}

void hoPrimitives::DrawPoint(float _x, float _y, float _size, float _rgba[4])
{
	DrawPoint(hoVector2f(_x, _y), _size, _rgba);
}

void hoPrimitives::DrawPoint(hoVector2f _pos, float _size, float _rgba[4])
{
	int index = GetFirstInactive(HO_POINT);
	if (index != -1) {
		hoPoint* temp = dynamic_cast<hoPoint*>(drawables[index]);
		if (temp)
			*temp = hoPoint(_pos, _size, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_POINT);
		drawables.push_back(new hoPoint(_pos, _size, _rgba));
	}
}

void hoPrimitives::DrawRect(float _x, float _y, float _w, float _h, float _rgba[4])				//Explicacion de Draws y Fills mas arriba
{
	DrawRect(hoVector2f(_x, _y), hoVector2f(_w, _h), _rgba);
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h, float _rgba[4])
{
	DrawRect(_pos, _w, _h, 0.0f, _rgba);
}

void hoPrimitives::DrawRect(hoVector2f _pos, hoVector2f _sizes, float _rgba[4])
{
	DrawRect(_pos, _sizes.x, _sizes.y, 0.0f, _rgba);
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h, float _rot, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		hoRect* temp = dynamic_cast<hoRect*>(drawables[index]);
		if (temp)
			*temp = hoRect(_pos, hoVector2f(_w, _h), _rgba);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h), _rgba));
	}
}

void hoPrimitives::DrawEllipse(float _x, float _y, float _w, float _h, int _seg, float _rgba[4])			//Explicacion de Draws y Fills mas arriba
{
	DrawEllipse(hoVector2f(_x, _y), _w, _h, _seg, 0.0f, _rgba);
}

void hoPrimitives::DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4])
{
	DrawEllipse(_pos, _w, _h, _seg, 0.0f, _rgba);
}

void hoPrimitives::DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot, float _rgba[4])
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		hoEllipse* temp = dynamic_cast<hoEllipse*>(drawables[index]);
		if (temp)
			*temp = hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba));
	}
}
	
void hoPrimitives::FillCircle(float _x, float _y, float _r, int _seg, float _rgba[4])				//Explicacion de Draws y Fills mas arriba
{
	FillCircle(hoVector2f(_x, _y), _r, _seg, _rgba);
}

void hoPrimitives::FillCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		hoCircle* temp = dynamic_cast<hoCircle*>(drawables[index]);
		if (temp)
			*temp = hoCircle(_pos, _r, _seg, _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg, _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRectColor(float _x, float _y, float _w, float _h, float _rgba[4])				//Explicacion de Draws y Fills mas arriba
{
	FillRectColor(hoVector2f(_x, _y), hoVector2f(_w, _h), _rgba);
}

void hoPrimitives::FillRectColor(hoVector2f _pos, float _w, float _h, float _rgba[4])
{
	FillRectColor(_pos, _w, _h, 0.0f, _rgba);
}

void hoPrimitives::FillRectColor(hoVector2f _pos, hoVector2f _sizes, float _rgba[4])			//Explicacion de Draws y Fills mas arriba
{
	FillRectColor(_pos, _sizes.x, _sizes.y, 0.0f, _rgba);
}

void hoPrimitives::FillRectColor(hoVector2f _pos, float _w, float _h, float _rot, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		hoRect* temp = dynamic_cast<hoRect*>(drawables[index]);
		if (temp)
			*temp = hoRect(_pos, hoVector2f(_w, _h), _rgba);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h), _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillEllipse(float _x, float _y, float _w, float _h, int _seg, float _rgba[4])
{
	FillEllipse(hoVector2f(_x, _y), _w, _h, _seg, 0.0f, _rgba);
}

void hoPrimitives::FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4])			//Explicacion de Draws y Fills mas arriba
{
	FillEllipse(_pos, _w, _h, _seg, 0.0f, _rgba);
}

void hoPrimitives::FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot, float _rgba[4])
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		hoEllipse* temp = dynamic_cast<hoEllipse*>(drawables[index]);
		if (temp)
			*temp = hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba);
		temp->rotation = _rot;
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

int hoPrimitives::GetFirstInactive(DrawableType _type)
{
	for (int i = 0; i < drawables.size(); i++) {	//Recorro mi arreglo de drawables buscando uno que sea inactive y que sea del mismo tipo que del que estoy buscando, para eso me apoyo de drawableTypes
		if (drawableTypes[i] == _type)
			if (!drawables[i]->isActive)
				return i;
	}
	return -1;
}

void hoPoint::Draw()
{
	hoDrawable::Draw();
	glPointSize(size);	//Cambio el tama�o del punto
	glBegin(GL_POINTS);
		glVertex2f(position.x, position.y);
		std::cout << "Position on y is: " << position.y << std::endl;
	glEnd();
}

void hoLine::Draw()
{
	float halfx = (point2.x + point1.x) / 2.0f;
	float halfy = (point2.y + point1.y) / 2.0f;
	hoDrawable::Draw();

	glPushMatrix();
	glTranslatef(halfx, halfy, 0.0f);
	glRotatef(rotation, 0, 0, 1);

	glBegin(GL_LINES);	
		glVertex2f(point1.x - halfx, point1.y - halfy);				//Dibujo linea de point1 a point2
		glVertex2f(point2.x - halfx, point2.y - halfy);
	glEnd();

	glPopMatrix();
}

void hoCircle::Draw()
{
	hoDrawable::Draw();
	if (!fill) {
		glBegin(GL_LINE_LOOP);						//Hago varias lineas, poniendo sus puntos A y B en la posicion necesaria segun el radio y los segmentos de el circulo
		for (int i = 0; i < segments; i++)
		{
			float degInRad = i * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(position.x + cos(degInRad)*radius, position.y + sin(degInRad)*radius);
		}
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < segments; i++)
		{
			float degInRad1 = i * (360.0f / segments) * M_PI / 180.0f;
			float degInRad2 = (i+1) * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(position.x + cos(degInRad1)*radius, position.y + sin(degInRad1)*radius);
			glVertex2f(position.x + cos(degInRad2)*radius, position.y + sin(degInRad2)*radius);
			glVertex2f(position.x, position.y);
		}
		glEnd();
	}
}

void hoEllipse::Draw()
{
	hoDrawable::Draw();
	glPushMatrix();
	glTranslatef(position.x, position.y, 0.0f);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	
	if (!fill) {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < segments; i++)			//Lo mismo que el circulo, solo que para asignar el valor X de los puntos uso el ancho en lugar de el radio, y para Y uso el alto.
		{
			float degInRad = i * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(cos(degInRad)*sizes.x, sin(degInRad)*sizes.y);
		}
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < segments; i++)			//Misma logica que el GL_LINE_LOOP pero utilizando triangulos, uniendo lo que en GL_LINE_LOOP seria la base de el triangulo con el centro de la elipse
		{
			float degInRad1 = i * (360.0f / segments) * M_PI / 180.0f;
			float degInRad2 = (i+1) * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(cos(degInRad1)*sizes.x, sin(degInRad1)*sizes.y);
			glVertex2f(cos(degInRad2)*sizes.x, sin(degInRad2)*sizes.y);
			glVertex2f(0.0f, 0.0f);
		}
		glEnd();
	}

	glPopMatrix();
}

void hoDrawable::Draw()
{
	glColor4f(rgba[0], rgba[1], rgba[2], rgba[3]);		//Cambio el color del brush a el color de el drawable
}

void hoDrawable::setColor(float _rgba[4])
{
	for (int i = 0; i < 4; i++) {
		rgba[i] = _rgba[i];			//Asigno el color
	}
}

void hoRect::Draw()
{
	hoDrawable::Draw();				//Dibujo un rect con la posicion en el centro, empezando en el pertice superior derecho y llendome en sentido horario
	glPushMatrix();
		glTranslatef(position.x, position.y, 0);
		glRotatef(rotation, 0.0f, 0.0f, 1.0f);

	if (!fill) {
		glBegin(GL_LINE_LOOP);
			glVertex2f(sizes.x / 2.0f, sizes.y / 2.0f);
			glVertex2f(sizes.x / 2.0f, -sizes.y / 2.0f);
			glVertex2f(-sizes.x / 2.0f, -sizes.y / 2.0f);
			glVertex2f(-sizes.x / 2.0f, sizes.y / 2.0f);
		glEnd();
	}
	else {
		glBegin(GL_QUADS);			//Lo mismo pero con GL_QUADS
			glVertex2f(sizes.x / 2.0f, sizes.y / 2.0f);
			glVertex2f(sizes.x / 2.0f, -sizes.y / 2.0f);
			glVertex2f(-sizes.x / 2.0f, -sizes.y / 2.0f);
			glVertex2f(-sizes.x / 2.0f, sizes.y / 2.0f);
		glEnd();
	}

	glPopMatrix();
}
