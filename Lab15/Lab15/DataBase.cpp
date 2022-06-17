#pragma region LIBS
#include <iostream>
#include <fstream>
#include <string>
#pragma endregion

#pragma region STRUCTS
const unsigned int Lenght = 40;

struct ValueFile
{
	const std::string fileName = "Value";
	const std::string fileType = ".txt";
} valueFile;

struct Vectors2
{
	double X[Lenght], Y[Lenght];
} vectors2;

struct MaxnMin 
{
	double Max, Min;
} X, Y;
#pragma endregion

class DataBase
{
	std::fstream ValueLib;

#pragma region (DE/CON)STRUCTOR
	DataBase()
	{
		X.Max = 0;
		X.Min = 0;

		Y.Max = 0;
		Y.Min = 0;
	}
	
	~DataBase();
#pragma endregion

	void GetValue() {
		ValueLib.open(valueFile.fileName + valueFile.fileType, std::ios::in);

		if (!ValueLib)
		{
			std::cout << "Eror: Cannot open the file" << '\n';
			return;
		}

		int i = 0;

		for (; !ValueLib.eof(); i++)
		{
			ValueLib >> vectors2.X[i];
			ValueLib >> vectors2.Y[i];

			std::cout << "X: " + std::to_string(vectors2.X[i]) + "Y: " + std::to_string(vectors2.Y[i]) << '\n';
		}

		ValueLib.close();

		std::cout << "Total iterations: " + i << '\n';

		void SetMaxnMinValue();
	}

	void SetMaxnMinValue()
	{
		X.Max = MaxOrMinValueFind(vectors2.X, true);
		X.Min = MaxOrMinValueFind(vectors2.X, false);

		Y.Max = MaxOrMinValueFind(vectors2.Y, true);
		Y.Min = MaxOrMinValueFind(vectors2.Y, false);
	}

	double MaxOrMinValueFind(double arr[], bool MaxOrMin)
	{
		double Max = 0, Min = 0;

		bool IsAlreadyCounted = false;

		if (IsAlreadyCounted)
			for (int i = 0; i < sizeof(arr); i++)
			{
				if (arr[i] > Max && MaxOrMin)
					Max == arr[i];
				else if (arr[i] < Max && !MaxOrMin)
					Min == arr[i];
			}

		IsAlreadyCounted != IsAlreadyCounted;

	    if (MaxOrMin)
			return Max;
		else
			return Min;
	}
};