#include <iostream>
#include <random>
#include <string>

#include <sgg/graphics.h>

#include "TextComponent.h"

TextComponent::TextComponent(float x, float y, float size, string content):
	x(x), y(y), size(size), content(content)
{
	br.fill_secondary_color[0] = 1.0f;
	br.fill_secondary_color[1] = 1.0f;
	br.fill_secondary_color[2] = 1.0f;
}

string TextComponent::getContent()
{
	return content;
}

void TextComponent::setContent(string content)
{
	this->content = content;
}

void TextComponent::setX(float x)
{
	this->x = x;
}

void TextComponent::setY(float y)
{
	this->y = y;
}

void TextComponent::draw()
{		
	graphics::drawText(x, y, size, content, br);
}

void TextComponent::update(float ms)
{
}
