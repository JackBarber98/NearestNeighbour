#pragma once
#include "LargeImage.h"
#include "ReferenceImage.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class OutputHandler
{

/*The output handler class only has two functions. The punlic function 
WriteToFile requires access to the Shade function, but no other functions 
do so the latter can be set to private
*/
public:
	OutputHandler(double**, int, LargeImage, ReferenceImage);
	~OutputHandler();
	void WriteToFile();
private:
	void Shade();
	unsigned char *image1D;
	unsigned char** image2D;
	double** matches;
	int n;
	LargeImage background;
	ReferenceImage reference;
};

