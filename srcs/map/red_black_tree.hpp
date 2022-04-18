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
			checkColor(new_node);
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
	void checkColor(Node<K, V> node)
	{
		if (node == root)
			return;
		if (node.color == RED && node.parent.color == RED)
			correctTree(node);
		checkColor(node.parent);
	}
	void correctTree(Node<K, V> node)
	{
		if (node.parent.isleftchild) //means aunt is node.parent.parent.right
		{
			if (node.parent.parent.right == nullptr || node.parent.parent.right.color = BLACK)
				return rotate(node);
			if (node.parent.parent.right != nullptr)
				node.parent.parent.right.color = BLACK;
			node.parent.parent.color = RED;
			node.parent.color = BLACK;
			return;
		}
		//aunt is grandparent.left
		if (node.parent.parent.left == nullptr || node.parent.parent.left.color = BLACK)
			return rotate(node);
		if (node.parent.parent.left != nullptr)
			node.parent.parent.left.color = BLACK;
		node.parent.parent.color = RED;
		node.parent.color = BLACK;
		return;
	}
	void rotate(Node<K, V> node)
	{
		if (node.isleftchild)
		{
			if (node.parent.isleftchild)
			{
				rightRotate(node.parent.parent);
				node.color = RED;
				node.parent.color = BLACK;
				if (node.parent.right != nullptr)
					node.parent.right.color = RED;
				return;
			}
			rightLeftRotate(node.parent.parent);
			node.color = BLACK;
			node.right.color = RED;
			node.left.color = RED;
			return;
		}
		if (node.parent.isleftchild)
		{
			leftRotate(node.parent.parent);
			node.color = RED;
			node.parent.color = BLACK;
			if (node.parent.left != nullptr)
				node.parent.left.color = RED;
			return;
		}
		leftRightRotate(node.parent.parent);
		node.color = BLACK;
		node.right.color = RED;
		node.left.color = RED;
		return;
	}
	void leftRotate(Node<K, V> node)
	{
		Node<K, V> tmp = node.right;

		node.right = tmp.left;
		if (node.right != nullptr)
		{
			node.right.parent = node;
			node.right.isleftchild = false;
		}
		if (node.parent == nullptr)
		{
			//we are on root node
			root = tmp;
			tmp.parent = nullptr;
		}
		else
		{
			tmp.parent = node.parent;
			if (node.isleftchild)
			{
				tmp.isleftchild = true;
				tmp.parent.left = tmp;
			}
			else
			{
				tmp.isleftchild = false;
				tmp.parent.right = tmp;
			}
			tmp.left = node;
			node.isleftchild = true;
			node.parent = tmp;
		}
	}
	void rightRotate(Node<K, V> node)
	{
		//need to invers rght and left
		Node<K, V> tmp = node.right;

		node.right = tmp.left;
		if (node.right != nullptr)
		{
			node.right.parent = node;
			node.right.isleftchild = false;
		}
		if (node.parent == nullptr)
		{
			//we are on root node
			root = tmp;
			tmp.parent = nullptr;
		}
		else
		{
			tmp.parent = node.parent;
			if (node.isleftchild)
			{
				tmp.isleftchild = true;
				tmp.parent.left = tmp;
			}
			else
			{
				tmp.isleftchild = false;
				tmp.parent.right = tmp;
			}
			tmp.left = node;
			node.isleftchild = true;
			node.parent = tmp;
		}
	}
	void leftRightRotate(Node<K, V> node)
	{
		leftRotate(node.left);
		rightRotate(node);
	}
	void rightLeftRotate(Node<K, V> node)
	{
		riightRotate(node.right);
		leftRotate(node);
	}
	int height()
	{
		if (root == nullptr)
			return (0);
		return (height(root) - 1);
	}
	int height(Node<K, V> node)
	{
		if (node == nullptr)
			return (0);
		int leftHeight = height(node.left) + 1;
		int rightHeight = height(node.right) + 1;
		if (leftHeight > rightHeight)
			return (leftHeight);
		return (rightHeight);
	}
	int blackNodes(Node<K, V> node)
	{
		if (node == null)
			return (1);
		int rightBlackNodes = blackNodes(node.right);
		int leftBlackNodes = blackNodes(node.left);
		if (rightBlackNodes != leftBlackNodes)
			//throw error or fix the tree
		if (node.color = BLACK)
			leftBlackNodes++;
		return (leftBlackNodes);
	}
};


#endif