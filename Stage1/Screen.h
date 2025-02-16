#pragma once

#include "Drawable.h"

class Screen : public Drawable
{
public:
	virtual void draw() = 0;
	virtual void update(float ms) = 0;
};

