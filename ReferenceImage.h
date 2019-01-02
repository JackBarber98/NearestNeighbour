#pragma once
#include "BaseImage.h"
#include <string>
class ReferenceImage: public BaseImage
{
public:
	ReferenceImage();
	~ReferenceImage();
	//The hollow, virtual ImportImage definition in the BaseImage class allows for a unique definition to be written here
	virtual void ImportImage(bool);
};

