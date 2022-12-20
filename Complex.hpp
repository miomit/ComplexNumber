class Complex
{
public:
	Complex();
	Complex(double re);
	Complex(double re, double im);

	static Complex InitWithModuleAndArg(double module, double arg);

	double GetRe();
	double GetIm();

	double GetModule();
	double GetArg();

	Complex GetRoot(double degree, double k);

	friend Complex operator+(Complex a, Complex b);
	friend Complex operator-(Complex a, Complex b);

	friend Complex operator*(Complex a, Complex b);

	friend Complex operator~(Complex& a);

	friend Complex operator*(double a, Complex b);
	friend Complex operator*(Complex a, double b);

	friend Complex operator/(Complex a, double b);

	friend Complex operator^(Complex a, double n);

	friend std::ostream& operator<<(std::ostream& Str, Complex v);

private:
	double Re, Im;
};