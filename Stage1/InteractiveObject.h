#pragma once

#include "Ripley.h"

#include "Bullet.h"

class InteractiveObject
{	
protected:
	//
	// Returns true if Ripley touches the rectangle: (width, height, x, y) 
	//
	virtual bool collides(Ripley* ripley, float width, float height, float x, float y);

	virtual bool collides(Bullet* ripley, float width, float height, float x, float y);
public:	
	//
	// Checks if collision and calls applyCollisionEvent()
	//
	virtual bool checkCollision(Ripley* ripley, float width, float height, float x, float y);

	//
	// Apply collision
	//
	virtual void applyCollisionEvent(Ripley* ripley) = 0;

    
	//
	// Checks if collision and calls applyCollisionEvent()
	//
	virtual bool checkCollision(Bullet* ripley, float width, float height, float x, float y);


};


