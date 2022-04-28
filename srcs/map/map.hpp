#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include "../iterators/iterator_traits.hpp"
#include "red_black_tree.hpp"

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

		pair& operator=(const pair& other) 
		{ 
			first = other.first;
			second = other.second;
			return (*this);
		};
	};
	template< class T1, class T2 >
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };
	template< class T1, class T2 >
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs == rhs); };
	template< class T1, class T2 >
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
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
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return (!(rhs < lhs)); };
	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return (rhs < lhs); };
	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return (!(lhs < rhs)); };
	//MAKE PAIR
	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair(T1 t, T2 u)
	{
		return ( ft::pair<T1,T2>(t,u) );
	};

	//MAP CONTAINER
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
	class Map
	{
		public:
			typedef Key 										key_type;
			typedef T 											mapped_type;
			typedef ft::pair<const key_type, mapped_type> 		value_type;
			typedef Compare 									key_compare;
			//value_compare
			typedef Alloc 										allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef ptrdiff_t 									difference_type;
			typedef size_t 										size_type;

			//Constructor
			Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : cmp(comp), _my_alloc(alloc), rbt(cmp, node_allocator) {};
			//template <class InputIterator>
			//Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			//Map (const Map& x);
			~Map() {};
			class value_compare
			{
				friend class Map;
				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {};
				public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); };
			};

			typedef typename red_black_tree<value_type, typename Alloc::template rebind<Node<value_type> >::other, value_compare>::template rbt_iterator<value_type>	iterator;
			typedef typename red_black_tree<value_type, typename Alloc::template rebind<Node<value_type> >::other, value_compare>::template const_rbt_iterator<value_type>	const_iterator;
			typedef ft::rbt_reverse_iterator<iterator>	 			reverse_iterator;
			typedef ft::rbt_reverse_iterator<const_iterator> 		const_reverse_iterator;
			iterator begin()
			{
				return (iterator(rbt.maxleft()));
			};
			const_iterator begin() const
			{
				return (iterator(rbt.maxleft()));
			};
			iterator end()
			{
				return (iterator(NULL));
			};
			const_iterator end() const
			{
				return (iterator(NULL));
			};
			reverse_iterator rbegin() { return iterator(rbt.maxright()); };
			const_reverse_iterator rbegin() const { return end(); };
			reverse_iterator rend() { return iterator(NULL); };
			const_reverse_iterator rend() const { return iterator(NULL); };
			ft::pair<iterator, bool> insert (const value_type& val)
			{
				bool flag;
				iterator it = rbt.insert(val, &flag); 
				ft::pair<iterator, bool> ret_pair = ft::make_pair(it, flag);
				return (ret_pair);
			};
			iterator insert (iterator position, const value_type& val)
			{
				ft::pair<iterator, bool> ret;

				if (cmp(val, *position))
				{
					ret = insert(val);
					return (ret.first);
				}
				else
				{
					return rbt.insert_from_position(position, val);
				}
			};
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
			};
			void printBT()
			{
				rbt.printBT();
			}
		private:
			typedef typename Alloc::template rebind<Node<value_type> >::other _Alty;
			_Alty node_allocator;
			value_compare cmp;
			allocator_type _my_alloc;
			red_black_tree<value_type, _Alty, value_compare> rbt;
	};
}

#endif