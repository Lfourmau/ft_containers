#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <class T>
	class Stack
	{
		private :
			Vector<T> _data;
			template <class U>
			friend bool operator== (const ft::Stack<U>& lhs, const ft::Stack<U>& rhs);
			template <class U>
  			friend bool operator!= (const ft::Stack<U>& lhs, const ft::Stack<U>& rhs);
			template <class U>
  			friend bool operator<  (const ft::Stack<U>& lhs, const ft::Stack<U>& rhs);
			template <class U>
  			friend bool operator<= (const ft::Stack<U>& lhs, const ft::Stack<U>& rhs);
			template <class U>
  			friend bool operator>  (const ft::Stack<U>& lhs, const ft::Stack<U>& rhs);
			template <class U>
  			friend bool operator>= (const ft::Stack<U>& lhs, const ft::Stack<U>& rhs);
		public :
			typedef T value_type;
			typedef Vector<T> container_type;
			typedef size_t size_type;
			Stack() : _data() {};
			~Stack() {};
			Vector<T> get_data() const {return (_data); };
			bool empty() const { return (_data.empty()); };
			size_type size() const {return (_data.size()); };
			value_type& top() { return (_data.back()); };
			const value_type& top() const { return (_data.back()); };
			void push (const value_type& val) { _data.push_back(val); };
			void pop() { _data.pop_back(); };
	};

	template <class T>
  	bool operator== (const ft::Stack<T>& lhs, const ft::Stack<T>& rhs) { return (lhs._data == rhs._data); };
	template <class T>
  	bool operator!= (const ft::Stack<T>& lhs, const ft::Stack<T>& rhs) { return (lhs._data != rhs._data); };
	template <class T>
  	bool operator<  (const ft::Stack<T>& lhs, const ft::Stack<T>& rhs) { return (lhs._data < rhs._data); };
	template <class T>
  	bool operator<= (const ft::Stack<T>& lhs, const ft::Stack<T>& rhs) { return (lhs._data <= rhs._data); };
	template <class T>
  	bool operator>  (const ft::Stack<T>& lhs, const ft::Stack<T>& rhs) { return (lhs._data > rhs._data); };
	template <class T>
  	bool operator>= (const ft::Stack<T>& lhs, const ft::Stack<T>& rhs) { return (lhs._data >= rhs._data); };
}
#endif