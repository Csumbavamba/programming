#pragma once

#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include <cmath>
#include <math.h>


class Vector3
{
public:
	
	float x;
	float y;
	float z;

	Vector3();
	Vector3(const Vector3& vector); // Copy constructor
	Vector3(float x, float y, float z);
	~Vector3();

	// Assignment Operator
	Vector3& operator =(const Vector3& vector); // Overload = -> if not defined this will disallow copy

	// Relational operators
	bool operator ==(const Vector3& vector) const;
	bool operator !=(const Vector3& vector) const;

	// Vector operations
	void Zero();

	Vector3 operator -() const; // negate
	Vector3 operator +(const Vector3& vector) const;
	Vector3 operator -(const Vector3& vector) const;

	// Multiplication and division by scalar
	Vector3 operator *(float scalar) const;
	Vector3 operator /(float scalar) const;

	// Combined assignment operators to conform to C notation convention
	Vector3& operator +=(const Vector3& vector);
	Vector3& operator -=(const Vector3& vector);
	Vector3& operator *=(float number);
	Vector3& operator /=(float number);

	// Normalize the vector
	void Normalize();

	// Vector Dot product
	// We overload the standard multiplication symbol to do this
	float operator *(const Vector3& vector) const;

	// Static member functions
	// Magnitude of vector
	static inline float Magnitude(const Vector3& vector)
	{
		return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
	}

	// Cross product of 2 vectors
	static inline Vector3 CrossProduct(const Vector3& vectorA, const Vector3& vectorB)
	{
		return
			(
				Vector3(vectorA.y * vectorB.z - vectorA.z * vectorB.y, 
						vectorA.z * vectorB.x - vectorA.x * vectorB.z,
						vectorA.x * vectorB.y - vectorA.y * vectorB.x)
			);
	}

	// Distance between 2 vectors
	static inline float Distance(const Vector3& vectorA, const Vector3& vectorB)
	{
		float distanceX = vectorA.x - vectorB.x;
		float distanceY = vectorA.y - vectorB.y;
		float distanceZ = vectorA.z - vectorB.z;

		return (sqrt(distanceX * distanceX + distanceY * distanceY + distanceZ * distanceZ));
	}

	// Scalar on the left multiplication, for symmetry
	inline Vector3 operator *(float scalar, const Vector3& vector)
	{
		return (Vector3(scalar * vector.x, scalar * vector.y, scalar * vector.z));
	}

	
};

#endif // !1