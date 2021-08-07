#include"Polynomial.h"

Polynomial::Polynomial()
{
				coeffitients.push_back(0);
}

Polynomial::Polynomial(double* param, int size)
{
				for (int i=0;i<size;i++ )
				{
								coeffitients.push_back(param[i]);
				}
}

Polynomial::Polynomial(const Polynomial& poly)
{
				coeffitients.clear();
				for (int i = 0; i < poly.coeffitients.size(); i++)
				{
								this->coeffitients.push_back(poly.coeffitients[i]);
				}
}

Polynomial::~Polynomial()
{
				//coeffitients.clear();
}


int Polynomial::mySize()
{
				return coeffitients.size();
}


Polynomial& Polynomial::operator = (const Polynomial& poly)
{
				this->coeffitients =poly.coeffitients;
				return *this;
}

const Polynomial Polynomial::operator + (const Polynomial& poly)
{
				Polynomial temp1 = *this;
				Polynomial temp2 = poly;
				int size1 = temp1.coeffitients.size();
				int size2 = temp2.coeffitients.size();

				if (size1 > size2)
				{
								for (int i = size2; i < size1; i++)
								{
												temp2.coeffitients.push_back(0);
								}
				}
				else if (size1 < size2)
				{
								for (int i = size1; i < size2; i++)
								{
												temp1.coeffitients.push_back(0);
								}
				}
				for (int i = 0; i < max(size1,size2); i++)
				{
								temp1.coeffitients[i] += temp2.coeffitients[i];
				}
				//*this = temp1;
				return temp1;
}

const Polynomial Polynomial::operator - (const Polynomial& poly)
{
				Polynomial temp=poly;

				for (int i = 0; i < poly.coeffitients.size(); i++)
				{
								temp.coeffitients[i] *= -1;
				}
				temp = *this+temp;
				return temp;
}

const Polynomial Polynomial::operator * (const Polynomial& poly)
{
				Polynomial temp ;

				size_t size1 = coeffitients.size();
				size_t size2 = poly.coeffitients.size();

				temp.coeffitients.resize(size1 + size2 -1);
				for (size_t i = 0; i < size1; i++)
				{
								for (size_t j = 0; j < size2; j++)
								{
												temp.coeffitients[i + j] += coeffitients[i] * poly.coeffitients[j];
								}
				}
				return temp;
}

double& Polynomial::operator[](int pos)
{
				if (pos >= coeffitients.size())
				{
								cout << "Index Out Of Range!" << endl;
								return coeffitients[0];
				}
				else
				{
								return coeffitients[pos];
				}
}

double evaluate(const Polynomial& poly, const double& var)
{
				double temp = 0;
				for (int i = 0; i < poly.coeffitients.size(); i++)
				{
								temp += poly.coeffitients[i]*pow(var, i);
				}
				return temp;
}

Polynomial operator + (const Polynomial& poly, const double& d)
{
				Polynomial temp=poly;
				temp[0] += d;
				return temp;
}

Polynomial operator - (const Polynomial& poly, const double& d)
{
				Polynomial temp = poly;
				temp[0] -= d;
				return temp;
}

Polynomial operator * (const Polynomial& poly, const double& d)
{
				Polynomial temp=poly;
				for (int i = 0; i < temp.mySize(); i++)
				{
								temp[i] *= d;
				}
				return temp;
}

Polynomial operator + (const double& d, const Polynomial& poly)
{
				Polynomial temp=poly;
				temp[0] += d;
				return temp;
}

Polynomial operator - (const double& d, const Polynomial& poly)
{
				Polynomial temp=poly;
				temp = temp * -1;
				temp[0] += d;
				return temp;
}

Polynomial operator * (const double& d, const Polynomial& poly)
{
				Polynomial temp=poly;
				temp = temp * d;
				return temp;
}

ostream& operator<<(ostream& ostr, const Polynomial& poly)
{
				for (int i = 0; i < poly.coeffitients.size(); i++)
				{
								cout << poly.coeffitients[i] ;
								if (i != poly.coeffitients.size() - 1)
												cout << ",";
								else
												cout << "\t";
				}
				return ostr;
}
