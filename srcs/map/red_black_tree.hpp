#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "map.hpp"
namespace ft
{
	enum node_color {
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
			red_black_tree(Compare cmp, Alloc alloc) : comp(cmp), _my_alloc(alloc) {};
			//void insert(const Pair& value)
			//{
			//	//root = new_node(value);
			//	//std::cout << root->value.first;
			//	//std::cout << root->value.second;
			//};
		private:
			Node<Pair> *root;
			Compare comp;
			Alloc _my_alloc;
			Node<Pair> *new_node(Pair value)
			{
				Node<Pair> *node = _my_alloc.allocate(1);
				_my_alloc.construct(&node->data, value);
				return (node);
			};
	};
}


#endif