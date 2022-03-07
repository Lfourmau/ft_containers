#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
	template <class Iter>
	struct Iterator_traits
	{
		typedef typename Iter::difference_type 		difference_type;
		typedef typename Iter::value_type 			value_type;
		typedef typename Iter::pointer 				pointer;
		typedef typename Iter::reference 			reference;
		typedef typename Iter::iterator_category 	iterator_category;
	};
	template <class Iter>
	struct Iterator_traits<Iter*>
	{
		typedef typename Iter::difference_type 		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};
	template <class Iter>
	struct Iterator_traits<const Iter*>
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <class Iter>
	class reverse_iterator
	{
		typedef typename ft::Iterator_traits<Iter>::iterator_category iterator_type;
		typedef typename ft::Iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::Iterator_traits<Iter>::value_type value_type;
		typedef typename ft::Iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::Iterator_traits<Iter>::pointer pointer;
		typedef typename ft::Iterator_traits<Iter>::reference reference;

		reverse_iterator() {};
		~reverse_iterator() {};

		iterator_type base() {};
		reverse_iterator& operator*(reverse_iterator const& rhs);
		reverse_iterator& operator+(reverse_iterator const& rhs);
		reverse_iterator& operator++(reverse_iterator const& rhs);
		reverse_iterator& operator+=(reverse_iterator const& rhs);
		reverse_iterator& operator-(reverse_iterator const& rhs);
		reverse_iterator& operator--(reverse_iterator const& rhs);
		reverse_iterator& operator-=(reverse_iterator const& rhs);
		//reverse_iterator& operator->(reverse_iterator const& rhs);
		reverse_iterator& operator[](reverse_iterator const& rhs);
	};
}

#endif