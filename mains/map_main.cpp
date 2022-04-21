#include "../debug_test.hpp"
#include "../srcs/map/map.hpp"
#include <vector>

int main()
{
	header_test_section("Pair/Make_pair doc test");
	ft::pair <int,int> foo;
  	ft::pair <int,int> bar;
	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	foo = bar;
	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	
	header_test_section("RBT tests");
	ft::pair <int,int> insertPair = ft::make_pair (40, 40);
	ft::pair <int,int> insertPair2 = ft::make_pair (32, 32);
	ft::pair <int,int> insertPair3 = ft::make_pair (52, 52);
	ft::Map<int, int> maptest;
	maptest.insert(insertPair);
	maptest.insert(insertPair3);
	maptest.insert(insertPair2);
	maptest.printBT();
}