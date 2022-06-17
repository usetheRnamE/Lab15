#include "Libs.h"
#include <string>

unsigned int iterationNum = 0;

bool GetValue(std::fstream& currentFile, std::string fileName, std::string fileType, double arrX[], double arrY[]) {
	currentFile.open(fileName + fileType, std::ios::in);

	if (!currentFile)
	{
		std::cout << "Eror: Cannot open the file" << '\n';
		return false;
	}

	for (; !currentFile.eof(); iterationNum++)
	{
		currentFile >> arrX[iterationNum];
		currentFile >> arrY[iterationNum];

		std::cout << "X: " + std::to_string(arrX[iterationNum]) + "Y: " + std::to_string(arrY[iterationNum]) << '\n';
	}

	currentFile.close();

	std::cout << "Total iterations: " + iterationNum << '\n';

	void SetMaxnMinValue();

	return true;
}