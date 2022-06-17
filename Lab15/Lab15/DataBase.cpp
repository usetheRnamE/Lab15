#include <string>
#include "Libs.h";

#pragma region STRUCTS
static const unsigned int Lenght = 40;

struct ValueFile
{
	std::fstream fileRef;
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

bool GetValue(std::fstream& currentFile, std::string fileName, std::string fileType, double arrX[], double arrY[]);

class DataBase
{

#pragma region (DE/CON)STRUCTOR
	DataBase()
	{
		X.Max = 0;
		X.Min = 0;

		Y.Max = 0;
		Y.Min = 0;

		if (GetValue(valueFile.fileRef, valueFile.fileName, valueFile.fileType, vectors2.X, vectors2.Y))
			SetMaxnMinValue();		
	}
	
	~DataBase() {}
#pragma endregion

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