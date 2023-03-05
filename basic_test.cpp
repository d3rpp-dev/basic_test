#include "common.h"
#define NL std::endl << std::endl

constexpr auto PI = 3.14159;
constexpr auto PROMPT = " = ";

namespace take {
	std::string string(std::string query) {
		std::cout << query << PROMPT;
		std::string a;

		std::getline(std::cin, a);

		return a;
	}

	int number(std::string query) {
		std::cout << query << PROMPT;
		int i;

		std::cin >> i;

		return i;
	}

	float decimal(std::string query) {
		std::cout << query << PROMPT;
		float f;

		std::cin >> f;

		return f;
	}
}

namespace io_ops {
	void print_nums() {
		int
			f_num{ 17 },
			s_num{ 3 };

		std::cout << "First Number: " << f_num << std::endl << "Second Number: " << s_num << NL << "\x0a\x0d";
	}

	void print_name() {
		std::string
			s_a = take::string("fname"),
			s_b = take::string("lname");

		std::cout << "Hello, " << s_a << " " << s_b << NL;
	}

	void quadratic() {
		int
			i_a = take::number("a"),
			i_x = take::number("x"),
			i_b = take::number("b");

		std::cout << "ax + b = " << (i_a * i_x) + i_b << NL;
	}

	void area() {
		float
			f_radius = take::decimal("radius");

		std::cout << "pi * r^2 = " << PI * powf(f_radius, 2) << NL;
	}

	void compounding_interest() {
		float
			f_principle = take::decimal("Principle"),
			f_rate = take::decimal("Interest Rate"),
			f_t = take::decimal("Time (years)");

		std::cout << "P(1+rt) = " << f_principle * (1 + (f_rate * f_t)) << NL;
	}

	void graph_a_circle() {
		float
			f_x = take::decimal("x"),
			f_y = take::decimal("y");

		std::cout << "x^2 + y^2 = " << powf(f_x, 2) + powf(f_y, 2) << NL;
	}

	void test_numbers() {
		int a = 1, b = 2;

		ops::add(a, b);
		ops::sub(a, b);
		ops::mul(a, b);
		ops::div(a, b);

		float c = 3.12, d = 2.8;

		ops::add(c, d);
		ops::sub(c, d);
		ops::mul(c, d);
		ops::div(c, d);

		double e = 1.12, f = 2.342;

		ops::add(e, f);
		ops::sub(e, f);
		ops::mul(e, f);
		ops::div(e, f);
	}
}

namespace ops {
	template<typename T>
	T add(T lhs, T rhs) {
		return lhs + rhs;
	}

	template<typename T>
	T sub(T lhs, T rhs) {
		return lhs - rhs;
	}

	template<typename T>
	T mul(T lhs, T rhs) {
		return lhs * rhs;
	}

	template<typename T>
	T div(T lhs, T rhs) {
		return lhs / rhs;
	}
}

int main() {
	io_ops::test_numbers();
	io_ops::print_nums();
	io_ops::print_name();
	io_ops::quadratic();
	io_ops::area();
	io_ops::compounding_interest();
	io_ops::graph_a_circle();

	return 0;
}
