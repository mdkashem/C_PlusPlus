/*
Author: Md Abul Kashem
This program can add, substruct, multiply and compare two complex numbers.

*/
#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include<string>
using namespace std;
class complex_class
{
public:
	//contractors
	complex_class(); //default
	complex_class(double , double );

	//destructor
	~complex_class();
	
	
	//accessors functions
	double getReal() const;
	double getImaginary() const;
	//
	void setReal(double);
	void setImaginary(double);
	//complex_class operator+(const complex_class , const complex_class);
	//overload member functions
	bool operator==(const complex_class& rhs)const;
	bool operator!=(const complex_class& rhs) const;


private:
	double	real = 0.0;
	double imaginary =0.0;

};

istream &operator>>(istream& in, complex_class& complex);
ostream &operator<<(ostream &output, const complex_class& c);
complex_class operator+(const complex_class &lhs, const complex_class &rhs);
complex_class operator-(const complex_class &lhs, const complex_class &rhs);
complex_class operator*(const complex_class &lhs, const complex_class &rhs);


#endif // !1

