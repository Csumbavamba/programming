#include "Vector3.h"


// Default constructor, leaves vector at indeterminate state
Vector3::Vector3()
{
}

// Copy constructor
Vector3::Vector3(const Vector3& vector)
	: x(vector.x)
	, y(vector.y)
	, z(vector.z)
{
}

// Construct given 3 values
Vector3::Vector3(float x, float y, float z) 
	: x(x)
	, y(y)
	, z(z)
{
}

Vector3::~Vector3()
{
}

// Assignment operator, we adhere to C convention and return reference to the value
Vector3& Vector3::operator =(const Vector3& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;

	return (*this);
}

// Equality & Inequality operator
bool Vector3::operator ==(const Vector3& vector) const
{
	return (x == vector.x && y == vector.y && z == vector.z);
}

bool Vector3::operator !=(const Vector3& vector) const
{
	return (x != vector.x || y != vector.y || z != vector.z);
}

// Set the vector to Zero
void Vector3::Zero()
{
	x = 0;
	y = 0;
	z = 0;
}

// Unary minus returns the negative of the vector
Vector3 Vector3::operator -() const
{
	return (Vector3(-x, -y, -z));
}

// Binary +, add vectors
Vector3 Vector3::operator +(const Vector3& vector) const
{
	return (Vector3(x + vector.x, y + vector.y, z + vector.z));
}


// Binary -, subtract vectors
Vector3 Vector3::operator -(const Vector3& vector) const
{
	return (Vector3(x - vector.x, y - vector.y, z - vector.z));
}

// Multiply by scalar
Vector3 Vector3::operator *(float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

// Divide by scalar
Vector3 Vector3::operator/(float scalar) const
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3 & Vector3::operator+=(const Vector3 & vector)
{
	// TODO: insert return statement here
	x += vector.x;
	y += vector.y;
	z += vector.z;

	return (*this);
}

Vector3 & Vector3::operator-=(const Vector3 & vector)
{
	// TODO: insert return statement here
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;

	return (*this);
}

Vector3 & Vector3::operator*=(float number)
{
	// TODO: insert return statement here
	x *= number;
	y *= number;
	z *= number;

	return (*this);
}

Vector3 & Vector3::operator/=(float number)
{
	// TODO: insert return statement here
	x /= number;
	y /= number;
	z /= number;

	return (*this);
}

void Vector3::Normalize()
{
	float magnitudeSquare = x * x + y * y + z * z;

	if (magnitudeSquare > 0.0f)
	{
		float oneOverMagnitude = 1.0f / sqrt(magnitudeSquare);

		x *= oneOverMagnitude;
		y *= oneOverMagnitude;
		z *= oneOverMagnitude;
	}

}

// Vector Dot Product
float Vector3::operator*(const Vector3 & vector) const
{
	return (x * vector.x + y * vector.y + z * vector.z);
}


