#pragma once

#include "MyShape.h"
#include <vector>

using namespace std;

class Cache
{
public:
	Cache(vector<MyShape*> &shapes,MyShape *shape)
		: shapes(shapes), shape(shape) {}
	
	//for undo
	void undo() { shapes.push_back(shape); }

	//for redo
	void redo() {
		vector<MyShape*>::iterator it;// use stl
		for (it = shapes.begin(); it != shapes.end(); ++it)
			if (*it == shape)
				break;
		if (it != shapes.end())
			shapes.erase(it);
	}
private:
	vector<MyShape*> &shapes;
	MyShape *shape;
};