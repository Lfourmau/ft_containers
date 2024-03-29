#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		protected :
			Container _data;
			template <class U, class Containr>
			friend bool operator== (const ft::stack<U, Containr>& lhs, const ft::stack<U, Containr>& rhs);
			template <class U, class Containr>
  			friend bool operator!= (const ft::stack<U, Containr>& lhs, const ft::stack<U, Containr>& rhs);
			template <class U, class Containr>
  			friend bool operator<  (const ft::stack<U, Containr>& lhs, const ft::stack<U, Containr>& rhs);
			template <class U, class Containr>
  			friend bool operator<= (const ft::stack<U, Containr>& lhs, const ft::stack<U, Containr>& rhs);
			template <class U, class Containr>
  			friend bool operator>  (const ft::stack<U, Containr>& lhs, const ft::stack<U, Containr>& rhs);
			template <class U, class Containr>
  			friend bool operator>= (const ft::stack<U, Containr>& lhs, const ft::stack<U, Containr>& rhs);
		public :
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
			explicit stack(const Container& cont = Container()) : _data(cont) {};
			~stack() {};
			bool empty() const { return (_data.empty()); };
			size_type size() const {return (_data.size()); };
			value_type& top() { return (_data.back()); };
			const value_type& top() const { return (_data.back()); };
			void push (const value_type& val) { _data.push_back(val); };
			void pop() { _data.pop_back(); };
	};

	template <class T, class Container>
  	bool operator== (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return (lhs._data == rhs._data); };
	template <class T, class Container>
  	bool operator!= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return (lhs._data != rhs._data); };
	template <class T, class Container>
  	bool operator<  (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return (lhs._data < rhs._data); };
	template <class T, class Container>
  	bool operator<= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return (lhs._data <= rhs._data); };
	template <class T, class Container>
  	bool operator>  (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return (lhs._data > rhs._data); };
	template <class T, class Container>
  	bool operator>= (const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) { return (lhs._data >= rhs._data); };
}
#endif