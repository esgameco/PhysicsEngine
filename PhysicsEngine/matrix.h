#pragma once

#include <vector>
#include <string>
#include <stdexcept>

#include "vector.fwd.h"
#include "matrix.fwd.h"

using std::vector;

template <typename T>
struct Matrix
{
	// X rows, Y columns
	Matrix() {}
	Matrix(const int& x, const int& y) 
	{
		this->contents.resize(x, vector<T>(y, 0));
	}
	Matrix(const vector<vector<T>>& mat)
	{
		for (unsigned int i = 0; i < mat.size(); i++)
		{
			this->contents.push_back(vector<T>());
			for (unsigned int j = 0; j < mat[i].size(); j++)
			{
				this->contents[i].push_back(mat[i][j]);
			}
		}
	}

	Vector<T> getSolutionVector()
	{
		Vector<T> v;

		for (int i = 0; i < this->rows(); i++)
		{
			v.push_back(0);
			for (int j = 0; j < this->columns(); j++)
			{
				v[i] += this->get(i, j);
			}
		}

		return v;
	}

	Matrix operator*(const Vector<T>& other)
	{
		if (this->columns() != other.dimensions())
			throw std::invalid_argument("Weights' dimensions must match Matrix's columns");

		Matrix newMatrix = Matrix(this->rows(), this->columns());

		for (int i = 0; i < this->rows(); i++)
		{
			for (int j = 0; j < this->columns(); j++)
			{
				newMatrix.set(i, j, this->get(i, j) * other.get(j));
			}
		}

		return newMatrix;
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
	{
		for (int i = 0; i < matrix.rows(); i++)
		{
			for (int j = 0; j < matrix.columns(); j++)
			{
				os << matrix.get(i, j);
				if (j < matrix.columns() - 1)
					os << " ";
			}
			os << "\n";
		}

		return os;
	}

	int rows() const
	{
		return this->contents.size();
	}

	int columns() const
	{
		return this->contents[0].size();
	}

	const T& get(const int& x, const int& y) const
	{
		return this->contents.at(x).at(y);
	}

	void set(const int& x, const int& y, const int& val)
	{
		this->contents.at(x).at(y) = val;
	}

	vector<vector<T>> contents;
};