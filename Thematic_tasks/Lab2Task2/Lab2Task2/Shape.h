#pragma once


class Shape 
{
protected:
	int width;
	int height;

public:

	Shape(int width_in = 0, int height_in = 0);
	virtual int GetArea() = 0;

};



