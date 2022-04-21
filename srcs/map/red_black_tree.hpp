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
		Node(const T &data) : parent(nullptr), left(nullptr), right(nullptr), value(data), color(RED) {};
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
			void printBT()
			{
				Node<Pair> *node = root;
				printBT("", node, false);
			}
			red_black_tree(Compare cmp, Alloc alloc) : comp(cmp), _my_alloc(alloc), root(nullptr) {};
			void insert(const Pair& value)
			{
				Node<Pair> *n = this->root;
				if (this->root == nullptr)
				{
					this->root = new_node(value);
					this->root->color = BLACK;
					return ;
				}
				while(n !=  nullptr)
				{
					if (comp(n->value, value) <= 0)
					{
						n = n->left;
					}
					else
					{
						n = n->right;
					}
				}
				n = new_node(value);
				std::cout << n->value.first;
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



		void printBT(const std::string& prefix, const Node<Pair>* node, bool isLeft)
		{
			if( node != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──L:" : "└──R:" );

				// print the value of the node
				std::cout << node->value.first << " -- ";
				std::cout << node->value.second << "]" << std::endl;

				// enter the next tree level - left and right branch
				printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}
	};
}


#endif