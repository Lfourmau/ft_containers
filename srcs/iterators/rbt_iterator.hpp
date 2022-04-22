#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "../map/red_black_tree.hpp"
#include "../map/map.hpp"


enum _color
{
	RED,
	BLACK
};
template<class T>
class Node;

namespace ft
{
	template<class T>
	class rbt_iterator
	{
		public:
			rbt_iterator(Node<T> *n = nullptr) : node(n) {};
			T& operator *() { return (node->value); };
			T* operator->() { return (&(node->value)); };
			bool operator==(const rbt_iterator<T> &rhs) { return (node == rhs.node); };
			bool operator!=(const rbt_iterator<T> &rhs) { return (node != rhs.node); };
			rbt_iterator<T> &operator++()
			{
				incrementation();
				return (*this);
			}
			rbt_iterator<T> &operator++(int)
			{
				rbt_iterator tmp = this;
				incrementation();
				return (*this);
			}
			rbt_iterator<T> &operator--()
			{
				decrementation();
				return (*this);
			}
			rbt_iterator<T> &operator--(int)
			{
				rbt_iterator tmp = this;
				decrementation();
				return (*this);
			}

		private:
			void incrementation()
			{
				if (node->right)
				{
					Node<T> *tmp = node->right;
					while (tmp->left)
						tmp = tmp->left;
					node = tmp;
				}
				else
				{
					Node<T> *tmp = node->parent;
					if (tmp->right == node)
					{
						while (node == tmp->right)
						{
							node = tmp;
							tmp = tmp->parent;
						}
					}
					if (node->right != tmp)
						node = tmp;
				}
			}
			void decrementation()
			{
				if (node->parent->parent == node && node->color == RED)
					node = node->left;
				else if (node->left)
				{
					while (node->right)
						node->right;
				}
				else
				{
					Node<T> *parent = node->parent;
					while (parent->left == node)
					{
						node = parent;
						parent = parent->parent;
					}
					node = parent;
				}
			}
			Node<T> *node;
	};
}

#endif