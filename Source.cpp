#include "LargeImage.h"
#include "ReferenceImage.h"
#include "Matrix.h"
#include "NearestNeighbour.h"
#include "OutputHandler.h"
#include "Console.h"
#include <iostream>
#include <chrono>

//Utilises the Clock() prexifx to allow for a more accurate system clock than the standard time.h instance
using Clock = std::chrono::high_resolution_clock;

int main() {

	/* Asks the user whether they want to view the similarity calculations made or not, the nth nearest 
	matches they wish to locate within the background image, and whetehr they wish to see the contents of 
	each matrix. These are stored as variables for later use
	*/
	Console c = Console();
	bool showCalcs = c.ShowCalculations();
	bool showMatrices = c.ShowDetail();
	int n = c.GetN();

	/* An instance of a large image object and a reference image object are declared and initialised
	   before the two respective image text files are imported. This process is timed and the result 
	   displayed to the user
	*/
	cout << "Importing images..." << '\n' << endl;
	LargeImage li = LargeImage();
	ReferenceImage ri = ReferenceImage();
	auto startImport = Clock::now();
	ri.ImportImage(showMatrices);
	li.ImportImage(showMatrices);
	auto endImport = Clock::now();
	cout << "Images imported in " << (endImport - startImport).count() / 1e9 << " seconds" << '\n' << endl;

	/* The nearest neighbour search algorithm is carried out on the previously imported images, a 
	process handled by the ScanBackground() function. Again, the process is times and the result
	displayed to the user
	*/
	cout << "Scanning (This may take up to 2 minutes)... \n" << endl;
	NearestNeighbour nn = NearestNeighbour(n);
	auto startScan = Clock::now();
	nn.ScanBackground(ri, li, showCalcs);
	auto endScan = Clock::now();
	cout << "Scan complete in " << (endScan - startScan).count() / 1e9 << " seconds. \n" << endl;

	//The nth best matches are located, ready to be shaded on the output pgm file
	cout << "Finding best match(es)... \n" << endl;
	auto startMatch = Clock::now();
	nn.GetNthBestMatch(showCalcs);
	auto endMatch = Clock::now();
	cout << n << " best matches found in " << (endMatch - startMatch).count() / 1e9 << " seconds \n" << endl;

	//The array of matches found by the Nearest Neighbour object previously is stored as a local variable
	double** matches = nn.matches;

	/* The backgrond image is written to a pgm file, with rectangles where the nth closest matches were found shaded. 
	There may be fewer visible rectangles than n because they may overlap.
	*/
	cout << "Writing output to pgm file... \n" << endl;
	OutputHandler oh = OutputHandler(matches, n, li, ri);
	auto startWrite = Clock::now();
	oh.WriteToFile();
	auto endWrite = Clock::now();
	cout << "Output data written to file in " << (endWrite - startWrite).count() / 1e9 << " seconds \n" << endl;
	//The total time the program takes to find Wally is calculated and displayed to the user
	cout << "Program took a total of " << (endWrite - startImport).count() / 1e9 << " seconds to run. " << '\n' << endl;

	//The user is required to press any key before the program closes
	system("pause");
	exit(0);
	return 0;
}