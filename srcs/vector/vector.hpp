#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class Vector
	{
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::size_type size_type;

		template <class iterator>
		class Iterator_traits
		{
			typedef typename iterator::difference_type difference_type;
			typedef typename iterator::value_type value_type;
			typedef typename iterator::pointer pointer;
			typedef typename iterator::reference reference;
			typedef typename iterator::iterator_category iterator_category;
		};

		public :
			Vector() {};
	};
}

#endif