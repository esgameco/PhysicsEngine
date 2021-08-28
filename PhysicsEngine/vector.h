#pragma once

#include <vector>
#include <string>
#include <stdexcept>

enum
{
	x,
	y,
	z
};

namespace Math
{
template <typename T>
struct Vector
{
	// Constructors
	// Empty
	Vector()
	{
		this->contents.reserve(3);
	}
	// 1 Dimensional
	Vector(const T& xVal)
	{
		this->contents.push_back(xVal);
	}
	// 2 Dimensional
	Vector(const T& xVal, const T& yVal)
	{
		this->contents.push_back(xVal);
		this->contents.push_back(yVal);
	}
	// 3 Dimensional
	Vector(const T& xVal, const T& yVal, const T& zVal)
	{
		this->contents.push_back(xVal);
		this->contents.push_back(yVal);
		this->contents.push_back(zVal);
	}
	// Any Dimensional
	Vector(const std::vector<T>& vals)
	{
		for (const T& val : vals)
			this->contents.push_back(val);
	}

	Vector operator+(const Vector& other)
	{
		Vector newVector;
		// Vector Addition
		if (this->dimensions() == other.dimensions())
			for (int i = 0; i < this->dimensions(); i++)
				newVector.contents.push_back(this->get(i) + other.get(i));
		// Scalar Addition
		else if (this->dimensions() == 1)
			for (int i = 0; i < other.dimensions(); i++)
				newVector.contents.push_back(this->get(x) + other.get(i));
		else if (other.dimensions() == 1)
			for (int i = 0; i < this->dimensions(); i++)
				newVector.contents.push_back(this->get(i) + other.get(x));
		// No Addition
		else
			throw std::invalid_argument("Arguments don't make sense");
		return newVector;
	}

	Vector operator-(const Vector& other)
	{
		Vector newVector;
		// Vector Subtraction
		if (this->dimensions() == other.dimensions())
			for (int i = 0; i < this->dimensions(); i++)
				newVector.contents.push_back(this->get(i) - other.get(i));
		// Scalar Subtraction
		else if (this->dimensions() == 1)
			for (int i = 0; i < other.dimensions(); i++)
				newVector.contents.push_back(this->get(x) - other.get(i));
		else if (other.dimensions() == 1)
			for (int i = 0; i < this->dimensions(); i++)
				newVector.contents.push_back(this->get(i) - other.get(x));
		// No Subtraction
		else
			throw std::invalid_argument("Arguments don't make sense");
		return newVector;
	}

	Vector operator*(const Vector& other)
	{
		Vector newVector;
		// Vector Product
		if (this->dimensions() == other.dimensions())
			for (int i = 0; i < this->dimensions(); i++)
				// Change this to work as a vector product
				newVector.contents.push_back(this->get(i) * other.get(i));
		// Dot Product
		else if (this->dimensions() == 1)
			for (int i = 0; i < other.dimensions(); i++)
				newVector.contents.push_back(this->get(x) * other.get(i));
		else if (other.dimensions() == 1)
			for (int i = 0; i < this->dimensions(); i++)
				newVector.contents.push_back(this->get(i) * other.get(x));
		// No Multiplication
		else
			throw std::invalid_argument("Arguments don't make sense");
		return newVector;
	}

	// TODO: Check whether namespace around friend is necessary
	friend std::ostream& operator<<(std::ostream& os, const Vector& vector)
	{
		for (int i = 0; i < vector.dimensions(); i++)
		{
			os << vector.get(i);
			if (i < vector.dimensions() - 1)
				os << ", ";
		}
		return os;
	}

	int dimensions() const
	{
		return this->contents.size();
	}

	void set(const int& axis, const T& value)
	{
		this->contents.at(axis) = value;
	}

	const T& get(const int& axis) const
	{
		return this->contents.at(axis);
	}

	std::vector<T> contents;
};
}