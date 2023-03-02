#include <iostream>
#include <string>
#include <cmath>

#define $nl std::endl << std::endl

const float PI = 3.141592;
const std::string PROMPT = " >> ";

namespace take {
	std::string string(std::string q) {
		std::cout << q << std::endl << PROMPT;
		std::string a;

		std::getline(std::cin, a);

		return a;
	}

	int number(std::string q) {
		std::cout << q << std::endl << PROMPT;
		int i;

		std::cin >> i;

		return i;
	}

	float decimal(std::string q) {
		std::cout << q << std::endl << PROMPT;
		float f;

		std::cin >> f;

		return f;
	}
}

int main() {
	std::string 
		s_a = take::string("fname"), 
		s_b = take::string("lname");

	std::cout << "Hello, " << s_a << " " << s_b << $nl;

	int 
		i_a = take::number("a"), 
		i_x = take::number("x"), 
		i_b = take::number("b");

	std::cout << "ax + b = " << (i_a * i_x) + i_b << $nl;

	float 
		f_radius = take::decimal("radius");

	std::cout << "pi * r^2 = " << PI * powf(f_radius, 2) << $nl;

	float 
		f_principle = take::decimal("Principle"), 
		f_rate = take::decimal("Interest Rate"), 
		f_t = take::decimal("Time (years)");

	std::cout << "P(1+rt) = " << f_principle * (1 + (f_rate * f_t)) << $nl;

	float 
		f_x = take::decimal("x"), 
		f_y = take::decimal("y");

	std::cout << "x^2 + y^2 = " << powf(f_x, 2) + powf(f_y, 2) << $nl;

	return 0;
}
