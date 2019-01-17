#pragma once
#include <iostream>
#include <list>
#include "rapidjson/document.h"

using namespace rapidjson;

class hoAtlas
{
public:
	hoAtlas() {}
	~hoAtlas() {}

	struct SpriteItem
	{
		const char *name;
		int x;
		int y;
		int width;
		int height;
	};

	std::list<SpriteItem> items;

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

		std::fstream f(result, std::fstream::in);
		std::string s;
		getline(f, s, '\0');
		f.close();


		Document document;
		document.Parse(s.c_str());
		if (document == NULL)
		{
			printf("KK\n");
			return false;
		}
		assert(document.IsObject());
		const Value& frames = document["frames"];
		//assert(frames.IsArray());
		for (SizeType i = 0; i < frames.Size(); i++)
		{
			printf("frames[%d] = %s\n", i, frames[i].GetString());
		}
		return true;
	}
};
