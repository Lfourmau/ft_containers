#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

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

template<class Pair, class Alloc>
class red_black_tree
{
	private:
		Node<Pair> *root;
		Alloc _my_alloc;
		Node<Pair> *new_node(Pair value)
		{
			Node<Pair> *node = _my_alloc.allocate();
			_my_alloc.construct(&node->data, value);
			return (node);
		};
};


#endif