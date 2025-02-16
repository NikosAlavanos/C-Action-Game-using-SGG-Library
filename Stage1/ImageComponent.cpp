#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "ImageComponent.h"

ImageComponent::ImageComponent(float x, float y, float width, float height, string texture) :
	x(x), y(y), width(width), height(height), texture(texture)
{
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 1.0f;
	br.fill_secondary_color[2] = 1.0f;
	br.outline_opacity = 0.0f;
	br.texture = texture;
}

void ImageComponent::draw()
{		
	graphics::drawRect(x, y, width, height, br);
}

void ImageComponent::update(float ms)
{
}
