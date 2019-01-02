#pragma once
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class BaseImage
{
/* All the class's functions need to be public in order to be accessible by the NNS algorithm.
	The width and height of the image, alongside the matrix representation of the image, are also needed by other functions
*/ 
public:
	BaseImage();
	~BaseImage();
	virtual void ImportImage();
	int width;
	int height;
	Matrix matrix;
//The filename that contains the image data is only needed by the child classes, so can be made a protected variable
protected:
	string filename;
};

