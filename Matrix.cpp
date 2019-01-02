#include "Matrix.h"
using namespace std;

/* An empty, default constructor is required because matrices are defined in the LargeImage 
and ReferenceImage classes without initialisation
*/
Matrix::Matrix() {

}

/* An overloaded constructor is created that takes the width and height of the matrix as parameters
These are then stored as local variables. A 1D version of a matrix is first created as an array, followed
by a 2D version based on vectors in order to demonstrate use of the std namespace. The 2D matrix is 
resized to ensure that enough memory is reserved
*/
Matrix::Matrix(int matrixWidth, int matrixHeight) {
	width = matrixWidth;
	height = matrixHeight;
	matrix1D = new double[matrixWidth * matrixHeight];
	values = vector<vector<int>>();
	values.resize(width);
	for (int x = 0; x < width; x++) {
		values.at(x).resize(height);
	}
}

Matrix::~Matrix()
{

}

//This function streams the contents of the .txt file to a 1D arrray which is used to represent a matrix
void Matrix::Create(ifstream& file) {
	int i = 0;
	if (file.is_open())
	{
		while (file.good())
		{
			if (i >= width * height) break;
			file >> *(matrix1D + i);
			//cout << *(matrix1D + i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		file.close();
	}
}

/* This function is required to calculate the cosine similarity of two matrices. To 
calculate the magnitude of a matrix, the sum of all its values is found before the square root is returned
*/
void Matrix::Magnitude() {
	magnitude = 0;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
				magnitude += matrix1D[y * width + x] * matrix1D[y * width + x];
		}
	}
	magnitude = sqrt(magnitude);
}

//Converts the one dimensional version of the matrix to a 2D equivalent, maintaining structure as appropriate
void Matrix::ConvertTo2D() {
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++) {
			values[x][y] = matrix1D[y * width + x];
		}
	}
}

//The value of each cell of the matrix is printed to the screen
void Matrix::Display() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			cout << matrix1D[y * width + x] << " ";
		}
	}
}