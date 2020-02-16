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
			if (mode < 1 || mode > 5)
			{
				std::cout << "¬ведите номер существующего действи€!(1-5).\n";
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
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}

	}
	delete[] object;
	return 0;
}