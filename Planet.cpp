#include "Headers.h"

//описание конструкторов и деструкторов

Planet::Planet()
{
	name_size = 1;
	name = new char[name_size];
	diameter = 0;
	life = 0;
	satellites = 0;
}

//основные функции меню

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

void Planet::writeDB(const char* fileName, Planet* object, const int& object_count)
{
	std::ofstream fout(fileName, std::ios_base::trunc);
	fout << std::setw(13) << std::left << "Название";
	fout << std::setw(13) << std::left << "Диаметр";
	fout << std::setw(13) << std::left << "Жизнь";
	fout << std::setw(13) << std::left <<"Спутники";
	fout << "\n";
	for (int i = 0; i < object_count; i++)
	{
		fout << object[i] << '\n';
	}
	fout.close();
}

void Planet::printDB(Planet* object, const int& object_count)
{
	system("cls");
	std::cout << std::setw(9) << std::left << "Название";
	std::cout << std::setw(9) << std::left << "Диаметр";
	std::cout << std::setw(9) << std::left << "Жизнь";
	std::cout << std::setw(9) << std::left << "Спутники";
	std::cout << "\n";
	for (int i = 0; i < object_count; i++)
	{
		std::cout << object[i] << "\n";
	}
}

Planet* Planet::editDB(Planet* object, int& object_count)
{
	int mode;
	while (true)
	{
		while (true)
		{
			system("cls");
			editMenu();
			std::cin >> mode;
			if (mode < 1 || mode > 4)
			{
				std::cout << "Введите номер существующего действия!(1-4).\n";
				system("pause");
			}
			else {
				break;
			}
		}
		switch (mode)
		{
		case 1:
			addToDB(object, object_count);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return object;
			break;
		}
	}
}

//методы меню редактирования

Planet* Planet::addToDB(Planet* object, int& object_count)
{
	reSize(object, object_count, 1);

}

//побочные методы класса

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

void Planet::setName(char* new_name) 
{
	name = strcpy(name, new_name);
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
