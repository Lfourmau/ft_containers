#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <utility>
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
	class map
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

			//Constructors
			map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : cmp(comp), _my_alloc(alloc), rbt(cmp, node_allocator) {};
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : cmp(comp), _my_alloc(alloc), rbt(cmp, node_allocator)
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
			};
			map (const map& x) : cmp(x.cmp), _my_alloc(x._my_alloc), rbt(x.cmp, x.node_allocator)
			{
				for(const_iterator it = x.begin(); it != NULL; it++)
					this->insert(*it);
			};
			~map() {};
			class value_compare
			{
				friend class map;
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
				return (const_iterator(rbt.maxleft()));
			};
			iterator end()
			{
				return (iterator(NULL));
			};
			const_iterator end() const
			{
				return (const_iterator(NULL));
			};
			bool empty() const { return (rbt.get_root() == nullptr); };
			size_t size() const { return (rbt.size()); }
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(value_type)); };
			void swap(map& other)
			{
				std::swap(*this, other);
			};
			iterator find(const Key& key)
			{
				Node<value_type> *current = rbt.get_root();
				value_type k = ft::make_pair(key, 0);

				while (current)
				{
					if (cmp(current->value, k))
						current = current->right;
					else if (cmp(k, current->value))
						current = current->left;
					else
						return (iterator(current));
				}
				return(this->end());
			};
			const_iterator find(const Key& key) const
			{
				Node<value_type> *current = rbt.get_root();
				value_type k = ft::make_pair(key, 0);

				while (current)
				{
					if (cmp(current->value, k))
						current = current->right;
					else if (cmp(k, current->value))
						current = current->left;
					else
						return (const_iterator(current));
				}
				return(this->end());
			}
			void clear() { rbt.clear(); };
			reverse_iterator rbegin() { return iterator(rbt.maxright()); };
			const_reverse_iterator rbegin() const { return const_iterator(rbt.maxright()); };
			reverse_iterator rend() { return iterator(NULL); };
			const_reverse_iterator rend() const { return const_iterator(NULL); };
			allocator_type get_allocator() const { return (_my_alloc); };
			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			};
			iterator lower_bound (const key_type& key)
			{
				Node<value_type> *current = rbt.get_root();
				value_type k = ft::make_pair(key, 0);

				while (current)
				{
					if (cmp(k, current->value))
					{
						if (current->left)
							current = current->left;
						else
							return iterator(current);
					}
					else if (cmp(current->value, k))
					{
						if (current->right)
							return iterator(current->right);
						return ++iterator(current);
					}
					else
						return (iterator(current));
				}
				return this->end();
			};
			const_iterator lower_bound (const key_type& k) const { return const_iterator(this->lower_bound(k)); };
			iterator upper_bound(const key_type& key)
			{
				Node<value_type> *current = rbt.get_root();
				value_type k = ft::make_pair(key, 0);

				while (current)
				{
					if (cmp(k, current->value))
					{
						if (current->left)
							current = current->left;
						else
							return iterator(current);
					}
					else
					{
						if (current->right)
							return iterator(current->right);
						return ++iterator(current);
					}
				}
				return this->end();
			}
			const_iterator upper_bound (const key_type& k) const { return const_iterator(this->upper_bound(k)); };
			ft::pair<iterator,iterator> equal_range( const Key& key ) { return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); };
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const { return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); };
			size_type count( const Key& key ) const
			{
				if (find(key) != this->end())
					return (1);
				return (0);
			};
			ft::pair<iterator, bool> insert (const value_type& val)
			{
				bool flag;
				iterator it = rbt.insert(val, &flag); 
				ft::pair<iterator, bool> ret_pair = ft::make_pair(it, flag);
				return (ret_pair);
			};
			iterator insert (iterator position, const value_type& val)
			{
				Node<value_type> *n = rbt.get_root();
				Node<value_type> *cursor;

				if (n == nullptr || n->parent == nullptr)
					return (insert(val).first);
				cursor = n->parent;
				if (cmp(val, n->value))
				{
                    if (n != n->parent->left && cmp(val, cursor->value))
                        return insert(val).first;
                    else if (n == n->parent->left)
                        return (rbt.insert_from_position(position, val));
                }
                else
				{
                    if (n == n->parent->left && cmp(cursor->value, val))
                        return insert(val).first;
                    else if (n != n->parent->left)
                        return (rbt.insert_from_position(position, val));
                }
                return (rbt.insert_from_position(position, val));
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
			void erase(iterator pos) { rbt.erase(pos); };
			void erase(iterator first, iterator last)
			{
				while (first != last)
				{
					iterator tmp = first;
					first++;
					this->erase(tmp);
				}
			};
			size_type erase(const Key& key)
			{
				iterator it = this->find(key);
				if (it == this->end())
					return (0);
				else
				{
					this->erase(it);
					return (1);
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