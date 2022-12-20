#include <iostream>
#include <math.h>
#include "Complex.hpp"

Complex::Complex() : Complex(0, 0)
{
}

Complex::Complex(double re) : Complex(re, 0)
{
}

Complex::Complex(double re, double im)
{
	this->Re = re;
	this->Im = im;
}

Complex Complex::InitWithModuleAndArg(double module, double arg)
{
	return Complex(
		cos(arg) * module,
		sin(arg) * module
	);
}

double Complex::GetRe()
{
	return this->Re;
}

double Complex::GetIm()
{
	return this->Im;
}

double Complex::GetModule()
{
	return sqrt(pow(GetRe(), 2) + pow(GetIm(), 2));
}

double Complex::GetArg()
{
	const double PI = 3.141592653589793238463;

	auto res = atan(GetIm() / GetRe());

	if (GetRe() < 0 && GetIm() > 0) res += PI;
	if (GetRe() < 0 && GetIm() < 0) res -= PI;

	if (GetRe() == 0 && GetIm() > 0) res = PI / 2;
	if (GetRe() == 0 && GetIm() < 0) res = 3 * PI / 2;

	return res;
}

Complex Complex::GetRoot(double degree, double k)
{
	const double PI = 3.141592653589793238463;

	const auto z = pow(GetModule(), 1 / degree);

	const auto f = (GetArg() + 2 * PI * k)/degree;

	return Complex::InitWithModuleAndArg(z, f);
}

Complex operator+(Complex a, Complex b)
{
	return Complex(
		a.GetRe() + b.GetRe(),
		a.GetIm() + b.GetIm()
	);
}

Complex operator-(Complex a, Complex b)
{
	return Complex(
		a.GetRe() - b.GetRe(),
		a.GetIm() - b.GetIm()
	);
}

Complex operator*(Complex a, Complex b)
{
	return Complex(
		a.GetRe()*b.GetRe() - a.GetIm()*b.GetIm(),
		a.GetRe()*b.GetIm() + a.GetIm()*b.GetRe()
	);
}

Complex operator~(Complex& a)
{
	return Complex(
		a.GetRe(),
		a.GetIm() * -1
	);
}

Complex operator*(double a, Complex b)
{
	return Complex(
		a * b.GetRe(),
		a * b.GetIm()
	);
}

Complex operator*(Complex a, double b)
{
	return b * a;
}

Complex operator/(Complex a, double b)
{
	return Complex(
		a.GetRe() / b,
		a.GetIm() / b
	);
}

Complex operator^(Complex a, double n)
{
	const auto z = pow(a.GetModule(), n);
	const auto f = a.GetArg();

	return Complex(
		z * cos(n * f),
		z * sin(n * f)
	);
}

std::ostream& operator<<(std::ostream& str, Complex a)
{
	if (a.GetRe() != 0) str << a.GetRe();
	if (a.GetIm() != 0) 
	{
		if (a.GetIm() > 0) str << '+';
		if (a.GetIm() != 1) str << a.GetIm();
		str << 'i';
	}
	return str;
}
