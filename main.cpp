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
	//templated insert
	BaseVect.insert(BaseVect.begin() + 2, BaseVect.begin(), BaseVect.end());
	for (std::vector<int>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	insertTest.insert(insertTest.begin() + 2, insertTest.begin(), insertTest.end());
	insertTest.print();

	
	header_test_section("Rev it comp. operators");
	std::vector<int> comptest(10, 42);
	std::vector<int>::iterator comp_it = comptest.begin() + 2;
	ft::reverse_iterator<std::vector<int>::iterator> comp_rev_it(comp_it);
	ft::reverse_iterator<std::vector<int>::iterator> comp_rev_it2(comp_it);	
	std::cout << (comp_rev_it == comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it != comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it >= comp_rev_it2) << std::endl;
	comp_rev_it2++;
	std::cout << (comp_rev_it < comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it > comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it <= comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it >= comp_rev_it2) << std::endl;

	header_test_section("Normal iterator");
	std::vector<int> normal_iterator_vect;
	normal_iterator_vect.push_back(456);
	normal_iterator_vect.push_back(45);
	normal_iterator_vect.push_back(4);
	normal_iterator_vect.push_back(56);
	normal_iterator_vect.push_back(498);
	normal_iterator_vect.push_back(99996);
	std::vector<int>::iterator nrm_it = normal_iterator_vect.begin();
	ft::normal_iterator<std::vector<int>::iterator> norm_it(nrm_it);
	std::cout << *norm_it << std::endl;
	norm_it++;
	std::cout << *norm_it << std::endl;
	norm_it+=2;
	std::cout << *norm_it << std::endl;
	norm_it-=2;
	std::cout << *norm_it << std::endl;
	std::cout << norm_it[5] << std::endl;
	std::cout << norm_it[4] << std::endl;
	norm_it--;
	std::cout << *norm_it << std::endl;

	header_test_section("Is the vector empty ?");
	ft::Vector<int> NotEmpty(10,42);
	ft::Vector<int> Empty;
	std::cout << "Not empty : " << NotEmpty.empty() << std::endl;
	std::cout << "Empty : " << Empty.empty() << std::endl;

	header_test_section("Reserve");
	ft::Vector<int> reserveVec(15, 256);
	std::cout << "Capacity : " << reserveVec.capacity() << std::endl;
	std::cout << "Size : " << reserveVec.size() << std::endl;
	reserveVec.reserve(54);
	std::cout << "Capacity : " << reserveVec.capacity() << std::endl;
	std::cout << "Size : " << reserveVec.size() << std::endl;
	reserveVec.reserve(54);
	std::cout << "Capacity : " << reserveVec.capacity() << std::endl;
	std::cout << "Size : " << reserveVec.size() << std::endl;
	reserveVec.reserve(2);
	std::cout << "Capacity : " << reserveVec.capacity() << std::endl;
	std::cout << "Size : " << reserveVec.size() << std::endl;
	reserveVec.reserve(89);
	std::cout << "Capacity : " << reserveVec.capacity() << std::endl;
	std::cout << "Size : " << reserveVec.size() << std::endl;

	header_test_section("Resize");
	ft::Vector<int> resize_vect(10, 42);
	std::vector<int> resize_original_vect(10,42);
	resize_vect.resize(4);
	resize_original_vect.resize(4);
	std::cout << "My vect capacity : " << resize_vect.capacity() << std::endl;
	std::cout << "Original vect capacity : " << resize_original_vect.capacity() << std::endl;
	std::cout << "My vect size : " << resize_vect.size() << std::endl;
	std::cout << "Original vect size : " << resize_original_vect.size() << std::endl;
	resize_vect.resize(12, 8);
	resize_original_vect.resize(12, 8);
	std::cout << "My vect capacity : " << resize_vect.capacity() << std::endl;
	std::cout << "Original vect capacity : " << resize_original_vect.capacity() << std::endl;
	std::cout << "My vect size : " << resize_vect.size() << std::endl;
	std::cout << "Original vect size : " << resize_original_vect.size() << std::endl;
	resize_vect.print();

	//header_test_section("At");
	//std::vector<int> base_at_vect;
	//base_at_vect.push_back(56);
	//base_at_vect.push_back(5);
	//base_at_vect.push_back(6);
	//base_at_vect.push_back(586);
	//base_at_vect.push_back(8965);
	//ft::Vector<int> My_at_vec;
	//My_at_vec.push_back(56);
	//My_at_vec.push_back(5);
	//My_at_vec.push_back(6);
	//My_at_vec.push_back(586);
	//My_at_vec.push_back(8965);
	//std::cout << "my vec at : " << My_at_vec.at(4) << std::endl;
	//std::cout << "base vec at : " << base_at_vect.at(4) << std::endl;
	//std::cout << "my vec at : " << My_at_vec.at(0) << std::endl;
	//std::cout << "base vec at : " << base_at_vect.at(0) << std::endl;
	//std::cout << "my vec at : " << My_at_vec.at(1) << std::endl;
	//std::cout << "base vec at : " << base_at_vect.at(1) << std::endl;

	header_test_section("Assign");
	std::vector<int> base_assign_vec(10, 42);
	ft::Vector<int> my_assign_vec(10, 42);
	for (std::vector<int>::iterator it = base_assign_vec.begin(); it < base_assign_vec.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	my_assign_vec.print();
	base_assign_vec.assign(5, 84);
	my_assign_vec.assign(5, 84);
	for (std::vector<int>::iterator it = base_assign_vec.begin(); it < base_assign_vec.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	my_assign_vec.print();



	header_test_section("END PROGRAM");
}