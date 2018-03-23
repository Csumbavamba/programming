#include "Vector3.h"

int main()
{
	// Vector test

	// Create 2 vectors
	Vector3 a(1.0f, 2.0f, 3.0f);
	Vector3 b(1.0f, 2.0f, 3.0f);

	Vector3 c;
	
	// Zero Vector
	c.Zero();

	// ADdition
	Vector3 d = a + b;

	// Subtraction.
	Vector3 e = a - b;

	//Scalar Multiplication.
	Vector3 f1 = a * 10;
	//Scalar Multiplication. --> This DOES NOT WORK
	//Vector3 f2 = 10 * a;
	//Scalar Division.
	Vector3 g = a / 10;
	// Unary minus.
	Vector3 h = -a;

	// Relational Operators.
	bool AEqualsB = (a == b);
	bool ANotEqaulsB = (a != b);

	// Combined operations +=.
	c = a;
	c += a;
	// Combined operations -=.
	c = a;
	c -= a;
	// Combined operations /=.
	c = a;
	c /= 10;
	// Combined operations *=.
	c = a;
	c *= 10;

	// Normalisation.
	c.Normalize();
	// Dot Product.
	float ADotB = a * b;

	// Magnitude.
	float magnitude1 = Vector3::Magnitude(a);
	float magnitude2 = Vector3::Magnitude(c);
	// Cross product.
	Vector3 crossProduct = Vector3::CrossProduct(a, c);
	// Distance.
	float distance = Vector3::Distance(a, c);

	return (0);



}