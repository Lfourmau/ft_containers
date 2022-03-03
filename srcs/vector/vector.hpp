#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>
#include <memory>
#include "../iterators/iterator_traits.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class Vector
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef typename allocator_type::size_type 			size_type;

		Iterator_traits<const_iterator> it;

		public :
			Vector() {};
			~Vector() {};
			T* array;
	};
}

#endif