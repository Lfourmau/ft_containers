#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <memory>
#include <algorithm>
#include <type_traits>
#include "../iterators/iterator_traits.hpp"

namespace ft
{
	template<class T, T v>
  	struct integral_constant {
      	static const T value = v;
      	typedef T value_type;
      	typedef integral_constant type;
    	operator value_type() const { return value; };
    	const value_type operator()() const { return value; };
  	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type{};
	template <>
	struct is_integral<bool> : public true_type{};
	template <>
	struct is_integral<char> : public true_type{};
	template <>
	struct is_integral<signed char> : public true_type{};
	template <>
	struct is_integral<unsigned char> : public true_type{};
	template <>
	struct is_integral<wchar_t> : public true_type{};
	template <>
	struct is_integral<short> : public true_type{};
	template <>
	struct is_integral<int> : public true_type{};
	template <>
	struct is_integral<long> : public true_type{};
	template <>
	struct is_integral<long long> : public true_type{};
	template <>
	struct is_integral<unsigned short> : public true_type{};
	template <>
	struct is_integral<unsigned int> : public true_type{};
	template <>
	struct is_integral<unsigned long> : public true_type{};
	template <>
	struct is_integral<unsigned long long> : public true_type{};


	template<bool B, class T = void>
    struct enable_if {};
    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public :
			class vec_it;
			class const_vec_it;
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef typename allocator_type::const_pointer 		const_pointer;
			typedef typename allocator_type::size_type 			size_type;
			typedef vec_it 										iterator;
			typedef ft::reverse_iterator<iterator>	 			reverse_iterator;
			typedef const_vec_it								const_iterator;
			typedef ft::reverse_iterator<const_iterator> 		const_reverse_iterator;
			vector () : _data(NULL), _capacity(0), _size(0), _my_alloc(Alloc()) {};
			vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
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
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			 	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				_data = NULL;
				_size = 0;
				_capacity = 0;
				_my_alloc = alloc;
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			};
			vector (const vector& x)
			{
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_my_alloc = x._my_alloc;
				this->_data = _my_alloc.allocate(x._capacity);
				for (size_t i = 0; i < _size; i++)
					_my_alloc.construct(_data + i, *(x._data + i));
			};
			~vector() 
			{
				for (size_t i = 0; i < this->_size; i++)
					_my_alloc.destroy(_data + i);
				_my_alloc.deallocate(this->_data, this->capacity());
			};

			//Iterators
			vector& operator=(vector const& rhs)
			{
				if (rhs == *this)
					return (*this);
				this->clear();
				this->insert(this->end(), rhs.begin(), rhs.end());
				return (*this);
			};
			iterator 				begin() { return iterator(this, 0); };
			const_iterator 			begin() const { return const_iterator(this, 0); };
			iterator 				end() { return iterator(this, this->_size); };
			const_iterator			end() const { return const_iterator(this, this->_size); };
			reverse_iterator		rbegin() { return (end()); };
			const_reverse_iterator	rbegin() const { return (end()); };
			reverse_iterator		rend() { return (begin()); };
			const_reverse_iterator	rend() const { return (begin()); };

			//Capacity
			size_type size() const { return (this->_size); };
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(value_type)); };
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
						this->reserve(capacity_check(n));
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
					vector tmp(*this);
					if (this->_data)
						_my_alloc.deallocate(this->_data, this->_capacity);
					this->_data = this->_my_alloc.allocate(n);
					this->_capacity = n;
					copy(tmp.begin(), tmp.begin() + tmp._size, this->_data);
				}
			};

			//Elements access
			reference 		operator[] (size_type n) { return (_data[n]); };
			const_reference operator[] (size_type n) const { return (_data[n]); };
			reference 		at (size_type n)
			{ 
				if (n < 0 || n >= this->size())
					throw(std::out_of_range("vector"));
				return (this->_data[n]); 
			};
			const_reference at (size_type n) const
			{ 
				if (n < 0 || n >= this->size())
					throw(std::out_of_range("vector"));
				return (this->_data[n]); 
			};
			reference 		front() { return (this->_data[0]); };
			const_reference front() const { return (this->data[0]); };
			reference 		back() { return (this->_data[_size - 1]); };
			const_reference back() const { return (this->_data[_size - 1]); };

			//Modifiers
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last, 
			  	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				this->clear();
				while (first != last)
				{
					this->reserve(this->_size + 1);
					this->push_back(*first);
					first++;
				}
			};
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				reserve(n);
				while (this->_size < n)
					this->push_back(val);
			}
			void push_back( const T& value )
			{
				this->reserve(this->capacity_check(_size + 1));
				_my_alloc.construct( _data + _size, value );
				_size++;
			}
			void pop_back()
			{
				_my_alloc.destroy(this->_data + _size);
				this->_size--;
			};
			iterator insert (iterator position, const value_type& val)
			{
				this->reserve(this->capacity_check(this->_size + 1));
				for (iterator it = this->end(); it != position; --it)
					*it = *(it - 1);
				*position = val;
				this->_size++;
				return (position);
			};
			void insert (iterator position, size_type n, const value_type& val)
			{
				this->reserve(this->capacity_check(this->_size + n));
				for (size_t i = 0; i < n; i++)
				{
					for (iterator it = this->end(); it != position; --it)
						*it = *(it - 1);
					*position = val;
					this->_size++;
					position++;
				}
			};
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
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
				for (iterator it = position; it != this->end(); it++)
					*it = *(it + 1);
				this->_size--;
				return (position);
			};
			iterator erase (iterator first, iterator last)
			{
				for (iterator it = first; it != last; it++)
					this->erase(first);
				return (last);
			};
			void swap (vector<T>& x)
			{
				std::swap(_data, x._data);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_size, x._size);
				std::swap(this->_my_alloc, x._my_alloc);
			};
			void clear()
			{
				while (this->_size > 0)
					this->pop_back();
			};

			//Allocator
			allocator_type get_allocator() const { return (this->_my_alloc); };

			class vec_it : public std::iterator<std::random_access_iterator_tag, value_type> 
			{
				private:
					const vector *vp;
					int index;

				public:

					vec_it() { this->vp = NULL; };
					vec_it(const vec_it & it) { this->vp = it.vp; this->index = it.index; };
					vec_it(const vector *vp, int index) { this->vp = vp; this->index = index; };
					vec_it & operator++() {
						index++;
						return *this;
					}
					vec_it operator++(int) {
						vec_it copy(*this);
						this->operator++();
						return copy;
					}
					vec_it & operator--() {
						index--;
						return *this;
					}
					vec_it operator--(int) {
						vec_it copy(*this);
						operator--();
						return copy;
					}
					vec_it&	operator=(vec_it const& rhs)
					{
						this->vp = rhs.vp;
						this->index = rhs.index;
						return (*this);
					}
					bool operator==(const vec_it & rhs) const { return vp == rhs.vp && index == rhs.index; };
					bool operator!=(const vec_it & rhs) const { return !(*this == rhs); };
					bool operator<(const vec_it & rhs) const{ return index < rhs.index; };
					bool operator<=(const vec_it & rhs) const { return index <= rhs.index; };
					bool operator>(const vec_it & rhs) const{ return index > rhs.index; };
					bool operator>=(const vec_it & rhs) const { return index >= rhs.index; };
					vec_it operator+(const int & rhs) const { return vec_it(vp, index + rhs); };
					vec_it operator-(const int & rhs) const { return vec_it(vp, index - rhs); };
					vec_it operator+=(const int & rhs) {
						index += rhs;
						return *this;
					};
					vec_it operator-=(const int & rhs) {
						index -= rhs;
						return *this;
					};
					int operator-(const vec_it & rhs) { return index - rhs.index; };
					value_type & operator*() { return (vp->_data[index]); };
					value_type *operator->() { return &vp->_data[index]; };
					value_type & operator[](int k) { return vp->_data[index + k]; };
			};

			class const_vec_it : public std::iterator<std::random_access_iterator_tag, value_type> 
			{
				private:
					const vector *vp;
					int index;

				public:
					typedef const value_type& reference;
					const_vec_it() { this->vp = NULL; };
					const_vec_it(const const_vec_it & it) { this->vp = it.vp; this->index = it.index; };
					const_vec_it(const vector *vp, int index) { this->vp = vp; this->index = index; };
					const_vec_it & operator++() {
						index++;
						return *this;
					}
					const_vec_it operator++(int) {
						const_vec_it copy(*this);
						operator++();
						return copy;
					}
					const_vec_it & operator--() {
						index--;
						return *this;
					}
					const_vec_it operator--(int) {
						const_vec_it copy(*this);
						operator--();
						return copy;
					}
					const_vec_it&	operator=(const_vec_it const& rhs)
					{
						this->vp = rhs.vp;
						this->index = rhs.index;
						return (*this);
					}
					bool operator==(const const_vec_it & rhs) const { return vp == rhs.vp && index == rhs.index; };
					bool operator!=(const const_vec_it & rhs)  const { return !(*this == rhs); };
					bool operator<(const const_vec_it & rhs) const{ return index < rhs.index; };
					bool operator<=(const const_vec_it & rhs)const { return index <= rhs.index; };
					bool operator>(const const_vec_it & rhs) const{ return index > rhs.index; };
					bool operator>=(const const_vec_it & rhs) const { return index >= rhs.index; };
					const_vec_it operator+(const int & rhs) const { return const_vec_it(vp, index + rhs); };
					const_vec_it operator-(const int & rhs) const { return const_vec_it(vp, index - rhs); };
					const_vec_it operator+=(const int & rhs) {
						index += rhs;
						return *this;
					}
					const_vec_it operator-=(const int & rhs) {
						index -= rhs;
						return *this;
					}
					int operator-(const const_vec_it & rhs) const { return index - rhs.index; };
					value_type const & operator*() const { return vp->_data[index]; };
					value_type const *operator->() const { return &vp->_data[index]; };
					value_type const & operator[](int k) const { return vp->_data[index + k]; };
			};

			private:
				T 				*_data;
				size_t 			_capacity;
				size_t 			_size;
				allocator_type 	_my_alloc;
				void	copy(iterator input_begin, iterator input_end, T* output)
				{
					size_t i = 0;
					while (input_begin != input_end)
					{
						_my_alloc.construct(&output[i], *input_begin);
						input_begin++;
						i++;
					}
				};
				size_t capacity_check(size_type needed)
				{
					if (needed > this->_capacity * 2)
						return (needed);
					else if (needed > this->_capacity)
						return (this->_capacity * 2);
					else
						return 0;
				}
	};
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
    	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
    	    if (comp(*first1, *first2)) return true;
    	    if (comp(*first2, *first1)) return false;
    	}
    	return (first1 == last1) && (first2 != last2);
	}


	template< class T, class Alloc >
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T>::const_iterator lit = lhs.begin();
		typename ft::vector<T>::const_iterator rit = rhs.begin();

		while (lit != lhs.end() && rit != rhs.end())
		{
			if (*lit != *rit)
				return (false);
			lit++;
			rit++;
		}
		return (true);
	};
	template< class T, class Alloc >
	bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	};
	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return ((lhs == rhs) || (lhs < rhs));
	};
	template< class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs <= rhs));
	};
	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	};
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	};
}

#endif