#pragma once
#include "Headers.h"

class Planet {
private:
	char* name;
	int name_size;
	int diameter;
	int life;
	int satellites;
	static Planet* reSize(Planet* object, int& object_count, int resize_count);	
	static Planet* addToDB(Planet* object, int& object_count);
	static Planet* deleteFromDB(Planet* object, int& object_count);
	static void editObject(Planet* object, const int& object_count);
public:
	Planet();
	Planet(const Planet& object);
	~Planet();
	static Planet* readDB(const char* fileName, Planet* object, int& object_count);
	static void writeDB(const char* fileName, Planet* object, const int& object_count);
	static void printDB(Planet* object, const int& object_count);
	static Planet* editDB(Planet* object, int& object_count);
	static void sortDB(Planet* object, const int& object_count);
	void setName(char* new_name);
	void setDiameter(int new_diameter);
	void setLife(bool new_life);
	void setSatellites(int new_satellites);
	friend int length(char* arr);
	friend char* strcpy(char* arr1, char* arr2);
	friend std::ifstream& operator>>(std::ifstream& fin, Planet& object);
	friend std::ofstream& operator<<(std::ofstream& fout, const Planet& object);
	friend std::ostream& operator<<(std::ostream& out, const Planet& object);
	friend std::istream& operator>>(std::istream& in, Planet& object);
	Planet& operator=(const Planet& object);
	bool operator<(const Planet& object);
};

