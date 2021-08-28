#include <iostream>

#include "vector.h"

using std::cout;
using std::endl;
using Math::Vector;

int main()
{
	Vector<double> position(5.0, 5.0);
	Vector<double> direction(0.5, 0.5);
	Vector<double> offset(750, 500);
	Vector<double> multiplier(5.0);
	Vector<double> newPosition = (position + (direction * multiplier)) - offset;

	cout << "Position: " << position << endl;
	cout << "Direction: " << direction << endl;
	cout << "Multiplier: " << multiplier << endl << endl;

	cout << "New Position: " << newPosition << endl;

	return 0;
}