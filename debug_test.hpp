#ifndef DEBUG_TEST_HPP
# define DEBUG_TEST_HPP

#include "srcs/vector/vector.hpp"
#include <vector>

class test {
	public:
	test() {};
	~test() { std::cout << "DESTROYED" << std::endl; };
};

void header_test_section(std::string title)
{
	std:: cout << std::endl;
	std::cout << "\033[33m-------" << title << "-------\033[0m" << std::endl;
}

#endif