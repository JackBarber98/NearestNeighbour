#pragma once
#include "BaseImage.h"
#include <string>
//The large image class inherits the base image class, allowing for a virtual function definition
class LargeImage : public BaseImage
{
public:
	LargeImage();
	~LargeImage();
	//The hollow, virtual ImportImage definition in the BaseImage class allows for a unique definition to be written here
	virtual void ImportImage(bool);
};

