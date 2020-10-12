#include "Dot.h"

Dot::Dot(float x_in, float y_in)
{
	dot.setPosition(x_in, y_in);
	dot.setRadius(radius);
	dot.setOrigin(this->radius, this->radius);
}
