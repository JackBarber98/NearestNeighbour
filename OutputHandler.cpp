#include "OutputHandler.h"

/*The constructor takes the matches array, the number of matches to find, and the large and reference 
image objects as parameters, storing them locally
*/

using namespace std;
OutputHandler::OutputHandler(double** matches, int n, LargeImage background, ReferenceImage reference)
{
	this->n = n;
	this->matches = matches;
	this->background = background;
	this->reference = reference;
	image1D = new unsigned char[background.width * background.height];
	image2D = new unsigned char*[background.width];
	for (int i = 0; i < background.width; i++) {
		image2D[i] = new unsigned char[background.height];
	}
}

OutputHandler::~OutputHandler()
{

}

//This function is responsible for formatting the output file and writing data to the file itself
void OutputHandler::WriteToFile() {
	//The background image's matrix is shaded where the algorithm determines the n most likely locations Wally are
	Shade();
	//An output file stream is created to which the output data will eventually be written
	ofstream file;
	string filename = "output.pgm";

	//The file is opened to allow for binary data to be written to it
	file.open(filename, ios::out | ios::binary | ios::trunc);

	//If the file is not found, an error is thrown 
	if (!file) {
		cout << "File not found. \n" <<  endl;
		system("pause");
		exit(0);
	}

	//The file header is initialised, and the shaded background image is written to the file
	file << "P5 " << background.width << " " << background.height << " " << 255 << endl;
	file.write(reinterpret_cast<char *> (image1D), (background.width * background.height) * sizeof(unsigned char));

	//If the program fails to write to the file, the user is told and the program exits
	if (file.fail()) {
		std::cout << "Image could not be written to file. \n" << endl;
		system("pause");
		exit(0);
	}
}

//Responsible for applying shading to the background image based on the probable locations of Wally
void OutputHandler::Shade() {
	//The background matrix is written to a 1D array that is later written to the file. Integer pixel values are converted to unsigned chararacters
	for (int x = 0; x < background.width; x++) {
		for (int y = 0; y < background.height; y++) {
			image2D[x][y] = (unsigned char) background.matrix.values[x][y];
		}
	}

	//The image is scanned through again, and if a location is landed upon where Wally is predicted to be, it's pixel value is made darker
	for (int k = 0; k < this->n; k++) {
		for (int x = matches[k][0]; x < matches[k][0] + reference.width; x++) {
			for (int y = matches[k][1]; y < matches[k][1] + reference.height; y++) {
				image2D[x][y] = (unsigned char) background.matrix.values[x][y] * 0.4;
			}
		}
	}

	//Copies the two-dimensional format of the output data to a one-dimensional version to allow for output streaming
	for (int x = 0; x < background.width; x++) {
		for (int y = 0; y < background.height; y++) {
			image1D[y * background.width + x] = image2D[x][y];
		}
	}
}