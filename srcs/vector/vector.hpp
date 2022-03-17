#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <memory>
#include <algorithm>
#include "../iterators/iterator_traits.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class Vector
	{
		public :
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::size_type 			size_type;
			typedef pointer 								iterator;
			typedef ft::reverse_iterator<iterator>	 			reverse_iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
			Vector () : _data(nullptr), _capacity(0), _size(0) {};
			Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_my_alloc = alloc;
				_data = _my_alloc.allocate(n);
				_size = n;
				_capacity = n;
				for (size_t i = 0; i < n; i++)
					_my_alloc.construct(_data + i, val);
				
			};
			void print()
			{
				for (size_t i = 0; i < this->_size; i++)
					std::cout << _data[i] << "---";
				std::cout << std::endl;
			};
			// template <class InputIterator>
         	// 	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			Vector (const Vector& x)
			{
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_my_alloc = allocator_type();
				this->_data = _my_alloc.allocate(this->_size);
				for (size_t i = 0; i < _size; i++)
					_my_alloc.construct(_data + i, *(x._data + i));
			};
			~Vector() {};

			//Iterators
			Vector& 				operator=(Vector const& rhs);
			iterator 				begin() { return (_data); };
			const_iterator 			begin() const;
			iterator 				end() { return (&_data[_size]); };
			const_iterator end() const;
			reverse_iterator rbegin() { return end(); };
			const_reverse_iterator rbegin() const;
			reverse_iterator rend() { return begin(); };
			const_reverse_iterator rend() const;

			//Capacity
			size_type size() const { return (this->_size); };
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					while (this->_size > n)
						this->pop_back();
				}
				else if (n > this->_size)
				{
					if (this->_capacity < n)
						this->reserve(n);
					while (this->_size < n)
						this->push_back(val);
				}
			};
			size_type capacity() const { return (this->_capacity); };
			bool empty() const { return(this->_size == 0); };
			void reserve (size_type n)
			{
				if (n > this->_capacity)
				{
					Vector tmp(*this);
					this->_data = this->_my_alloc.allocate(n);
					std::copy(tmp.begin(), tmp.begin() + tmp._size, this->_data);
					this->_capacity = n;
				}
			};

			//Elements access
			reference operator[] (size_type n) { return (_data[n]); };
			const_reference operator[] (size_type n) const;
			reference at (size_type n) { return (this->_data[n]); };
			const_reference at (size_type n) const;
			reference front() { return (this->data[0]); };
			const_reference front() const;
			reference back() { return (this->data[_size]); };
			const_reference back() const;

			//Modifiers
			//template <class InputIterator>
  			//	void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				reserve(n);
				while (this->_size < n)
					this->push_back(val);
			};
			void push_back (const value_type& val)
			{
				this->insert(this->end(), val);
			};
			void pop_back()
			{
				_my_alloc.destroy(_data + _size);
				this->_size--;
			};
			iterator insert (iterator position, const value_type& val)
			{
				int i = this->_size;
				T* tmpo = _data;
			
				if (this->_size == this->_capacity)
					this->reserve(std::max(this->_capacity * 2, static_cast<size_t>(1)));
				while (&tmpo[i] != position)
				{
					_data[i] = tmpo[i - 1];
					i--;
				}
				_data[i] = val;
				i--;
				while (i > 0)
				{
					_data[i] = tmpo[i];
					i--;
				}
				this->_size++;
				return (position);
			};
			//void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->insert(position, *first);
					position++;
					first++;
				}
			};
			iterator erase (iterator position)
			{
				if (position == this->end())
					return (this->end());

				size_t i = 0;
				Vector tmp(*this);

				while (&_data[i] <= position)
					i++;
				this->resize(i);
				this->pop_back();
				while (i < tmp._size)
				{
					this->push_back(tmp._data[i]);
					i++;
				}
				return (position);
			};
			iterator erase (iterator first, iterator last);
			void swap (Vector& x)
			{
				T *tmp;
	
				tmp = x.begin();
				x._data = this->_data;
				this->_data = tmp;
			};
			void clear()
			{
				while (this->_size > 0)
					this->pop_back();
			};

			//Allocator
			allocator_type get_allocator() const { return (this->_my_alloc); };

			//Reltionnal operators

			private:
				T 				*_data;
				size_t 			_capacity;
				size_t 			_size;
				allocator_type 	_my_alloc;
				void	copy(T *input_begin, T *input_end, T *output)
				{
					size_t i = 0;
					while (input_begin != input_end)
					{
						output[i] = *input_begin;
						input_begin++;
						i++;
					}
				};
	};
}

#endif