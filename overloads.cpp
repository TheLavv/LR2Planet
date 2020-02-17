#include "Headers.h"

//перегрузки операторов

std::ifstream& operator>>(std::ifstream& fin, Planet& object)
{
	unsigned char sym;
	bool flag = false;
	int field = 0;
	fin >> std::noskipws >> sym;
	while (sym == ' ' || sym == '\t')
	{
		fin >> std::noskipws >> sym;
	}
	while (sym != '\n' && !fin.eof() && sym != '\r')
	{
		if (sym != ' ' && sym != '\t')
		{
			if (field == 0)
			{
				int size = object.name_size + 1;
				char* temp = new char[size];
				for (int i = 0; i < size - 1; i++)
				{
					temp[i] = object.name[i];
				}
				temp[size - 2] = sym;
				temp[size - 1] = '\0';
				object.name_size++;
				delete[] object.name;
				object.name = temp;
				temp = nullptr;
			}
			else if (field == 1)
			{
				object.diameter *= 10;
				object.diameter += sym - '0';
			}
			else if (field == 2)
			{
				object.life *= 10;
				object.life += sym - '0';
			}
			else if (field == 3)
			{
				object.satellites *= 10;
				object.satellites += sym - '0';
			}
		}
		else
		{
			while (sym == ' ' || sym == '\t')
			{
				fin >> std::noskipws >> sym;
			}
			flag = true;
			field++;
		}
		if (!flag)
		{
			fin >> std::noskipws >> sym;
		}
		else
			flag = false;
	}
	if(sym == '\r')
		fin >> sym;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Planet& object)
{
	fout << std::setw(13) << std::left << object.name;
	fout << std::setw(13) << std::left << object.diameter;
	fout << std::setw(13) << std::left << object.life;
	fout << std::setw(13) << std::left << object.satellites;
	return fout;
}

Planet& Planet::operator=(const Planet& object)
{
	name_size = object.name_size;
	delete[] name;
	name = new char[name_size];
	for (int i = 0; i < name_size; i++)
		name[i] = object.name[i];
	diameter = object.diameter;
	life = object.life;
	satellites = object.satellites;
	return *this;
}