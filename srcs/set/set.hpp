#ifndef SET_HPP
# define SET_HPP

#include "../map/map.hpp"
#include "../map/red_black_tree.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > 
	class set
	{
		public:
			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename red_black_tree<value_type, typename Alloc::template rebind<Node<value_type> >::other, value_compare>::template rbt_iterator<value_type>	iterator;
			typedef typename red_black_tree<value_type, typename Alloc::template rebind<Node<value_type> >::other, value_compare>::template const_rbt_iterator<value_type>	const_iterator;
			typedef ft::rbt_reverse_iterator<iterator>	 			reverse_iterator;
			typedef ft::rbt_reverse_iterator<const_iterator> 		const_reverse_iterator;
			typedef size_t size_type;


			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : cmp(comp), _my_alloc(alloc), rbt(cmp, node_allocator) {};
			template <class InputIterator>
  			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : cmp(comp), _my_alloc(alloc), rbt(cmp, node_allocator)
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
			};
			set (const set& x) : cmp(x.cmp), _my_alloc(x._my_alloc), rbt(x.cmp, x.node_allocator)
			{
				for(const_iterator it = x.begin(); it != NULL; it++)
					this->insert(*it);
			};
			~set() { this->clear(); };
			iterator begin() { return (iterator(rbt.maxleft())); };
			const_iterator begin() const { return (const_iterator(rbt.maxleft())); };
			iterator end() { return (iterator(NULL, rbt.maxright())); };
			const_iterator end() const { return (const_iterator(NULL, rbt.maxright())); };
			reverse_iterator rbegin() { return reverse_iterator(rbt.maxright()); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(rbt.maxright()); };
			reverse_iterator rend() { return reverse_iterator(iterator(NULL, rbt.maxleft())); };
			const_reverse_iterator rend() const { return const_reverse_iterator(iterator(NULL, rbt.maxleft())); };
			bool empty() const { return (rbt.get_root() == nullptr); };
			size_t size() const { return (rbt.size()); }
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(Node<value_type>)); };

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
			size_type erase(const key_type& key)
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
			void swap(set& other)
			{
				rbt.swap(other.rbt); 
			};
			void clear() { rbt.clear(); };

			iterator find(const key_type& key)
			{
				Node<value_type> *current = rbt.get_root();

				while (current)
				{
					if (cmp(current->value, key))
						current = current->right;
					else if (cmp(key, current->value))
						current = current->left;
					else
						return (iterator(current));
				}
				return(this->end());
			};
			const_iterator find(const key_type& key) const
			{
				Node<value_type> *current = rbt.get_root();

				while (current)
				{
					if (cmp(current->value, key))
						current = current->right;
					else if (cmp(key, current->value))
						current = current->left;
					else
						return (const_iterator(current));
				}
				return(this->end());
			}
			iterator lower_bound (const key_type& key)
			{
				iterator current = this->begin();

				while (current != this->end())
				{
					if (cmp(*current, key) == false)
						return (current);
					current++;
				}
				return (this->end());
			};
			const_iterator lower_bound (const key_type& k) const { return const_iterator(this->lower_bound(k)); };
			iterator upper_bound(const key_type& key)
			{
				iterator current = this->begin();

				while (current != this->end())
				{
					if (cmp(*current, key) == false && (cmp(*current, key) || cmp(key, *current)))
						return (current);
					current++;
				}
				return (this->end());
			}
			const_iterator upper_bound (const key_type& k) const { return const_iterator(this->upper_bound(k)); };
			ft::pair<iterator,iterator> equal_range( const key_type& key ) { return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); };
			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const { return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); };
			size_type count( const key_type& key ) const
			{
				if (find(key) != this->end())
					return (1);
				return (0);
			};
			allocator_type get_allocator() const { return (_my_alloc); };
		protected:
			typedef typename Alloc::template rebind<Node<value_type> >::other _Alty;
			_Alty node_allocator;
			value_compare cmp;
			allocator_type _my_alloc;
			red_black_tree<value_type, _Alty, key_compare> rbt;
			
	};
}

#endif