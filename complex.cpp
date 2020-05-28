/*
Author: Md Abul Kashem
This program can add, substruct, multiply and compare two complex numbers.

*/
#include"complex.h"
complex_class::complex_class() {
		real = 0.0;
	 imaginary = 0.0;
}
complex_class::complex_class(double r, double im) {
	real = r;
	this->imaginary = im;  

}

complex_class::~complex_class() {

}
double complex_class::getReal()const {
	return real;
}
double complex_class::getImaginary()const {
	return imaginary;

}

void complex_class::setReal(double r) {
	real = r;
}
void complex_class::setImaginary(double im) {
	imaginary = im;
}

bool complex_class::operator==(const complex_class& rhs)const {

	return this->getReal() == rhs.real && this->getImaginary() == rhs.imaginary;
};

bool complex_class::operator!=(const complex_class& rhs)const {	
	return !(*this==rhs);
};

complex_class operator+(const complex_class &lhs, const complex_class &rhs)
{
	complex_class sum;
	double r = lhs.getReal() + rhs.getReal();
	double imag = lhs.getImaginary() + rhs.getImaginary();
	sum = complex_class(r, imag);
	return sum;
}

complex_class operator-(const complex_class &lhs, const complex_class &rhs)
{
	complex_class sub;
	double r = lhs.getReal() - rhs.getReal();
	double imag = lhs.getImaginary() - rhs.getImaginary();
	sub = complex_class(r, imag);
	return sub;
}

complex_class operator*(const complex_class &lhs, const complex_class &rhs)
{
	complex_class mul;  //(a+bi)(c+di)=(ac-bd)+(bc+ad)i.\ 
	mul = complex_class((lhs.getReal() * rhs.getReal() - lhs.getImaginary()*rhs.getImaginary()), (lhs.getImaginary()*rhs.getReal() + lhs.getReal()* rhs.getImaginary()));
	return mul;
}


istream &operator>>(istream& in, complex_class& complex) {
	double real, imag;
	in >> real >> imag;
	//complex = complex_class(real, imag);
	complex.setReal(real);
	complex.setImaginary(imag);
	return in;
};

ostream &operator<<(ostream &output, const complex_class& c) {
	if (c.getImaginary() > 0) {
		output << c.getReal() << " + " << c.getImaginary() << "i" << endl;
	}
	else
		output << c.getReal() << " " << c.getImaginary() << "i" << endl;
	 
	 return output;
};

