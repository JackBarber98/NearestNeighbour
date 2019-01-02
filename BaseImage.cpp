#include "BaseImage.h"
using namespace std;

/* The base class is an interface class as it contains only hollow class definitions. 
The large image and reference image classes inherit this one
*/
BaseImage::BaseImage()
{

}

BaseImage::~BaseImage()
{

}

/* This is used to import the .txt files and create a matrice for each. Different outputs
are printed to the user depending on the image being imported, so it is a virutal function to allow for this
*/ 
void BaseImage::ImportImage() {

}