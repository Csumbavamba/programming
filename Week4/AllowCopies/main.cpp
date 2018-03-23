#include "GameObject.h"

int main()
{
	GameObject * object1 = new GameObject();
	GameObject object2;
	GameObject object3;

	// Try copying object
	GameObject& test = object1->Clone();

	// Destroy the test object
	delete object1;
	object1 = 0;

	delete &test;

	return 0;
}