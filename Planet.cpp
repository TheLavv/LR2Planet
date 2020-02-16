#include "Headers.h"

Planet::Planet()
{
	name_size = 1;
	name = new char[name_size];
	diameter = 0;
	life = 0;
	satellites = 0;
}

Planet* Planet::reSize(Planet* object, int& object_count, int resize_count)
{
	object_count += resize_count;
	Planet* temp = new Planet[object_count];
	for (int i = 0; i < (resize_count > 0 ? object_count - resize_count : object_count); i++)
	{
		temp[i] = object[i];
	}
	delete[] object;
	object = temp;
	temp = nullptr;
	return object;
}

Planet* Planet::readDB(const char* fileName, Planet* object, int& object_count)
{
	std::ifstream fin;
	fin.open(fileName, std::ios::binary);
	unsigned char sym;
	do
	{
		fin >> std::noskipws >> sym;
	} while (sym != '\n');
	while (true)
	{
		object = reSize(object, object_count, 1);
		fin >> object[object_count - 1];
		if (fin.eof())
			break;
	}
	object = reSize(object, object_count, -1);
	fin.close();
	return object;
}

void Planet::setName(char* new_name) 
{
	strcpy(name, new_name);
}

void Planet::setDiameter(int new_diameter)
{
	if (new_diameter > 0)
		diameter = new_diameter;
}

void Planet::setLife(bool new_life)
{
	life = new_life;
}

void Planet::setSatellites(int new_satellites)
{
	if (new_satellites >= 0)
		satellites = new_satellites;
}
