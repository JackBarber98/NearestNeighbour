#include "LargeImage.h"

/* As the dimensions of the larger image were provided, the process of calculating their dimensions 
is not required, and would make the execution of the program slower. The dimensions of the larger 
image are stored as local variables alongside the filename of the relevant .txt file.

The matrix associated with this image is then initialised, taking the images' width and height as parameters
*/
LargeImage::LargeImage()
{	
	filename = "Cluttered_scene.txt";
	width = 1024;
	height = 768;
	matrix = Matrix(width, height);
}

LargeImage::~LargeImage()
{
}

// This function is responsible for importing the image and then formatting its contents as a matrix 
void LargeImage::ImportImage(bool showMatrices) {
	//A file stream is created that then has an instance of a reference created
	ifstream file;
	ifstream& fileRef = file;
	//The file is opened and if it exists, a 1D matrix is created using the image's pixel values alongside a 2D equivalent
	file.open(filename);
	if (file) {
		matrix.Create(fileRef);
		matrix.ConvertTo2D();
		//Display the contents of the larger image's matrix if the user set showCalcs to true
		if (showMatrices) {
			cout << "Contents of background image: " << '\n';
			matrix.Display();
		}
	} //If the file does not exist, the user is warned of this and the program closes after a further input of any sort
	else {
		//Note that the use of a virtual function here allows for a prompt stating that specifically the larger image has not been found
		cout << "Background image file " << filename << " not found. " << endl;
		system("pause");
		exit(0);
	}

	//The file is closed after any processing requiring it occurs
	file.close();
}
