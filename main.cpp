#include "srcs/vector/vector.hpp"
#include <vector>

int main()
{
	std::vector<int> myvect;
	myvect.push_back(2);
	myvect.push_back(4);
	myvect.push_back(9);
	myvect.push_back(93);
	myvect.push_back(98);
	myvect.push_back(100);
	std::vector<int>::iterator it = myvect.end();
	std::vector<int>::reverse_iterator base_rev_it(it);
	ft::reverse_iterator<std::vector<int>::iterator> rev_it(it);
	std::cout << "\033[33mMY IT >> \033[0m" << rev_it[5] << std::endl;
	std::cout << "\033[35mBASE IT >> \033[0m" << base_rev_it[5] << std::endl;
	rev_it++;
	base_rev_it++;
	std::cout << "\033[33mMY IT >> \033[0m" << *rev_it << std::endl;
	std::cout << "\033[35mBASE IT >> \033[0m" << *base_rev_it << std::endl;
	rev_it += 2;
	base_rev_it += 2;
	std::cout << "\033[33mMY IT >> \033[0m" << *rev_it << std::endl;
	std::cout << "\033[35mBASE IT >> \033[0m" << *base_rev_it << std::endl;
	ft::Vector<int> testsize(10, 42);
	std::cout << "\033[33mMTST VECT SIZE >> \033[0m" << testsize.size() << std::endl;
}