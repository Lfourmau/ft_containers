#include "../srcs/vector/vector.hpp"
#include "../debug_test.hpp"
#include <vector>

void header_test_section(std::string title);
void test_vector_pushback();
void testrev_it_operators();
void test_vector_size();
void test_vector_popback();
void test_vector_swap();
void test_vector_copy_constructor();
void test_vector_insert();
void test_rev_it_comp_operators();
void test_normal_iterator();
void test_vector_empty();
void test_vector_reserve();
void test_vector_resize();
void test_vector_at();
void test_vector_assign();
void test_vector_erase();
void test_range_constructor();
void test_const_iterators();
void test_relationnal_operators();
void test_const_rev_it();

int main()
{
 	test_vector_pushback();
	testrev_it_operators();
	test_vector_size();
	test_vector_popback();
	test_vector_swap();
	test_vector_copy_constructor();
	test_vector_insert();
	test_rev_it_comp_operators();
	test_normal_iterator();
	test_vector_empty();
	test_vector_reserve();
	test_vector_resize();
	test_vector_at();
	test_vector_assign();
	test_vector_erase();
	//test_range_constructor(); (free after modified problem)
	test_const_iterators();
	test_relationnal_operators();
	test_const_rev_it();
	header_test_section("END PROGRAM");
}


void test_vector_pushback()
{
	header_test_section("Push Back");
	ft::Vector<std::string> My_pushback_vect;
	My_pushback_vect.push_back("okok");
	My_pushback_vect.push_back("eeeee");
	My_pushback_vect.push_back("okok");
	My_pushback_vect.push_back("okok");
	My_pushback_vect.push_back("okok");
	My_pushback_vect.push_back("okok");
	My_pushback_vect.push_back("okok");

	std::vector<std::string> base_pushback_vect;
	base_pushback_vect.push_back("okok");
	base_pushback_vect.push_back("eeeee");
	base_pushback_vect.push_back("okok");
	base_pushback_vect.push_back("okok");
	base_pushback_vect.push_back("okok");
	base_pushback_vect.push_back("okok");
	base_pushback_vect.push_back("okok");
	std::cout << "Base vect : ";
	for (std::vector<std::string>::iterator it = base_pushback_vect.begin(); it != base_pushback_vect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	std::cout << "Test vect : ";
	My_pushback_vect.print();
}

void testrev_it_operators()
{
	header_test_section("REV IT : |[]|");
	std::vector<std::string> myvect;
	myvect.push_back("ok");
	myvect.push_back("ehplo");
	myvect.push_back("bsoir");
	myvect.push_back("ui");
	myvect.push_back("yo");
	myvect.push_back("ha");
	std::vector<std::string>::iterator it = myvect.end();
	std::vector<std::string>::reverse_iterator base_rev_it(it);
	ft::reverse_iterator<std::vector<std::string>::iterator> rev_it(it);
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
}

void test_vector_size()
{
	header_test_section("Vector size");
	ft::Vector<std::string> testsize(10, "okokokk");
	std::cout << "VECT SIZE >> " << testsize.size() << std::endl;
}

void test_vector_popback()
{
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
}

void test_vector_swap()
{
	header_test_section("SWAP");
	ft::Vector<std::string> swap1(10, "bonsoir");
	ft::Vector<std::string> swap2(10, "bonjour");
	std::cout << "Vec1 before swapping : ";
	swap1.print();
	std::cout << "Vec2 before swapping : ";
	swap2.print();
	swap1.swap(swap2);
	std::cout << "Vec1 after swapping : ";
	swap1.print();
	std::cout << "Vec2 after swapping : ";
	swap2.print();
}

void test_vector_copy_constructor()
{
	header_test_section("Copy constructor");
	ft::Vector<std::string> Base;
	Base.push_back("bsoir");
	Base.push_back("c le tst");
	Base.push_back("des string");
	Base.push_back("ui");
	std::cout << "Base vector : ";
	Base.print();
	std::cout << "Copy vector : ";
	ft::Vector<std::string> Copy(Base);
	Copy.print();
	std::cout << "Modifying copy vector..." << std::endl;
	Copy[1] = "vamos";
	Copy[2] = "vomas";
	std::cout << "Base vector : ";
	Base.print();
	std::cout << "Copy vector : ";
	Copy.print();
}

void test_vector_insert()
{
	header_test_section("Insert");
	ft::Vector<std::string> insertTest;
	std::vector<std::string> BaseVect;
	insertTest.push_back("a");BaseVect.push_back("a");
	insertTest.push_back("LA");BaseVect.push_back("LA");
	insertTest.push_back("Queue");BaseVect.push_back("Queue");
	insertTest.push_back("lele");BaseVect.push_back("lele");
	std::cout << "Test vect :" ;
	insertTest.print();
	std::cout << "Base vect :" ;
	for (std::vector<std::string>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	std::cout << "Inserting elements.." << std::endl;
	BaseVect.insert(BaseVect.begin() + 2, "olah");
	insertTest.insert(insertTest.begin() + 2, "olah");
	BaseVect.insert(BaseVect.end(), "tamere");
	insertTest.insert(insertTest.end(), "tamere");
	BaseVect.insert(BaseVect.begin(), "eldenring");
	insertTest.insert(insertTest.begin(), "eldenring");
	std::cout << "Test vect :" ;
	insertTest.print();
	std::cout << "Base vect :" ;
	for (std::vector<std::string>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	//templated insert
	std::vector<std::string> insertion_vect;insertion_vect.push_back("one");insertion_vect.push_back("two");insertion_vect.push_back("threee");insertion_vect.push_back("for");
	BaseVect.insert(BaseVect.begin() + 2, insertion_vect.begin(), insertion_vect.begin() + 4);
	for (std::vector<std::string>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	insertTest.insert(insertTest.begin() + 2, insertion_vect.begin(), insertion_vect.begin() + 4);
	insertTest.print();
	std::cout << "Inserting..." << std::endl;
	insertTest.insert(insertTest.begin() + 2, 4, "quaranta-y-dos");
	insertTest.print();
	BaseVect.insert(BaseVect.begin() + 2, 4, "quaranta-y-dos");
	for (std::vector<std::string>::iterator it = BaseVect.begin(); it != BaseVect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	
}

void test_rev_it_comp_operators()
{
	header_test_section("Rev it comp. operators");
	std::vector<std::string> comptest(10, "akaka");
	std::vector<std::string>::iterator comp_it = comptest.begin() + 2;
	ft::reverse_iterator<std::vector<std::string>::iterator> comp_rev_it(comp_it);
	ft::reverse_iterator<std::vector<std::string>::iterator> comp_rev_it2(comp_it);	
	std::cout << (comp_rev_it == comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it != comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it >= comp_rev_it2) << std::endl;
	comp_rev_it2++;
	std::cout << (comp_rev_it < comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it > comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it <= comp_rev_it2) << std::endl;
	std::cout << (comp_rev_it >= comp_rev_it2) << std::endl;
}

void test_normal_iterator()
{
	header_test_section("Normal iterator");
	std::vector<std::string> normal_iterator_vect;
	ft::Vector<std::string> my_normal_iterator_vect;
	normal_iterator_vect.push_back("elden");my_normal_iterator_vect.push_back("elden");
	normal_iterator_vect.push_back("ring");my_normal_iterator_vect.push_back("ring");
	normal_iterator_vect.push_back("torrent");my_normal_iterator_vect.push_back("torrent");
	normal_iterator_vect.push_back("godrick");my_normal_iterator_vect.push_back("godrick");
	normal_iterator_vect.push_back("limier");my_normal_iterator_vect.push_back("limier");
	normal_iterator_vect.push_back("saignement");my_normal_iterator_vect.push_back("saignement");
	std::vector<std::string>::iterator nrm_it = normal_iterator_vect.begin();
	ft::Vector<std::string>::iterator norm_it = my_normal_iterator_vect.begin();
	std::cout << *norm_it << "---" << *nrm_it << std::endl;
	norm_it++;nrm_it++;
	std::cout << *norm_it << "---" << *nrm_it << std::endl;
	norm_it+=2;nrm_it+=2;
	std::cout << *norm_it << "---" << *nrm_it << std::endl;
	norm_it-=2;nrm_it-=2;
	std::cout << *norm_it << "---" << *nrm_it << std::endl;
	std::cout << norm_it[5] << "---" << nrm_it[5] << std::endl;
	std::cout << norm_it[4] << "---" << nrm_it[4] << std::endl;
	norm_it--;nrm_it--;
	std::cout << *norm_it << "---" << *nrm_it << std::endl;
}

void test_vector_empty()
{
	header_test_section("Is the vector empty ?");
	ft::Vector<std::string> NotEmpty(10,"Quarantqdos");
	ft::Vector<std::string> Empty;
	std::cout << "Not empty : " << NotEmpty.empty() << std::endl;
	std::cout << "Empty : " << Empty.empty() << std::endl;
}

void test_vector_reserve()
{
	header_test_section("Reserve");
	ft::Vector<std::string> reserveVec(15, "uneString");
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
}

void test_vector_resize()
{
	header_test_section("Resize");
	ft::Vector<std::string> resize_vect(10, "tob");
	std::vector<std::string> resize_original_vect(10,"Botika");
	resize_vect.resize(4);
	resize_original_vect.resize(4);
	std::cout << "My vect capacity : " << resize_vect.capacity() << std::endl;
	std::cout << "Original vect capacity : " << resize_original_vect.capacity() << std::endl;
	std::cout << "My vect size : " << resize_vect.size() << std::endl;
	std::cout << "Original vect size : " << resize_original_vect.size() << std::endl;
	resize_vect.resize(12, "val");
	resize_original_vect.resize(12, "val");
	std::cout << "My vect capacity : " << resize_vect.capacity() << std::endl;
	std::cout << "Original vect capacity : " << resize_original_vect.capacity() << std::endl;
	std::cout << "My vect size : " << resize_vect.size() << std::endl;
	std::cout << "Original vect size : " << resize_original_vect.size() << std::endl;
	resize_vect.print();
}

void test_vector_at()
{
	header_test_section("At");
	std::vector<std::string> base_at_vect;
	base_at_vect.push_back("first");
	base_at_vect.push_back("second");
	base_at_vect.push_back("third");
	base_at_vect.push_back("fourth");
	base_at_vect.push_back("fifth");
	ft::Vector<std::string> My_at_vec;
	My_at_vec.push_back("first");
	My_at_vec.push_back("second");
	My_at_vec.push_back("third");
	My_at_vec.push_back("fourth");
	My_at_vec.push_back("fifth");
	std::cout << "my vec at : " << My_at_vec.at(4) << std::endl;
	std::cout << "base vec at : " << base_at_vect.at(4) << std::endl;
	std::cout << "my vec at : " << My_at_vec.at(0) << std::endl;
	std::cout << "base vec at : " << base_at_vect.at(0) << std::endl;
	std::cout << "my vec at : " << My_at_vec.at(1) << std::endl;
	std::cout << "base vec at : " << base_at_vect.at(1) << std::endl;
}

void test_vector_assign()
{
	header_test_section("Assign");
	std::vector<std::string> base_assign_vec(10, "Coucoucmoa");
	ft::Vector<std::string> my_assign_vec(10, "Coucoucmoa");
	for (std::vector<std::string>::iterator it = base_assign_vec.begin(); it < base_assign_vec.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	my_assign_vec.print();
	base_assign_vec.assign(5, "topitokaka");
	my_assign_vec.assign(5, "topitokaka");
	for (std::vector<std::string>::iterator it = base_assign_vec.begin(); it < base_assign_vec.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	my_assign_vec.print();
	//range assign
	base_assign_vec.assign(my_assign_vec.begin(), my_assign_vec.begin() + 3);
	for (std::vector<std::string>::iterator it = base_assign_vec.begin(); it < base_assign_vec.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	my_assign_vec.assign(base_assign_vec.begin(), base_assign_vec.begin() + 3);
	my_assign_vec.print();
}

void test_vector_erase()
{
	header_test_section("Erase");
	std::vector<std::string> erase_base_vect;
	ft::Vector<std::string> erase_test_vect;
	erase_base_vect.push_back("wehsh");erase_test_vect.push_back("wehsh");
	erase_base_vect.push_back("pelo");erase_test_vect.push_back("pelo");
	erase_base_vect.push_back("eh");erase_test_vect.push_back("eh");
	erase_base_vect.push_back("41");erase_test_vect.push_back("41");
	erase_base_vect.push_back("Nikepitech");erase_test_vect.push_back("Nikepitech");
	erase_base_vect.push_back("vivenous");erase_test_vect.push_back("vivenous");
	std::cout << "Vectors before erase : " << std::endl;
	std::cout << "Base vect : ";
	for (std::vector<std::string>::iterator it = erase_base_vect.begin(); it < erase_base_vect.end(); it++)
			std::cout << *it << "---";
	std::cout << std::endl;
	std::cout << "Test vect : ";
	erase_test_vect.print();
	std::cout << "Erasing..." << std::endl;

	erase_base_vect.erase(erase_base_vect.begin() + 2);
	erase_base_vect.erase(erase_base_vect.end() - 1);
	std::cout << "Base vect : ";
	for (std::vector<std::string>::iterator it = erase_base_vect.begin(); it < erase_base_vect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;

	std::cout << "Test vect : ";
	erase_test_vect.erase(erase_test_vect.begin() + 2);
	erase_test_vect.erase(erase_test_vect.end() - 1);
	erase_test_vect.print();

	std::cout << "Erasing by template..." << std::endl;

	erase_test_vect.erase(erase_test_vect.begin(), erase_test_vect.begin() + 2);
	erase_base_vect.erase(erase_base_vect.begin(), erase_base_vect.begin() + 2);
	std::cout << "Base vect : ";
	for (std::vector<std::string>::iterator it = erase_base_vect.begin(); it < erase_base_vect.end(); it++)
		std::cout << *it << "---";
	std::cout << std::endl;
	std::cout << "Test vect : ";
	erase_test_vect.print();
}

void test_range_constructor()
{
	header_test_section("Range constructor");
	ft::Vector<std::string> other_vec;
	other_vec.push_back("on");
	other_vec.push_back("tst");
	other_vec.push_back("la");
	other_vec.push_back("range");
	other_vec.push_back("construction");
	other_vec.push_back("un peu la");
	std::cout << "Original vector :";
	for (ft::Vector<std::string>::iterator it = other_vec.begin(); it < other_vec.end(); it++)
			std::cout << *it << "---";
	std::cout << std::endl;
	std::cout << "Constructed vector :";
	ft::Vector<std::string> my_vect(other_vec.begin(), other_vec.end());
	my_vect.print();
}

void test_const_iterators()
{
	header_test_section("Const iterator");
	const ft::Vector<std::string> myvect(10, "vingt");

	for (ft::Vector<std::string>::const_iterator const_it = myvect.begin(); const_it != myvect.end(); const_it++)
	{
		//*const_it = 5;
		std::cout << *const_it << "---";
	}
	std::cout << std::endl;
}

void test_relationnal_operators()
{
	header_test_section("Relationnal operators");
	std::cout << "~~~==~~~" << std::endl;
	ft::Vector<std::string> first_vec (10, "unsetring");
	ft::Vector<std::string> scnd_vec (10, "deuxiemestring");
	std::cout << (first_vec == scnd_vec) << std::endl;
	scnd_vec.assign(10, "unsetring");
	std::cout << (first_vec == scnd_vec) << std::endl;

	std::cout << "~~~!=~~~" << std::endl;
	std::cout << (first_vec != scnd_vec) << std::endl;
	scnd_vec.assign(10, "hopla");
	first_vec.print();
	std::cout << std::endl;
	scnd_vec.print();
	std::cout << (first_vec != scnd_vec) << std::endl;
	std::cout << std::endl;

	std::cout << "~~~<~~~" << std::endl;
	first_vec.print();
	std::cout << std::endl;
	scnd_vec.print();
	ft::Vector<std::string> third_vec(scnd_vec);
	std::cout << (first_vec < scnd_vec) << std::endl;
	std::cout << (third_vec < scnd_vec) << std::endl;

	std::cout << "~~~<=~~~" << std::endl;
	first_vec.print();
	std::cout << std::endl;
	scnd_vec.print();
	std::cout << (first_vec <= scnd_vec) << std::endl;
	std::cout << (third_vec <= scnd_vec) << std::endl;

	std::cout << "~~~>~~~" << std::endl;
	first_vec.print();
	std::cout << std::endl;
	scnd_vec.print();
	std::cout << (first_vec > scnd_vec) << std::endl;
	std::cout << (third_vec > scnd_vec) << std::endl;

	std::cout << "~~~>=~~~" << std::endl;
	first_vec.print();
	std::cout << std::endl;
	scnd_vec.print();
	std::cout << (first_vec >= scnd_vec) << std::endl;
	std::cout << (third_vec >= scnd_vec) << std::endl;
}

void test_const_rev_it()
{
	header_test_section("Const rev iterators");
	const ft::Vector<std::string> myvect(10, "karanteude");
	ft::Vector<std::string>::const_iterator it = myvect.end();
	ft::Vector<std::string>::const_iterator it2 = myvect.begin();
	ft::reverse_iterator<ft::Vector<std::string>::const_iterator> rev_it(it);
	ft::reverse_iterator<ft::Vector<std::string>::const_iterator> rev_it2(it2);
	//std::reverse_iterator<ft::Vector<std::string>::const_iterator> rev_it(it);
	//std::reverse_iterator<ft::Vector<std::string>::const_iterator> rev_it2(it2);

	while (rev_it != rev_it2)
	{
		//*rev_it = 8;
		std::cout << *rev_it << "---";
		rev_it++;
	}
	std::cout << std::endl;
}