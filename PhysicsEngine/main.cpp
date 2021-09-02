#include <iostream>

#include "vector.h"
#include "matrix.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	Vector<double> position(5.0, 5.0);
	Vector<double> direction(0.5, 0.5);
	Vector<double> offset(750, 500);
	Vector<double> multiplier(5.0);
	Vector<double> newPosition = (position + (direction * multiplier)) - offset;
	Vector<double> weights(5, 5, 10);
	Matrix<double> matrix = Matrix<double>(vector<vector<double>>{ 
		{1, 2, 3},
		{4, 5, 6}
	});
	Matrix<double> weightedMatrix = matrix * weights;
	Vector<double> solutionVector = weights * matrix;

	cout << "Position: " << position << endl;
	cout << "Direction: " << direction << endl;
	cout << "Multiplier: " << multiplier << endl << endl;

	cout << "New Position: " << newPosition << endl << endl;

	cout << "Matrix: \n" << matrix << endl;
	cout << "Weighted: \n" << weightedMatrix << endl;
	cout << "Solution: " << solutionVector << endl;

	return 0;
}