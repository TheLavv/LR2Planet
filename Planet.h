#pragma once
#include "Headers.h"

class Planet {
private:
	char* name;
	int name_size;
	int diameter;
	int life;
	int satellites;
public:
	Planet();
	static Planet* readDB(const char* fileName, Planet* object, int& object_count);
	static Planet* reSize(Planet* object, int& object_count, int resize_count);
	void setName(char* new_name);
	void setDiameter(int new_diameter);
	void setLife(bool new_life);
	void setSatellites(int new_satellites);
	Planet& operator=(const Planet& object);
	friend std::ifstream& operator>>(std::ifstream& fin, Planet& object);
	friend int length(char* arr);
	friend char* strcpy(char* arr1, char* arr2);
};

