#include "NearestNeighbour.h"
using namespace std;

/* The constructor for the nearest neighbour class takes a value of n which is the number of closest matches
the algorithm must attempt to find. A map is initialised to store the similarity value at specified coordinates.
A 2D array is also created that will be used to store all similarity values, and is mapped to the matrix they were
calculated from
*/
NearestNeighbour::NearestNeighbour(int& n)
{
	this->n = n;
	simLocations = map<double, pair<int, int>>();
	matches = new double*[n];
	for (int i = 0; i < n; i++) {
		matches[i] = new double[2];
	}
}

NearestNeighbour::~NearestNeighbour()
{
}

/* This function takes a reference to the reference image, larger background image, and a 
boolean dictating whether calculation details are to be shown or not. The function created
a partial matrix, which is populated with a matrix extracted from the larger image to be 
compared to the reference image. The partial matrix is populated with a matrix equal in 
width and height to that of the reference image, with the values taken from the background
image at incrementing coordinal locations. The consine similarity of this partial matrix and 
the reference image's matrix is then calculated and stored in a map alongside the coordinates 
of the top left corner the partial matrix was extracted from
*/
void NearestNeighbour::ScanBackground(ReferenceImage& reference, LargeImage& background, bool& detail) {
	simSize = (background.width - reference.width) * (background.height - reference.height);
	similarities = new double[simSize];
	ReferenceImage partial = ReferenceImage();
	double* backgroundValues = background.matrix.matrix1D;
	int count = 0;
	double bestSim = 0;
	for (int bCol = 0; bCol < background.width - reference.width; bCol += reference.width / 2) {
		for (int bRow = 0; bRow < background.height - reference.height; bRow += reference.height / 2) {
			for (int rCol = 0; rCol < reference.width; rCol++) {
				for (int rRow = 0; rRow < reference.height; rRow++) {
					partial.matrix.matrix1D[rRow * partial.width + rCol] = backgroundValues[(bRow + rRow) * background.width + (bCol + rCol)];
				}
			}
			double sim = CosineSimilarity(partial.matrix, reference.matrix);
			similarities[count] = sim;
			simLocations[sim] = pair<int, int>{ bCol, bRow };
			count++;
		}
	}
}

/* To calculate the cosine similarity, the magnitudes of both the partial matrix is calculated. The magnitude of the reference matrix
was calculated soon after initialisation in order to enhance efficency. The dot product of the
partial and reference matrices are then calculated. A similarity is found by dividing the dot product by the product of the two magnitudes
*/
double NearestNeighbour::CosineSimilarity(Matrix& partial, Matrix& reference) {
	partial.Magnitude();
	double dotProduct = partial * reference;
	return dotProduct / (partial.magnitude * reference.magnitude);
}

/* The nth best matches are found by sorting the similarities array from greatest to smallest,
and the first n similarities found are stored in the matches array alongside the location the 
similarity was calculated
*/
void NearestNeighbour::GetNthBestMatch(bool showCalcs) {
	sort(similarities, similarities + simSize , greater<double>());
	for (int i = 0; i < n; i++) {
		matches[i][0] = simLocations[similarities[i]].first;
		matches[i][1] = simLocations[similarities[i]].second;
		if (showCalcs) {
			cout << "Coordinate: (" << matches[i][0] << ", " << matches[i][1] << ") \t Similarity: " << similarities[i] << endl;
		}
	}
}
