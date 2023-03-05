#include "common.h"
#define NL std::endl << std::endl

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#define u8 char
#define u16 short unsigned int
#define u32 unsigned int
#define u64 unsigned long
#define u128 unsigned long long

#define i8 signed char
#define i16 short signed int
#define i32 signed int
#define i64 signed long
#define i128 signed long long

#define f32 float
#define f64 double

#define str std::string

constexpr auto PI = (float)3.14159;
constexpr auto PROMPT = " = ";

namespace take {
	str stri(str query) {
		std::cout << query << PROMPT;
		str a;

		std::getline(std::cin, a);

		return a;
	}

	int number(str query) {
		std::cout << query << PROMPT;
		int i;

		std::cin >> i;

		return i;
	}

	float decimal(str query) {
		std::cout << query << PROMPT;
		float f;

		std::cin >> f;

		return f;
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

	// just for the funny, I've copied the infamous q_rsqrt algorithm
	float q_rsqrt(float number)
	{
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y;							// evil floating point bit level hacking
		i = 0x5f3759df - (i >> 1);              // what the f*ck? 
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));    // 1st iteration
		//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

		return y;
	}
}

namespace fns {
	void print_nums() {
		i32
			f_num = 17,
			s_num = 3;

		std::cout << "First Number: " << f_num << std::endl << "Second Number: " << s_num << NL;
	}

	void bitshift_neg() {
		i32 a = -32;

		i32 b = a << 1;

		std::cout << "A: " << a << std::endl << "B: " << b << NL;
	}

	void random_garbage() {
		std::cout << "random garbage: ";
		for (i32 _i = 0; _i < 100; _i++) {
			i32 a = std::rand();

			std::cout << a << ", ";
		}
		std::cout << std::endl;
	}

	void print_name() {
		str
			s_a = take::stri("fname"),
			s_b = take::stri("lname");

		std::cout << "Hello, " << s_a << " " << s_b << NL;
	}

	void quadratic() {
		i32
			i_a = take::number("a"),
			i_x = take::number("x"),
			i_b = take::number("b");

		std::cout << "ax + b = " <<  ops::add(ops::mul(i_a, i_x), i_b) << NL;
	}

	void area() {
		f32
			f_radius = take::decimal("radius");

		std::cout << "pi * r^2 = " << ops::mul(PI, powf(f_radius, 2)) << NL;
	}

	void compounding_interest() {
		f32
			f_principle = take::decimal("Principle"),
			f_rate = take::decimal("Interest Rate"),
			f_t = take::decimal("Time (years)");

		std::cout << "P(1+rt) = " << ops::mul(f_principle, ops::add(1.0f, ops::mul(f_rate, f_t))) << NL;
	}

	void graph_a_circle() {
		f32
			f_x = take::decimal("x"),
			f_y = take::decimal("y");

		std::cout << "x^2 + y^2 = " << ops::add(powf(f_x, 2), powf(f_y, 2)) << NL;
	}

	void test_numbers() {
		i32 a = 1, b = 2;

		ops::add(a, b);
		ops::sub(a, b);
		ops::mul(a, b);
		ops::div(a, b);

		f32 c = (float)3.12, d = (float)2.8;

		ops::add(c, d);
		ops::sub(c, d);
		ops::mul(c, d);
		ops::div(c, d);

		f64 e = 1.12, f = 2.342;

		ops::add(e, f);
		ops::sub(e, f);
		ops::mul(e, f);
		ops::div(e, f);
	}
}

int main() {
	fns::test_numbers();
	fns::bitshift_neg();
	fns::random_garbage();
	// fns::print_nums();
	// fns::print_name();
	// fns::quadratic();
	// fns::area();
	// fns::compounding_interest();
	// fns::graph_a_circle();

	return 0;
}
