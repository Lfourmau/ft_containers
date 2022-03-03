#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

template <class iterator>
struct Iterator_traits
{
	typedef typename iterator::difference_type 		difference_type;
	typedef typename iterator::value_type 			value_type;
	typedef typename iterator::pointer 				pointer;
	typedef typename iterator::reference 			reference;
	typedef typename iterator::iterator_category 	iterator_category;
};
template <class iterator>
struct Iterator_traits<iterator*>
{
	typedef typename iterator::difference_type 		difference_type;
	typedef typename iterator::value_type			value_type;
	typedef typename iterator::pointer				pointer;
	typedef typename iterator::reference			reference;
	typedef typename iterator::iterator_category	iterator_category;
};
template <class iterator>
struct Iterator_traits<const iterator*>
{
	typedef typename iterator::difference_type		difference_type;
	typedef typename iterator::value_type			value_type;
	typedef typename iterator::pointer				pointer;
	typedef typename iterator::reference			reference;
	typedef typename iterator::iterator_category	iterator_category;
};

#endif