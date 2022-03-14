#include "srcs/vector/vector.hpp"
#include "debug_test.hpp"
#include <vector>

void header_test_section(std::string title);

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
	header_test_section("REV IT : |[]|");
	std::cout << "MY IT >>" << rev_it[5] << std::endl;
	std::cout << "BASE IT >>" << base_rev_it[5] << std::endl;
	rev_it++;
	base_rev_it++;

	header_test_section("REV IT : |* & ++|");
	std::cout << "MY IT >>" << *rev_it << std::endl;
	std::cout << "BASE IT >>" << *base_rev_it << std::endl;
	rev_it += 2;
	base_rev_it += 2;

	header_test_section("REV IT : |+= & *|");
	std::cout << "MY IT >>" << *rev_it << std::endl;
	std::cout << "BASE IT >>" << *base_rev_it << std::endl;

	header_test_section("Vector size");
	ft::Vector<int> testsize(10, 42);
	std::cout << "VECT SIZE >> " << testsize.size() << std::endl;

	header_test_section("Vector PopBack");
	ft::Vector<test> pop_back_test;
	test A;
	test B;
	test C;
	pop_back_test.push_back(A);
	pop_back_test.push_back(B);
	pop_back_test.push_back(C);
	std::cout << "VECT SIZE >> " << pop_back_test.size() << std::endl;
	pop_back_test.pop_back();
	std::cout << "VECT SIZE >> " << pop_back_test.size() << std::endl;

	header_test_section("SWAP");
	ft::Vector<int> swap1(10, 30);
	ft::Vector<int> swap2(10,23);
	std::cout << "Vec1 before swapping : ";
	swap1.print();
	std::cout << "Vec2 before swapping : ";
	swap2.print();
	swap1.swap(swap2);
	std::cout << "Vec1 after swapping : ";
	swap1.print();
	std::cout << "Vec2 after swapping : ";
	swap2.print();

	header_test_section("Copy constructor");
	ft::Vector<int> Base;
	Base.push_back(44);
	Base.push_back(443);
	Base.push_back(442);
	Base.push_back(4422);
	std::cout << "Base vector : ";
	Base.print();
	std::cout << "Copy vector : ";
	ft::Vector<int> Copy(Base);
	Copy.print();
	std::cout << "Modifying copy vector..." << std::endl;
	Copy[1] = 42;
	Copy[2] = 999;
	std::cout << "Base vector : ";
	Base.print();
	std::cout << "Copy vector : ";
	Copy.print();
	
	header_test_section("Insert");
	ft::Vector<int> insertTest;
	std::vector<int> BaseVect;
	insertTest.push_back(44);BaseVect.push_back(44);
	insertTest.push_back(443);BaseVect.push_back(443);
	insertTest.push_back(442);BaseVect.push_back(442);
	insertTest.push_back(4422);BaseVect.push_back(4422);
	std::cout << "Test vect :" ;
	insertTest.print();
	std::cout << "Base vect :" ;
	for (std::vector<int>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	std::cout << "Inserting elements.." << std::endl;
	
	BaseVect.insert(BaseVect.begin() + 2, 9);
	insertTest.insert(insertTest.begin() + 2, 9);
	BaseVect.insert(BaseVect.begin() + 4, 99);
	insertTest.insert(insertTest.begin() + 4, 99);
	std::cout << "Test vect :" ;
	insertTest.print();
	std::cout << "Base vect :" ;
	for (std::vector<int>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	header_test_section("END PROGRAM");
}