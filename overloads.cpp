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

std::istream& operator>>(std::istream& in, Planet& object)
{
	system("cls");
	std::cout << "Введите следующие поля: \n\n" << "Название планеты: ";
	char* temp = new char[30];
	std::cin >> temp;
	object.name_size = length(temp) + 1;
	object.name = new char[object.name_size];
	for (int i = 0; i < object.name_size; i++)
	{
		object.name[i] = temp[i];
	}

	bool flag = false;
	int new_diameter = 0;
	while (!flag)
	{
		flag = true;
		std::cout << "\nДиаметр планеты(введите число): ";
		std::cin >> temp;
		for (int i = 0; i < length(temp); i++)
		{
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				new_diameter *= 10;
				new_diameter += temp[i] - '0';
			}
			else
			{
				flag = false;
				std::cout << "\n\nВведено некорректное значение поля! Пожалуйста, введите число.\n";
				break;
			}
		}
	}
	object.diameter = new_diameter;

	flag = false;
	while (!flag)
	{
		flag = true;
		std::cout << "\nНаличие жизни(введите 1 или 0 - есть/нет соответственно): ";
		std::cin >> temp;
		if (!(length(temp) == 1 && (temp[0] == '1' || temp[0] == '0')))
		{
			flag = false;
			std::cout << "\n\nВведено некорректное значение поля! Пожалуйста введите 1 или 0.\n";
		}
	}
	object.life = temp[0] - '0';

	flag = false;
	int new_sat = 0;
	while (!flag)
	{
		flag = true;
		std::cout << "\nКоличество спутников(введите число): ";
		std::cin >> temp;
		for (int i = 0; i < length(temp); i++)
		{
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				new_sat *= 10;
				new_sat += temp[i] - '0';
			}
			else
			{
				flag = false;
				std::cout << "\n\nВведено некорректное значение поля! Пожалуйста, введите число.\n";
				break;
			}
		}
	}
	object.satellites = new_sat;
	delete[] temp;
	return in;
}

std::ofstream& operator<<(std::ofstream& fout, const Planet& object)
{
	fout << std::setw(13) << std::left << object.name;
	fout << std::setw(13) << std::left << object.diameter;
	fout << std::setw(13) << std::left << object.life;
	fout << std::setw(13) << std::left << object.satellites;
	return fout;
}

std::ostream& operator<<(std::ostream& out, const Planet& object)
{
	out << std::setw(13) << std::left << object.name;
	out << std::setw(13) << std::left << object.diameter;
	out << std::setw(13) << std::left << object.life;
	out << std::setw(13) << std::left << object.satellites;
	return out;
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