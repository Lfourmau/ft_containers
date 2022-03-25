#include "srcs/stack/stack.hpp"
#include "debug_test.hpp"
#include <vector>
#include <deque>
#include <stack>

int main()
{
	ft::Stack< int, std::deque<int> > test;
	ft::Stack< int, std::deque<int> > test2;
	test.push(899);
	test2.push(899);
	std::cout << (test == test2) << std::endl;
	std::cout << (test != test2) << std::endl;
	std::cout << (test <= test2) << std::endl;
	std::cout << (test > test2) << std::endl;
	std::cout << (test >= test2) << std::endl;
}