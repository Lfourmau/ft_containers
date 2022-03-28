#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "../iterators/iterator_traits.hpp"

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > 
class Map
{
	public:
		typedef Key 										key_type;
		typedef T 											mapped_type;
		typedef std::pair<const key_type, mapped_type> 		value_type;
		typedef Compare 									key_compare;
		//value_compare
		typedef Alloc 										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		//typedef ft::reverse_iterator<iterator>	 			reverse_iterator;
		//typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
		typedef ptrdiff_t 									difference_type;
		typedef size_t 										size_type;

		Map() {};
		~Map() {};
};

#endif