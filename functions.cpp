#include "Headers.h"

int length(char* arr)
{
	int i;
	for (i = 0; arr[i] != '\0'; i++);
	return i;
}

char* strcpy(char* arr1, char* arr2)
{
	delete[] arr1;
	int size = length(arr2) + 1;
	arr1 = new char[size];
	for (int i = 0; arr2[i] != '\0'; i++)
		arr1[i] = arr2[i];
	return arr1;
}