#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector>
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
		typedef pointer 									iterator;
		typedef ft::reverse_iterator<iterator>	 			reverse_iterator;
		typedef const_pointer								const_iterator;
		typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;

		private:
			T 				*_data;
			size_t 			_capacity;
        	size_t 			_size;
			allocator_type 	_my_alloc;

		public :
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
			// Vector (const Vector& x);
			// ~Vector() {};

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
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);

			//Elements access
			reference operator[] (size_type n) { return (_data[n]); };
			const_reference operator[] (size_type n) const;
		//	reference at (size_type n) { return (data[n]); };
			const_reference at (size_type n) const;
		//	reference front() { return (this->data[0]); };
			const_reference front() const;
			//reference back() { return (this->data[size]); };
			const_reference back() const;

			//Modifiers
			template <class InputIterator>
  				void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val)
			{
				T *data_tmp = this->_data;
				if (this->_size == this->_capacity)
				{
					_data = this->_my_alloc.allocate(_size * 2);
					std::copy(data_tmp, data_tmp + _size, _data);
					_my_alloc.construct(_data + _size, val); //before increment size, because size is equal to the number of element, not the index
					this->_size++;
					this->_capacity *= 2;
				}
				else
				{
					std::copy(data_tmp, data_tmp + _size, _data);
					this->_data[_size] = val; //before increment size, because size is equal to the number of element, not the index
					this->_size++;
				}
			};
			void pop_back()
			{
				_my_alloc.destroy(_data + _size);
				this->_size--;
			};
			iterator insert (iterator position, const value_type& val)
			{
				T  *data_tmp = this->_data;

				if (this->_size == this->capacity)
				{
					_data = this->_my_alloc.allocate(_size * 2);
					this->_capacity *= 2;
				}
				std::copy(data_tmp, data_tmp + (position - 2), _data);
				_my_alloc.construct(_data + (position - 1), val);
				std::copy(data_tmp + position, data_tmp + _size, _data);
				return (_data + (position - 1));
			};
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    			void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (Vector& x)
			{
				T *tmp;
	
				tmp = x.begin();
				x._data = this->_data;
				this->_data = tmp;
			};
			void clear();

			//Allocator
			allocator_type get_allocator() const;

			//Reltionnal operators
	};
}

#endif