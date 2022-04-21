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
	ft::pair <std::string,std::string> insertPair = ft::make_pair ("100", "42");
	ft::pair <std::string,std::string> insertPair2 = ft::make_pair ("140", "442");
	ft::Map<std::string, std::string> maptest;
	maptest.insert(insertPair);
	maptest.insert(insertPair2);
}