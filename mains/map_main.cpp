#include "../debug_test.hpp"
#include "../srcs/map/map.hpp"
#include <vector>
#include <map>

int main()
{
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
	maptest.insert(insertPair3);
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
	ft::Map<int, int>::iterator findIt = maptest.find(4);
	std::cout << "Find iterator : Lookup for a 4key-> "  << (*findIt).first<< std::endl;
	insertIt++;
	insertIt++;
	std::cout << "{{"  << (*insertIt).first<< std::endl;
	map_scnd_test.printBT();
	map_scnd_test.insert(insertIt, insertPair3);
	map_scnd_test.printBT();
	map_scnd_test.erase(4);
	map_scnd_test.printBT();
	std::cout << map_scnd_test.size() << std::endl;
	map_scnd_test.clear();
	std::cout << map_scnd_test.size() << std::endl;
	// std::cout << "DELETING 15" << std::endl;
	// ft::Map<int, int>::iterator eraseIt = map_scnd_test.find(15);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 28" << std::endl;
	// eraseIt = map_scnd_test.find(28);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 9" << std::endl;
	// eraseIt = map_scnd_test.find(9);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 5" << std::endl;
	// eraseIt = map_scnd_test.find(5);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 62" << std::endl;
	// eraseIt = map_scnd_test.find(62);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 2" << std::endl;
	// eraseIt = map_scnd_test.find(2);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 4" << std::endl;
	// eraseIt = map_scnd_test.find(4);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 99" << std::endl;
	// eraseIt = map_scnd_test.find(99);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
	// std::cout << "DELETING 8" << std::endl;
	// eraseIt = map_scnd_test.find(8);
	// map_scnd_test.erase(eraseIt);
	// map_scnd_test.printBT();
}