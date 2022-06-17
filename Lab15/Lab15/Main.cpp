#include "PlotLib/pbPlots.hpp"
#include "PlotLib/supportLib.hpp"

#include <vector>
#include <iostream>

struct Vectors {
	std::vector<double> X;
	std::vector<double> Y;
} FuncVec, AppFuncVec;

struct ImgReference {
	
} funcImgRef, appFuncImgRef;

struct FileName {
	std::string fileName = "Func";
	std::string fileType = ".png";
} funcFile;

void FuncVectorSetUp(double x)
{
	FuncVec.X.push_back(x);
	FuncVec.Y.push_back(FuncCalculate(x));
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

	for (double x = 0; x < funcInfoReference.fluctuationCount; x += funcInfoReference.presicion)
	{
		FuncVectorSetUp(x);
	}

	DrawTheFunc(ImgRef, funcFile.fileName, funcFile.fileType);

	funcInfoReference.CloseAllFiles();
	std::cout << "Program has been finished" << '\n';
}

