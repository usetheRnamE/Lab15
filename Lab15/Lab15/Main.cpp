#pragma region LIBS
#include "PlotLib/pbPlots.hpp"
#include "PlotLib/supportLib.hpp"

#include <vector>
#include "Libs.h"
#include "DataBase.cpp"
#include "FileReader.cpp"
#pragma endregion

#pragma region STRUCTS
struct Vectors {
	std::vector<double> X;
	std::vector<double> Y;
} FuncVec;

struct Arrays {
	double Xa[Lenght], Ya[Lenght];
} FuncArr;

struct ImgReference {

} funcImgRef, appFuncImgRef;

struct FileName {
	std::fstream fileRef;
	const std::string fileName = "Func";
	const std::string fileType = ".png";
} funcFile;
#pragma endregion

bool GetValue(std::fstream& currentFile, std::string fileName, std::string fileType, double arrX[], double arrY[]);

const unsigned presicion = .001;

bool VectorsSetUp()
{
	if (GetValue(funcFile.fileRef, funcFile.fileName, funcFile.fileType, FuncArr.Xa, FuncArr.Ya))
	{
		FuncVec.X = std::vector<double>(std::begin(FuncArr.Xa), std::end(FuncArr.Xa));
		FuncVec.Y = std::vector<double>(std::begin(FuncVec.Y), std::end(FuncVec.Y));
	}

	std::cout << "Vector is seted up" << '\n';
	return true;
}

void DrawTheFunc(RGBABitmapImageReference* currentImgRef, std::string fileName, std::string fileType)
{
	std::cout << "Drawing has been started" << '\n';

	DrawScatterPlot(currentImgRef, 600, 400, &FuncVec.X, &FuncVec.Y, nullptr);

	std::vector<double>* pngData = ConvertToPNG(currentImgRef->image);
	WriteToFile(pngData, fileName + fileType);
	DeleteImage(currentImgRef->image);
}

int main()
{
	std::cout << "Program has been started" << '\n';

	RGBABitmapImageReference* ImgRef = CreateRGBABitmapImageReference();
	
	if(VectorsSetUp())
      DrawTheFunc(ImgRef, funcFile.fileName, funcFile.fileType);

	std::cout << "Program has been finished" << '\n';
}



