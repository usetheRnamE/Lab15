#include "DataBase.cpp"
#include "FileReader.cpp"

#pragma region STRUCTS
struct LangValueFile
{
	std::fstream langFileRef;
	const std::string fileName = "LangValues";
	const std::string fileType = ".txt";
} langValueFile;

#pragma endregion

void SetValueToAFile(double x, double y)
{
	langValueFile.langFileRef << x;
	langValueFile.langFileRef << y;
}

void CloseTheFile(std::fstream& fileToClose)
{
	fileToClose.close();

	std::cout << "Lang file is closed" << '\n';
}

void LangrangFuncCalculator()
{
	std::cout << "Lang Calculate" << '\n';

	double langSum = 0;

	for (double x = X.Min ; x < X.Max; x += .01)
	{
		for (int i = 1; i <= iterationNum; i++)
		{
			double langMul = 1;

			for (int j = 1; j <= iterationNum; j++)
			{
				if (i != j)
				{
					langMul *= (x - vectors2.X[i]) / (vectors2.X[i] - vectors2.X[j]);
				}
			}

			langSum += langMul * vectors2.Y[i];

			SetValueToAFile(x, langSum);
		}
	}
	CloseTheFile(langValueFile.langFileRef);
}
