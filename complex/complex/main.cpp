#include <iostream>


class ComplexN
{
private:
	int re;
	int im;
public:
	ComplexN()
	{
		this->im = 0;
		this->re = 0;
	}
	ComplexN(int re, int im)
	{
		this->re = re;
		this->im = im;
	}
	void Print()
	{
		std::cout << "(" << this->re << ", " << this->im << ")" << std::endl;
	}
	ComplexN operator+(ComplexN m)
	{
		return ComplexN(this->re + m.re, this->im + m.im);
	}
	ComplexN operator-(ComplexN m)
	{
		return ComplexN(this->re - m.re, this->im - m.im);
	}
	ComplexN operator*(ComplexN m)
	{
		return ComplexN(this->re * m.re - this->im * m.im, this->re * m.im + this->im * m.re);
	}
	bool operator>(ComplexN m)
	{
		if (this->re > m.re) 
			return true;
		else 
			return false;
	}

};

int main()
{
	ComplexN n = ComplexN(15, 20);
	ComplexN m = ComplexN(30, 10);
	std::cout << "n = ";
	n.Print();
	std::cout << "m = ";
	m.Print();

	ComplexN res = n + m;
	std::cout << "n + m = ";
	res.Print();

	res = n - m;
	std::cout << "n - m = ";
	res.Print();

	res = n * m;
	std::cout << "n * m = ";
	res.Print();

	bool isBigger = (res > m);
	std::cout << "res > m = ";
	std::cout << isBigger << std::endl;
	return 0;
}