#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#pragma once
using namespace std;

class Polynomial
{
public:
				Polynomial(); // construct a zero Polynomial
				Polynomial(double* param, int size); // construct a "size" length based on param 
				Polynomial(const Polynomial& poly); // copy constructor
				~Polynomial();

				int mySize(); // output number of terms

				Polynomial& operator = (const Polynomial& poly);
				const Polynomial operator + (const Polynomial& poly);
				const Polynomial operator - (const Polynomial& poly);
				const Polynomial operator * (const Polynomial& poly);
				double& operator [] (int pos);
				
				friend ostream& operator<<(ostream& ostr,const Polynomial& poly);

				friend Polynomial operator + (const Polynomial& poly, const double& d);
				friend Polynomial operator - (const Polynomial& poly, const double& d);
				friend Polynomial operator * (const Polynomial& poly, const double& d);

				friend Polynomial operator + (const double& d, const Polynomial& poly);
				friend Polynomial operator - (const double& d, const Polynomial& poly);
				friend Polynomial operator * (const double& d, const Polynomial& poly);

				friend double evaluate(const Polynomial& poly, const double& var); // 回傳多項式帶入var後的值
private:
				vector<double> coeffitients;
};

