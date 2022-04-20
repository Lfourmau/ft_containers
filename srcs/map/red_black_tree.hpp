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
		Node(T &data)
		{
			parent = left = right = nullptr;
			value = data;
			color = RED;
		};
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
				Node<Pair> *n = this->root;
				if (this->root == nullptr)
				{
					this->root = new_node(value);
					this->root->color = BLACK;
					std::cout << "[" << this->root->value.first << " -- ";
					std::cout << this->root->value.second << "]" << std::endl;
					this->current = this->root;
				}
				else if (cmp < 0)
				{
					//left
					//insert as leaf
					if (n->left == nullptr)
					{
						n->value = value;
						return;
					}
					else
						n = n->left;
					//check parent color
					std::cout << "[" << this->current->value.first << " -- ";
					std::cout << this->current->value.second << "]" << std::endl;
				}
				else if (cmp > 0)
				{
					//right
					if (n->right == nullptr)
					{
						n->value = value;
						return;
					}
					else
						n = n->right;
				};
			};
		private:
			Compare comp;
			Alloc _my_alloc;
			Node<Pair> *root;
			Node<Pair> *current;
			Node<Pair> *new_node(Pair value)
			{
				Node<Pair> *node = _my_alloc.allocate(1);
				_my_alloc.construct(&node->value, value);
				return (node);
			};
	};
}


#endif