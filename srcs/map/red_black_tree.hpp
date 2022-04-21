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
				Node<Pair> *inserted = new_node(value);
				if (this->root == nullptr)
				{
					this->root = inserted;
					this->root->color = BLACK;
					inserted->parent = n;
					return ;
				}
				while(n != nullptr)
				{
					if (comp(n->value, value) <= 0)
					{
						if (n->left == nullptr)
						{
							n->left = inserted;
							break;
						}
						else
							n = n->left;
					}
					else
					{
						if (n->right == nullptr)
						{
							n->right = inserted;
							break;
						}
						else
							n = n->right;
					}
				}
				inserted->parent = n;
				std::cout << inserted->value.first << std::endl;
				fix_tree(inserted);
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
			void left_rotate(Node<Pair> *node)
			{
				Node<Pair> *n = node->right;
				node->right = n->left;
				if (n->left != nullptr)
					n->left->parent = node;
				n->parent = node->parent;
				if (node->parent == nullptr)
					this->root = n;
				else if (node == node->parent->left)
					node->parent->left = n;
				else
					node->parent->right = n;
				n->left = node;
				node->parent = n;
			}
			void right_rotate(Node<Pair> *node)
			{
				Node<Pair> *n = node->left;
				node->left = n->right;
				if (n->right != nullptr)
					n->right->parent = node;
				n->parent = node->parent;
				if (node->parent == nullptr)
					this->root = n;
				else if (node == node->parent->right)
					node->parent->right = n;
				else
					node->parent->left = n;
				n->right = node;
				node->parent = n;
			}
			void fix_tree(Node<Pair> *node)
			{
				while (node != root && node->parent->color == RED)
				{
					if (node->parent == node->parent->parent->left)
					{
						Node<Pair> *n = node->parent->parent->right;
						if (n && n->color == RED)
						{
							node->parent->color = BLACK;
							n->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->right)
							{
								node = node->parent;
								left_rotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							right_rotate(node->parent->parent);
						}
					}
					else
					{
						Node<Pair> *n = node->parent->parent->left;
						if (n && n->color == RED)
						{
							node->parent->color = BLACK;
							n->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->left)
							{
								node = node->parent;
								right_rotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							left_rotate(node->parent->parent);
						}
					}
				}
				this->root->color = BLACK;
			};


		void printBT(const std::string& prefix, const Node<Pair>* node, bool isLeft)
		{
			if( node != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──L:" : "└──R:" );

				// print the value of the node
				if (node->color == RED)
				{
					std::cout << "\033[31m[" << node->value.first << " -- ";
					std::cout << node->value.second << "]\033[0m" << std::endl;
				}
				else
				{
					std::cout << "[" << node->value.first << " -- ";
					std::cout << node->value.second << "]" << std::endl;
				}

				// enter the next tree level - left and right branch
				printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}
	};
}


#endif