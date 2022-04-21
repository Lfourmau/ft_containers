#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "map.hpp"
namespace ft
{
	enum node_color
	{
		RED,
		BLACK
	};

	template<class T>
	struct Node
	{
		Node(const T &data)
		{
			parent = left = right = nullptr;
			value = data;
			color = RED;
		};
		Node(const Node& other)
		{
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
			this->value = other.value;
			this->color = other.color;
		}
		Node 		*parent;
		Node 		*left;
		Node 		*right;
		T 			value;
		node_color	color;
	};

	template<class Pair, class Alloc, class Compare>
	class red_black_tree
	{
		public:
			red_black_tree(Compare cmp, Alloc alloc) : comp(cmp), _my_alloc(alloc), root(nullptr) {};
			void insert(const Pair& value)
			{
				//Node<Pair> *n = this->root;
				if (this->root == nullptr)
				{
					this->root = new_node(value);
					this->root->color = BLACK;
					std::cout << "[" << this->root->value.first << " -- ";
					std::cout << this->root->value.second << "]" << std::endl;
				}
			};
		private:
			Compare comp;
			Alloc _my_alloc;
			Node<Pair> *root;
			Node<Pair> *new_node(const Pair& value)
			{
				Node<Pair> *node = _my_alloc.allocate(1);
				_my_alloc.construct(node, value);
				return (node);
			};
	};
}


#endif