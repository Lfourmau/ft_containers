#include "srcs/stack/stack.hpp"
#include "debug_test.hpp"
#include <vector>

int main()
{
	ft::Stack<int> test;
	ft::Stack<int> test2;
	test.push(899);
	test2.push(899);
	std::cout << (test == test2) << std::endl;
	std::cout << (test != test2) << std::endl;
	std::cout << (test <= test2) << std::endl;
	std::cout << (test > test2) << std::endl;
	std::cout << (test >= test2) << std::endl;
}