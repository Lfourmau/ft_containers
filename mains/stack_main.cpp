#include "../srcs/stack/stack.hpp"
#include "../debug_test.hpp"
#include <vector>
#include <deque>
#include <stack>

int main()
{
	header_test_section("**DEQUEUE BASED**");
	ft::Stack< int, std::deque<int> > test;
	ft::Stack< int, std::deque<int> > test2;
	std::cout << "push 4 elements in each stacks..." << std::endl;
	header_test_section("~~Comparison operators~~");
	test.push(899);test2.push(899);
	test.push(3);test2.push(3);
	test.push(45);test2.push(45);
	test.push(676);test2.push(676);
	std::cout << (test == test2) << std::endl;
	std::cout << (test != test2) << std::endl;
	std::cout << (test <= test2) << std::endl;
	std::cout << (test > test2) << std::endl;
	std::cout << (test >= test2) << std::endl;
	header_test_section("~~Size and pop~~");
	std::cout << "size of stack1 : " << test.size() << std::endl;
	std::cout << "size of stack2 : " << test2.size() << std::endl;
	std::cout << "pop 2 elements..." << std::endl;
	test.pop();test2.pop();
	test.pop();test2.pop();
	std::cout << "size of stack1 : " << test.size() << std::endl;
	std::cout << "size of stack2 : " << test2.size() << std::endl;
	header_test_section("~~Empty~~");
	std::cout << "pop 2 lefts elements.." << std::endl;
	test.pop();test2.pop();
	test.pop();test2.pop();
	std::cout << "Stack1 empty : " << test.empty() << std::endl;
	std::cout << "Stack2 empty : " << test2.empty() << std::endl;
	std::cout << "push 1 element in each stack.." << std::endl;
	test.push(34);test2.push(43);
	std::cout << "Stack1 empty : " << test.empty() << std::endl;
	std::cout << "Stack2 empty : " << test2.empty() << std::endl;
	header_test_section("~~Top~~");
	std::cout << "Stack1 top : " << test.top() << std::endl;
	std::cout << "Stack2 top : " << test2.top() << std::endl;
	std::cout << "push 42 in each stack" << std::endl;
	test.push(42);test2.push(42);
	std::cout << "Stack1 top : " << test.top() << std::endl;
	std::cout << "Stack2 top : " << test2.top() << std::endl;
//-------------------------------------------------------------
	header_test_section("**DEFAULT BASED (VECTOR)**");
	ft::Stack<int> vecstack;
	ft::Stack<int> vecstack2;
	std::cout << "push 4 elements in each stacks..." << std::endl;
	header_test_section("~~Comparison operators~~");
	vecstack.push(899);vecstack2.push(899);
	vecstack.push(3);vecstack2.push(3);
	vecstack.push(45);vecstack2.push(45);
	vecstack.push(676);vecstack2.push(676);
	std::cout << (vecstack == vecstack2) << std::endl;
	std::cout << (vecstack != vecstack2) << std::endl;
	std::cout << (vecstack <= vecstack2) << std::endl;
	std::cout << (vecstack > vecstack2) << std::endl;
	std::cout << (vecstack >= vecstack2) << std::endl;
	header_test_section("~~Size and pop~~");
	std::cout << "size of stack1 : " << vecstack.size() << std::endl;
	std::cout << "size of stack2 : " << vecstack2.size() << std::endl;
	std::cout << "pop 2 elements..." << std::endl;
	vecstack.pop();vecstack2.pop();
	vecstack.pop();vecstack2.pop();
	std::cout << "size of stack1 : " << vecstack.size() << std::endl;
	std::cout << "size of stack2 : " << vecstack2.size() << std::endl;
	header_test_section("~~Empty~~");
	std::cout << "pop 2 lefts elements.." << std::endl;
	vecstack.pop();vecstack2.pop();
	vecstack.pop();vecstack2.pop();
	std::cout << "Stack1 empty : " << vecstack.empty() << std::endl;
	std::cout << "Stack2 empty : " << vecstack2.empty() << std::endl;
	std::cout << "push 1 element in each stack.." << std::endl;
	vecstack.push(34);vecstack2.push(43);
	std::cout << "Stack1 empty : " << vecstack.empty() << std::endl;
	std::cout << "Stack2 empty : " << vecstack2.empty() << std::endl;
	header_test_section("~~Top~~");
	std::cout << "Stack1 top : " << vecstack.top() << std::endl;
	std::cout << "Stack2 top : " << vecstack2.top() << std::endl;
	std::cout << "push 42 in each stack" << std::endl;
	vecstack.push(42);vecstack2.push(42);
	std::cout << "Stack1 top : " << vecstack.top() << std::endl;
	std::cout << "Stack2 top : " << vecstack2.top() << std::endl;
}