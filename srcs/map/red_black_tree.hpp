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
		Node *root;
		Alloc _my_alloc;
		Node *new_node(Pair value)
		{
			Node *node = _my_alloc.allocate(sizeof(Node));
			_struct(&node->data, value);
			return (node);
		};
};


#endif