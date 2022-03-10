#include "srcs/vector/vector.hpp"
#include <vector>

int main()
{
	ft::Vector<int> myvect(10, 20);
	myvect.print();
	ft::reverse_iterator<std::vector<int>::iterator> mon_petit_rev_it;
	//std::vector<int> myvect;
	//myvect.push_back(50);
	//myvect.push_back(51);
	//myvect.push_back(52);
	//myvect.push_back(53);
	//std::vector<int>::iterator it = myvect.begin() + 3;
	//std::vector<int>::reverse_iterator rev_it(it);
	//std::cout << rev_it[0] << std::endl;
}