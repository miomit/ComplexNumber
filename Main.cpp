#include <iostream>
#include "Complex.hpp"
#include <math.h>

using namespace std;

int main()
{
	const double PI = 3.141592653589793238463;

	auto a = Complex(-1, sqrt(3));

	auto b = Complex::InitWithModuleAndArg(4, 7 * PI / 9);

	auto c = Complex::InitWithModuleAndArg(5, 4 * PI / 7);

	a = a ^ 4;
	b = b ^ 3;
	c = c ^ 4;

	auto numerator = a * b * ~c;
	auto denominator = (c * ~c).GetRe();

	for (int i = 0; i < 4; i++)
		cout << (numerator / denominator).GetRoot(4, i) << endl;


	return 0;
}