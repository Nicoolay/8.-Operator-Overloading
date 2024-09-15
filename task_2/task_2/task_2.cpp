#include <iostream>
#include <windows.h>
class Fraction
{
private:
	double numerator_; // числитель
	double denominator_; // знаменатель
	int gcd(int a, int b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

public:
	// Метод для сокращения дроби
	void reduce() {
		int num = static_cast<int>(numerator_);
		int denom = static_cast<int>(denominator_);
		int divisor = gcd(std::abs(num), std::abs(denom));
		numerator_ /= divisor;
		denominator_ /= divisor;
	}
	
	
	Fraction(double numerator, double denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	void print() {
		std::cout << numerator_ <<"/" << denominator_;
	}
	Fraction operator + (Fraction other) {
		Fraction result((numerator_ * other.denominator_) + (other.numerator_ * denominator_), (denominator_ * other.denominator_));
		result.reduce(); 
		return result;
	}

	Fraction operator - (Fraction other) {
		Fraction result((numerator_ * other.denominator_) - (other.numerator_ * denominator_), (denominator_ * other.denominator_));
		result.reduce(); 
		return result;
	}

	Fraction operator * (Fraction other) {
		Fraction result((numerator_ * other.numerator_), (denominator_ * other.denominator_));
		result.reduce(); 
		return result;
	}

	Fraction operator / (Fraction other) {
		Fraction result((numerator_ * other.denominator_), (other.numerator_ * denominator_));
		result.reduce(); 
		return result;
	}
	
	
	Fraction& operator ++() {
		numerator_ += denominator_;  // Префиксный инкремент
		return *this;
	}

	// Постфиксный инкремент
	Fraction operator ++(int) {
		Fraction temp = *this;
		++(*this);  
		return temp;
	}

	// Префиксный декремент
	Fraction& operator --() {
		numerator_ -= denominator_;  
		return *this;
	}

	// Постфиксный декремент
	Fraction operator --(int) {
		Fraction temp = *this;
		--(*this);  
		return temp;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	double numerator_f1{}, numerator_f2{}, denominator_f1{}, denominator_f2{};

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator_f1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator_f1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator_f2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator_f2;

	Fraction f1(numerator_f1, denominator_f1);
	Fraction f2(numerator_f2, denominator_f2);

	Fraction sum = f1 + f2;
	f1.print();	std::cout << " + "; f2.print(); std::cout << " = "; sum.print(); std::cout << std::endl;
	Fraction minus = f1 - f2;
	f1.print();	std::cout << " - "; f2.print(); std::cout << " = "; minus.print(); std::cout << std::endl;
	Fraction mult = f1 * f2;
	f1.print();	std::cout << " * "; f2.print(); std::cout << " = "; mult.print(); std::cout << std::endl;
	Fraction div = f1 / f2;
	f1.print();	std::cout << " / "; f2.print(); std::cout << " = "; div.print(); std::cout << std::endl;
	++f1;
	std::cout << "++";  f1.print();	std::cout << " * "; f2.print(); std::cout << " = "; mult.print(); std::cout << std::endl;
	std::cout << "Значение дроби 1 = ";  f1.print(); std::cout << std::endl;
	f1--;
	f1.print(); std::cout << "--"; 	std::cout << " * "; f2.print(); std::cout << " = "; mult.print(); std::cout << std::endl;
	std::cout << "Значение дроби 1 = ";  f1.print(); std::cout << std::endl;
	
	return 0;
}