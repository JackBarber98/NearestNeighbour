#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Matrix
{
	/* This operator overload allows for the dot product of two matrices to be calculated 
	without calling a function. If the dot product cannot be calculated, an error is thrown 
	and the user is informed that the calculation was unsucessful before the program closes
	*/
	friend double operator * (Matrix& left, Matrix& right) {
		double dotproduct = 0;
		try {
			for (int i = 0; i < left.width * left.height; i++) {
				dotproduct += left.matrix1D[i] * right.matrix1D[i];
			}
		}
		catch (...) {
			cout << "Dot product cannot be calculated because they have different dimensions. " << endl;
			system("pause");
			exit(1);
		}
		return dotproduct;
	}

	//All functions and variables that form the matrix class must be public
public:
	Matrix();
	Matrix(int, int);
	~Matrix();
	void Create(ifstream&);
	void Magnitude();
	void Display();
	void ConvertTo2D();
	int width;
	int height;
	double magnitude;
	double* matrix1D;
	vector<vector<int>> values;
};

