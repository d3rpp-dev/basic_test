#include "common.h"
#define NL std::endl << std::endl

constexpr auto PI = (float)3.1415926536;
constexpr auto PROMPT = "\n > ";

namespace take {
	str text(str query) {
		std::cout << GREEN << query << RESET << PROMPT;
		str a;

		std::cin.clear();
		fflush(stdin);
		std::getline(std::cin, a);

		return a;
	}

	str word(str query) {
		std::cout << RED << query << RESET << PROMPT;
		str a;

		std::cin.clear();
		fflush(stdin);
		std::cin >> a;
		std::cin.clear();
		fflush(stdin);

		return a;
	}

	template<typename T>
	T number(str query) {
		std::cout << BLUE << query << RESET << PROMPT;
		T f{};

		fflush(stdin);
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
}

namespace fns {
	void print_nums() {
		i32
			f_num = 17,
			s_num = 3;

		std::cout << "First Number" << f_num << std::endl << "Second Number" << s_num << NL;
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
			s_a = take::text("fname"),
			s_b = take::text("lname");

		std::cout << "Hello, " << s_a << " " << s_b << NL;
	}

	void quadratic() {
		i32
			i_a = take::number<i32>("a"),
			i_x = take::number<i32>("x"),
			i_b = take::number<i32>("b");

		std::cout << "ax + b = " <<  ops::add(ops::mul(i_a, i_x), i_b) << NL;
	}

	void area() {
		f32
			f_radius = take::number<f32>("radius");

		std::cout << "pi * r^2 = " << ops::mul(PI, powf(f_radius, 2)) << NL;
	}

	void compounding_interest() {
		f32
			f_principle = take::number<f32>("Principle"),
			f_rate = take::number<f32>("Interest Rate"),
			f_t = take::number<f32>("Time (years)");

		std::cout << "P(1+rt) = " << ops::mul(f_principle, ops::add(1.0f, ops::mul(f_rate, f_t))) << NL;
	}

	void graph_a_circle() {
		f32
			f_x = take::number<f32>("x"),
			f_y = take::number<f32>("y");

		std::cout << "x^2 + y^2 = " << ops::add(powf(f_x, 2), powf(f_y, 2)) << NL;
	}

	void test_numbers() {
		i32 a = 1, b = 2;

		i32 i_add = ops::add(a, b);
		i32 i_sub = ops::sub(a, b);
		i32 i_mul = ops::mul(a, b);
		i32 i_div = ops::div(a, b);

		f32 c = (float)3.12, d = (float)2.8;

		f32 f_add = ops::add(c, d);
		f32 f_sub = ops::sub(c, d);
		f32 f_mul = ops::mul(c, d);
		f32 f_div = ops::div(c, d);


		f64 e = 1.12, f = 2.342;

		f64 d_add = ops::add(e, f);
		f64 d_sub = ops::sub(e, f);
		f64 d_mul = ops::mul(e, f);
		f64 d_div = ops::div(e, f);

		f128 g = 1.12, h = 2.342;

		f128 l_add = ops::add(g, h);
		f128 l_sub = ops::sub(g, h);
		f128 l_mul = ops::mul(g, h);
		f128 l_div = ops::div(g, h);

		str s;
		std::cout << " >> ";
		std::getline(std::cin, s);

		std::cout << "not runtime erros from templates" << NL;
	}

	void size_of_vars() {
		std::cout
			<< "i8:   " << sizeof(i8)   << std::endl
			<< "i16:  " << sizeof(i16)  << std::endl
			<< "i32:  " << sizeof(i32)  << std::endl
			<< "i64:  " << sizeof(i64)  << std::endl
			<< "f32:  " << sizeof(f32)  << std::endl
			<< "f64:  " << sizeof(f64)  << std::endl
			<< "f128: " << sizeof(f128) << std::endl;
	}

	void floating_point() {
		f32  flt = 1.2132321323124324321432456523653241356432156234f;
		f64  dbl = 1.2132321323124324321432456523653241356432156234;
		f128 ldb = 1.2132321323124324321432456523653241356432156234L;

		f64 dsa = 1.342435325536245635214e16;
		f64 bru = 3.498e-12;

		f64 a = 5.6, b = 0.0;

		f64 c = a / b;

		std::cout << std::setprecision(20);
		std::cout << "bse: 1.2132321323124324321432456523653241356432156234\n";
		std::cout << "flt: " << flt << "\n";
		std::cout << "dbl: " << dbl << "\n";
		std::cout << "ldb: " << ldb << "\n";
		std::cout << "dsa: " << dsa << "\n";
		std::cout << "bru: " << bru << "\n";
		std::cout << "c  : " << c << "\n";
	}

	void conditional_programming_is_incredibly_easy() {
		bool a = true, b = false;

		if (a) {
			std::cout << "a == true" << NL;
		}
		else {
			std::cout << "a == false" << NL;
		}
	}
}

namespace more_fns {
	void multiple_choice() {
		bool should_exit = false;

		do {
			f64 input_one = 0.0, input_two = 0.0, output = 0.0;

			char op = '\x00';
			bool input_valid = false;

			do {
				str operand = take::word("Operand (or e to exit) [+-*/e]");

				// trim whitespace from string
				trim(operand);

				if (operand.length() < 1) { 
					std::cout << std::endl;
					continue; 
				}

				if (operand[0] == '+' || operand[0] == '-' || operand[0] == '*' || operand[0] == '/' || operand[0] == 'e') {
					op = operand[0];
					input_valid = true;
				}
			// operand check
			} while (!input_valid);

			if (op == 'e') {
				// user has chosen to exit
				should_exit = true;
				continue;
			}

			input_one = take::number<f64>("Left Hand Side");
			input_two = take::number<f64>("Right Hand Side");

			// we use numbers because why tf not

			std::cout << std::endl;

			if (op == 43) {
				std::cout 
					<< GREEN << input_one << RESET 
					<< " + " 
					<< GREEN << input_two << RESET 
					<< " = " 
					<< CYAN << ops::add(input_one, input_two) << RESET 
					<< NL;
			} 
			else if (op == 42) {
				std::cout << GREEN << input_one << RESET << " × " << GREEN << input_two << RESET << " = " << CYAN << ops::mul(input_one, input_two) << RESET << NL;
			}
			else if (op == 45) {
				std::cout << GREEN << input_one << RESET << " - " << GREEN << input_two << RESET << " = " << CYAN << ops::sub(input_one, input_two) << RESET << NL;
			}
			else if (op == 47) {
				std::cout << GREEN << input_one << RESET << " / " << GREEN << input_two << RESET << " = " << CYAN << ops::div(input_one, input_two) << RESET << NL;
			}

		// main loop
		} while (!should_exit);
	}

	void profit_counter() {
		i32 income, cost;

		income = take::number<i32>("Income");
		cost   = take::number<i32>("Cost");

		i32 profit_or_loss = income - cost;

		if (profit_or_loss > 0) {
			std::cout << "Profit: $" << profit_or_loss << NL;
		}
		else if (profit_or_loss == 0) {
			std::cout << "Broke Even, no profit or loss." << NL;
		}
		else {
			std::cout << "Loss: $" << profit_or_loss << NL;
		}
	}

	void calculate_endianess() {
		i32 n = 1;

		// borrowed from https://stackoverflow.com/a/4181991
		//
		// cast a reference to an 32-bit integer to a 
		// character pointer which will take the first 
		// byte and represent it as a char.
		// 
		// in a 32-bit integer in little-endian, the 
		// first byte will contain the first bytes, 
		// so if our value (1) can be found here, the 
		// system is little-endian, otherwise it is 
		// big-endian.
		//
		// it's worth noting that the other 3 bytes are 
		// leaked, so don't do this in a loop or you'll 
		// have a memory leak.
		if (*(char*)&n == 1) {
			std::cout << "Little Endian" << NL;
		}
		else {
			std::cout << "Big Endian" << NL;
		}
	}

	void print_base() {
		const i16 data = 0xdead;

		std::cout << "data[dec]: " << std::showbase << std::dec << data << std::endl;
		std::cout << "data[hex]: " << std::showbase << std::hex << data << std::endl;
		std::cout << "data[oct]: " << std::showbase << std::oct << data << std::endl;
		std::cout << "data[bin]: " << std::bitset<16>(data) << std::endl;
	}

	void bit_tinkering() {
		u8 a = 0b0101010101;
		u8 b = 0b1001001001;

		std::cout << std::bitset<8>(a) << std::endl << std::bitset<8>(b) << " &" << std::endl << "--------" << std::endl << std::bitset<8>(a & b) << NL;


		std::cout << std::bitset<8>(a) << std::endl << std::bitset<8>(b) << " |" << std::endl << "--------" << std::endl << std::bitset<8>(a | b) << NL;
	}

	void internal_task() {
		i32 num = take::number<i32>("Number");

		// optimised
		if (num > 0) {
			std::cout << "Positive" << NL;
		}
		else if (num < 0) {
			std::cout << "Negative" << NL;
		}
		else {
			std::cout << "Zero" << NL;
		}
	}
}

namespace even_more_fns {
	void divisible() {
		i32 num = take::number<i32>("Number");

		bool by_three = num % 3 == 0;
		bool by_five = num % 5 == 0;

		if (by_five && by_three) {
			std::cout << "Divisible by 3 & 5" << NL;
		} else {
			if (by_five) {
				std::cout << "Divisible by 5" << NL;
			}
			else if (by_three) {
				std::cout << "Divisible by 3" << NL;
			}
			else {
				std::cout << "Divisible by neither 3 or 5" << NL;
			}
		}
	}

	void bitwise_ops() {
		i16 a = take::number<i16>("First Number"),
			b = take::number<i16>("Second Number");

		std::cout <<
			"| " << std::bitset<16>(a) << " | 0x" << std::hex << a << std::endl <<
			"| " << std::bitset<16>(b) << " | 0x" << std::hex << b << std::endl <<
			"|-" << "----------------" << "-| &" << std::endl <<
			"| " << std::bitset<16>(a & b) << " |" << NL;

		std::cout <<
			"| " << std::bitset<16>(a) << " | 0x" << std::hex << a << std::endl <<
			"| " << std::bitset<16>(b) << " | 0x" << std::hex << b << std::endl <<
			"|_" << "----------------" << "_| |" << std::endl <<
			"| " << std::bitset<16>(a | b) << " |" << NL;

		std::cout <<
			"| " << std::bitset<16>(a) << " | 0x" << std::hex << a << std::endl <<
			"| " << std::bitset<16>(b) << " | 0x" << std::hex << b << std::endl <<
			"|-" << "----------------" << "-| ^" << std::endl <<
			"| " << std::bitset<16>(a ^ b) << " |" << NL;

		std::cout << std::bitset<16>(a) << " << " << 2 << " = " << std::bitset<16>(a << 2) << NL;

		std::cout << std::bitset<16>(a) << " >> " << 2 << " = " << std::bitset<16>(a >> 2) << NL;
	}

	void spite() {
		bool
			red = false,
			amber = false,
			green = true,
			cops = true;

		if (red || cops) {
			std::cout << "Stop" << NL;
		}
		else if (amber) {
			std::cout << "Slow Down" << NL;
		}
		else if (green) {
			std::cout << "GO" << NL;
		}
		else {
			// this should never occur bit it is an edge case where the lights are not red, amber, or green, & there is no police stop
			//
			// assume the traffic lights have crashed and are in "well f*ck" mode.
			exit(1234);
		}
	}

	void switch_my_existence() {
		const char* months[12] = {
			"January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"July",
			"August",
			"September",
			"November",
			"December"
		};

		bool should_exit = false;

		do {
			i32 month = take::number<i32>("Month [1-12]");

			/* 
			switch (month) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
				std::cout << month << " corresponds to " << months[month - 1] << NL;
				should_exit = true;
				break;
			default:
				std::cout << "Invalid Month, please try again." << NL;
			}
			*/

			if (month > 0 && month <= 12) {
				std::cout << month << " corresponds to " << months[month - 1] << NL;
				should_exit = true;
			} else {
				std::cout << "Invalid Month, please try again." << NL;
			}
			
		} while (!should_exit);
	}
}

int main() {
	// fns::floating_point();
	// fns::conditional_programming_is_incredibly_easy();
	// fns::bitshift_neg();
	// fns::size_of_vars();
	// fns::test_numbers();
	// fns::random_garbage();
	// fns::print_nums();
	// fns::print_name();
	// fns::quadratic();
	// fns::area();
	// fns::compounding_interest();
	// fns::graph_a_circle();

	// more_fns::multiple_choice();
	// more_fns::profit_counter();
	// more_fns::calculate_endianess();
	// more_fns::print_base();
	// more_fns::bit_tinkering();
	// more_fns::internal_task();

	// even_more_fns::bitwise_ops();
	even_more_fns::switch_my_existence();

	return 0;
}
