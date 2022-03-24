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
		Iter iter;

		public:
			typedef Iter iterator_type;
			typedef typename ft::Iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::Iterator_traits<Iter>::value_type value_type;
			typedef typename ft::Iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::Iterator_traits<Iter>::pointer pointer;
			typedef typename ft::Iterator_traits<Iter>::reference reference;
			reverse_iterator() {};
			reverse_iterator (iterator_type it) : iter(it) {};
			template <class Iterator>
  			reverse_iterator (const reverse_iterator<Iterator>& rev_it) : iter(rev_it.iter) {};
			~reverse_iterator() {};

			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other )
			{ 
				this->iter = other;
				return (*this);
			};
			iterator_type base() const { return (iter); }; //offset of 1 need to be implement
			reference operator*() const
			{
				Iter cpy(iter);

				cpy--;
				return (*cpy);
			};
			reverse_iterator operator+(difference_type n) const
			{
			this->iter -= n;

			reverse_iterator<Iter> cpy(*this);
			return (cpy);
			};
			reverse_iterator& operator++()
			{
				iter--;
				return (*this);
			};
			reverse_iterator  operator++(int)
			{
				reverse_iterator<Iter> tmp;

				this->iter--;
				return (tmp);

			};
			reverse_iterator& operator+=(difference_type n)
			{
				this->iter -= n;
				return (*this);
			};
			reverse_iterator operator-(difference_type n) const
			{
				this->iter += n;

			 	reverse_iterator<Iter> cpy(*this);
			 	return (cpy);
			};
			reverse_iterator& operator--()
			{
				iter++;
				return (*this);
			};
			reverse_iterator  operator--(int)
			{
				reverse_iterator<Iter> tmp;

				this->iter++;
				return (tmp);

			};
			reverse_iterator& operator-=(difference_type n)
			{
				this->iter += n;
				return (*this);
			};
			pointer operator->() const
			{
				return &(this->operator*());
			};
			reference operator[](difference_type n) const
			{
				return (*(this->iter - (n + 1)));
			};
	};
	//Reverse iterator comparison op.
	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() == rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() != rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() > rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() >= rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() < rhs.base()); };
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() <= rhs.base()); };
}

#endif