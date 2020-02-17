#include "Headers.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int object_count = 0;
	Planet* object = nullptr;
	const char* fileName = "DataBase.txt";
	while (true)
	{
		int mode;
		while (true)
		{
			system("cls");
			mainMenu();
			std::cin >> mode;
			if (mode < 1 || mode > 6)
			{
				std::cout << "Введите номер существующего действия!(1-6).\n";
				system("pause");
			}
			else {
				break;
			}
		}
		switch (mode)
		{
		case 1: 
			object = Planet::readDB(fileName, object, object_count);
			system("cls");
			std::cout << "База данных успешно считана из файла.\n\n";
			system("pause");
			break;
		case 2:
			Planet::writeDB(fileName, object, object_count);
			system("cls");
			std::cout << "База данных успешно записана в файл.\n\n";
			system("pause");
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			system("cls");
			Planet::printDB(object, object_count);
			break;
		case 6:
			return 0;
			break;
		}

	}
	delete[] object;
	return 0;
}