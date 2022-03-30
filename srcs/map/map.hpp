#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "../iterators/iterator_traits.hpp"

namespace ft
{
	//PAIR
	template<class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;
		pair() : first(0), second(0) {};
		pair(const T1& x, const T2& y) : first(x), second(y) {};
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) :first(p.first), second(p.second) {};
		//pair( const pair& p ) = default;

		pair& operator=( const pair& other ) 
		{ 
			first = other.first;
			second = other.second;
			return (*this);
		};
	};
	template< class T1, class T2 >
	bool operator==(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };
	template< class T1, class T2 >
	bool operator!=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs) { return !(lhs == rhs); };
	template< class T1, class T2 >
	bool operator<(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs)
	{
		if (lhs.first < rhs.first)
			return (true);
		else if (rhs.first < lhs.first)
			return (false);
		if (lhs.second < rhs.second)
			return (true);
		return (false);
	};
	template< class T1, class T2 >
	bool operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) { return (!(rhs < lhs)); };
	template< class T1, class T2 >
	bool operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) { return (rhs < lhs); };
	template< class T1, class T2 >
	bool operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ) { return (!(lhs < rhs)); };
	//MAKE PAIR
	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair(T1 t, T2 u)
	{
		return ( ft::pair<T1,T2>(t,u) );
	};


	//MAP CONTAINER
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

			//Constructor
			Map() {};
			//Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			//template <class InputIterator>
			//Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			//Map (const Map& x);
			~Map() {};

	};
}

#endif