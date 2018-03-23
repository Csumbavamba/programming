#include "GameObject.h"

int main()
{
	// Create a test object
	GameObject * object1 = new GameObject();
	GameObject * object2;
	GameObject * object3;

	// Try copying the gameObject
	// GameObject test1 = *object1; --> Does not work
	// object3 = object2;

	delete object1;
	object1 = 0;

	return 0;
}