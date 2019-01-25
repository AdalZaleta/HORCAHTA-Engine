#pragma once
#include <iostream>
#include <vector>
#include "rapidjson/document.h"
#include <string>
#include <fstream>
#include <streambuf>

using namespace rapidjson;

class hoAtlas
{
public:
	hoAtlas() {}
	~hoAtlas() {}

	struct SpriteItem //estructura para la informacion de cada sprite
	{
		std::string name;
		int x;
		int y;
		int width;
		int height;
	};

	std::vector<SpriteItem> items; //vector contenedor de todos los frames

	bool loadAtlas(const char *_dirImage, const char *_json)
	{
		//This const char will be the prefix of the image
		const char *prefix = "Resources/";
		//This char array will be concatenate the path
		char result[100];
		//Here we concatenate the prefix
		strcpy_s(result, prefix);
		//Here we add the final path
		strcat_s(result, _json);

		std::ifstream t(result);
		std::string str;

		t.seekg(0, std::ios::end);
		str.reserve(t.tellg()); //magia del internet
		t.seekg(0, std::ios::beg);

		str.assign((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());

		

		Document document;
		document.Parse(str.c_str());
		if (document == NULL) //seguridad
		{
			return false;
		}
		assert(document.IsObject()); //asegurarse que es objeto 
		const Value& frames = document["frames"];
		assert(frames.IsArray()); //asegurarse que es arreglo
		SpriteItem temp;
		for (SizeType i = 0; i < frames.Size(); i++) //mete a un vector cada sprite de la spritesheet
		{
			temp.name.assign(frames[i]["filename"].GetString());
			temp.x = frames[i]["frame"]["x"].GetInt();
			temp.y = frames[i]["frame"]["y"].GetInt();
			temp.width = frames[i]["frame"]["w"].GetInt();
			temp.height = frames[i]["frame"]["h"].GetInt();
			items.push_back(temp);
		}
		for (int j = 0; j < items.size(); j++)
		{
			printf("El item[%d] de la lista se llama: %s, \nX: %d,\nY: %d,\nW: %d,\nH: %d\n--------------------------\n",j, items[j].name.c_str(), items[j].x, items[j].y, items[j].width, items[j].height);
		}

		return true;
	}

	//Recibe el nombre del sprite y devuelve el SpriteItem correspondiente
	SpriteItem GetSpriteDetails(const char *_name) //te da la informacion de el frame que pides en el argumento
	{
		
		for (int i = 0; i < items.size(); i++)
		{
			//printf("Intentando comparar %s con %s", items[i].name, _name);
			int comp = items[i].name.compare(_name);
			if (comp == 0)
			{
				//printf_s("Entro esta madre\n");
				return items[i];
			}
		}

	}
};
