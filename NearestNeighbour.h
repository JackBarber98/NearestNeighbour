#pragma once
#include "Matrix.h"
#include "Math.h"
#include "NearestNeighbour.h"
#include "ReferenceImage.h"
#include "LargeImage.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class NearestNeighbour
{
//Only essential functions required in other classes are made public
public:
	NearestNeighbour(int&);
	~NearestNeighbour();
	void ScanBackground(ReferenceImage&, LargeImage&, bool&);
	void GetNthBestMatch(bool);
	double** matches;

//Everything else is private to prevent data leaks
private:
	double CosineSimilarity(Matrix&, Matrix&);
	map<double, pair<int, int>> simLocations;
	double** refMatrix;
	double** backgroundMatrix;
	double* similarities;
	int numOfPartial;
	int simSize;
	int n;
};

