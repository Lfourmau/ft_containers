#include "../debug_test.hpp"
#include "../srcs/map/map.hpp"
#include <vector>
#include <map>

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
	ft::pair <ft::Map<int,int>::iterator, bool > retPair;
	ft::pair <int,int> insertPair = ft::make_pair (1, 1);
	ft::pair <int,int> insertPair2 = ft::make_pair (5, 5);
	ft::pair <int,int> insertPair3 = ft::make_pair (15, 15);
	ft::pair <int,int> insertPair4 = ft::make_pair (8, 8);
	ft::pair <int,int> insertPair5 = ft::make_pair (62, 62);
	ft::pair <int,int> insertPair6 = ft::make_pair (4, 4);
	ft::pair <int,int> insertPair7 = ft::make_pair (2, 2);
	ft::pair <int,int> insertPair8 = ft::make_pair (28, 28);
	ft::pair <int,int> insertPair9 = ft::make_pair (9, 9);
	ft::pair <int,int> insertPair10 = ft::make_pair (99, 99);
	ft::Map<int, int> maptest;
	std::cout << "Map.empty() before insertions-> " << maptest.empty() << std::endl;
	std::cout << "Map.size() before insertions-> " << maptest.size() << std::endl;
	ft::Map<int, int> map_scnd_test;
	maptest.insert(insertPair);
	std::cout << "Map.empty() after 1 insertion-> " << maptest.empty() << std::endl;
	std::cout << "Map.size() after 1 insertion-> " << maptest.size() << std::endl;
	maptest.insert(insertPair2);
	maptest.insert(insertPair4);
	maptest.insert(insertPair5);
	std::cout << "Map.size() after 4 insertion-> " << maptest.size() << std::endl;
	maptest.insert(insertPair6);
	maptest.insert(insertPair7);
	maptest.insert(insertPair8);
	retPair = maptest.insert(insertPair9);
	maptest.insert(insertPair10);
	//maptest.insert(insertPair3);
	maptest.printBT();
	std::cout << retPair.second << std::endl;
	for (ft::Map<int, int>::reverse_iterator it = maptest.rbegin(); it != maptest.rend(); it++)
	{
		std::cout << "[" << (*it).first << "---" << (*it).second << std::endl;
	}
	for (ft::Map<int, int>::iterator it = maptest.begin(); it != maptest.end(); it++)
	{
		std::cout << "[]" << (*it).first << "---" << (*it).second << std::endl;
	}
	map_scnd_test.insert(maptest.begin(), maptest.end());
	ft::Map<int, int>::iterator insertIt = map_scnd_test.begin();
	insertIt++;
	insertIt++;
	std::cout << "{{"  << (*insertIt).first<< std::endl;
	map_scnd_test.printBT();
	map_scnd_test.insert(insertIt, insertPair3);
	map_scnd_test.printBT();
	//ft::Map<int, int>::reverse_iterator it = maptest.rbegin();
	//std::cout << "[" << (*it).first << "---" << (*it).second << std::endl;
	//testIt++;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	//testIt++;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	//testIt++;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	//testIt++;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	//testIt--;
	//testIt--;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	//++testIt;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	//--testIt;
	//std::cout << "[" << (*testIt).first << "--";
	//std::cout << (*testIt).second << "]" << std::endl;
	
}