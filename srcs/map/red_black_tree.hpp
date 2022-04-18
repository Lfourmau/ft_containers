#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

enum node_color {
  RED,
  BLACK
};

//struct Node
//{
//  int			data;
//  Node 			*parent;
//  Node 			*left;
//  Node 			*right;
//  node_color	color;
//};

template<class K, class V>
class red_black_tree
{
	private:
		int _size;
		Node<K,V> root;
		void add(Node<K, V> parent, Node<K, V> new_node)
		{
			if (Compare(new_node.key) > Compare(parent.key))
			{
				if (parent.right == nullptr)
				{
					parent.right = new_node;
					new_node.parent = parent;
					new_node.isleftchild = false;
					return;
				}
				return (add(parent.right, new_node));
			}
			if (parent.left == nullptr)
			{
				parent.left = new_node;
				new_node.parent = parent;
				new_node.isleftchild = true;
				return;
			}
			return (add(parent.left, new_node));
			//checkColor
		};

	public:
	class Node<K,V>
	{
		public:
			Node(K key, V value)
			{
				this->key = key;
				this->value = value;
				this->color = RED;
				this->left = nullptr;
				this->right = nullptr;
				this->parent = nullptr;
				this->isleftchild = false;
			};
			K 			key;
			V 			value;
			Node<K,V>	*parent;
			Node<K,V>	*left;
			Node<K,V>	*right;
			node_color	color;
			bool		isleftchild;
	};

	void add(K key, V value)
	{
		Node<K, V> node = new Node<K, V>(key, value);

		if (root == nullptr)
		{
			root = node;
			root.color = BLACK;
			_size++;
			return ();
		}
		add(root, node);
		_size++;
	};
};


#endif