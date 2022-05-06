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
	class Node
	{
		public:
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

	
	template<class T, class Alloc, class Compare>
	class red_black_tree
	{
		public:
			//ITERATOR
			template<class U>
			class rbt_iterator : public std::iterator<std::bidirectional_iterator_tag, U>
			{
				public:
					rbt_iterator();
					rbt_iterator(Node<U> *n) : node(n) {};
					U& operator *() { return (node->value); };
					Node<U> *base() { return (node); };
					U* operator->() { return (&(node->value)); };
					rbt_iterator<U> &operator=(const rbt_iterator<U> &rhs)
					{
						this->node = rhs.node;
						return (*this);
					};
					bool operator==(const rbt_iterator<U> &rhs) { return (node == rhs.node); };
					bool operator!=(const rbt_iterator<U> &rhs) { return (node != rhs.node); };
					rbt_iterator<U> &operator++()
					{
						incrementation();
						return (*this);
					}
					rbt_iterator<U> &operator++(int)
					{
						rbt_iterator<U> *tmp = this;
						incrementation();
						return (*tmp);
					}
					rbt_iterator<U> &operator--()
					{
						decrementation();
						return (*this);
					}
					rbt_iterator<U> &operator--(int)
					{
						rbt_iterator<U> *tmp = this;
						decrementation();
						return (*tmp);
					}

				private:
					void incrementation()
					{
						if (node->right)
						{
							node = node->right;
							while (node->left)
								node = node->left;
						} 
						else
						{
							while (node->parent && node->parent->right == node)
								node = node->parent;
							node = node->parent;
						}
					}
					void decrementation()
					{
						if (node->left)
						{
							node = node->left;
							while (node->right)
								node = node->right;
						}
						else
						{
							Node<U> *parent = node->parent;
							while (parent && parent->left == node)
							{
								node = parent;
								parent = parent->parent;
							}
							if (parent)
								node = parent;
							else
								node = NULL;
						}
					}

					Node<U> *node;
			};
			template<class U>
			class const_rbt_iterator
			{
				public:
					const_rbt_iterator();
					const_rbt_iterator(Node<U> *n) : node(n) {};
					Node<U> *base() { return (node); };
					U const & operator *() { return (node->value); };
					U const * operator->() { return (&(node->value)); };
					const_rbt_iterator<U> &operator=(const const_rbt_iterator<U> &rhs)
					{
						this->node = rhs.node;
						return (*this);
					};
					bool operator==(const const_rbt_iterator<U> &rhs) { return (node == rhs.node); };
					bool operator!=(const const_rbt_iterator<U> &rhs) { return (node != rhs.node); };
					const_rbt_iterator<U> &operator++()
					{
						incrementation();
						return (*this);
					}
					const_rbt_iterator<U> &operator++(int)
					{
						const_rbt_iterator<U> *tmp = this;
						incrementation();
						return (*tmp);
					}
					const_rbt_iterator<U> &operator--()
					{
						decrementation();
						return (*this);
					}
					const_rbt_iterator<U> &operator--(int)
					{
						const_rbt_iterator<U> *tmp = this;
						decrementation();
						return (*tmp);
					}
	
				private:
					void incrementation()
					{
						if (node->right)
						{
							node = node->right;
							while (node->left)
								node = node->left;
						} 
						else
						{
							while (node->parent && node->parent->right == node)
								node = node->parent;
							node = node->parent;
						}
					}
					void decrementation()
					{
						if (node->parent->parent == node && node->color == RED)
							node = node->left;
						else if (node->left)
						{
							while (node->right)
								node = node->right;
						}
						else
						{
							Node<U> *parent = node->parent;
							while (parent->left == node)
							{
								node = parent;
								parent = parent->parent;
							}
							node = parent;
						}
					}
					Node<U> *node;
			};

			void printBT()
			{
				Node<T> *node = root;
				printBT("", node, false);
			}
			red_black_tree(Compare cmp, Alloc alloc) : comp(cmp), _my_alloc(alloc), root(nullptr), _size(0) {};
			~red_black_tree() { this->clear(); };
			rbt_iterator<T> insert(const T& value, bool *flag)
			{
				Node<T> *n = this->root;
				Node<T> *ret = nullptr;
				Node<T> *inserted = new_node(value);
				if (this->root == nullptr)
				{
					this->root = inserted;
					this->root->color = BLACK;
					inserted->parent = n;
					ret = this->root;
					*flag = true;
					this->_size++;
					//_my_alloc.deallocate(inserted, 1);
					return ret;
				}
				while(n != nullptr)
				{
					if (comp(value, n->value))
					{
						if (n->left == nullptr)
						{
							n->left = inserted;
							ret = n->left;
							*flag = true;
							break;
						}
						else
							n = n->left;
					}
					else if (comp(n->value, value))
					{
						if (n->right == nullptr)
						{
							n->right = inserted;
							ret = n->right;
							*flag = true;
							break;
						}
						else
							n = n->right;
					}
					else
					{
						std::cout << n->value.first << std::endl;
						*flag = false;
						return n;
					}
				}
				inserted->parent = n;
				fix_tree(inserted);
				this->_size++;
				return (ret);
			};
			rbt_iterator<T> insert_from_position(rbt_iterator<T> position, const T& value)
			{
				Node<T> *n = position.base();
				Node<T> *inserted = new_node(value);

				while(n != nullptr)
				{
					if (comp(value, n->value))
					{
						if (n->left == nullptr)
						{
							n->left = inserted;
							break;
						}
						else
							n = n->left;
					}
					else if (comp(n->value, value))
					{
						if (n->right == nullptr)
						{
							n->right = inserted;
							break;
						}
						else
							n = n->right;
					}
					else
					{
						std::cout << n->value.first << std::endl;
						return n;
					}
				}
				inserted->parent = n;
				fix_tree(inserted);
				this->_size++;
				return (rbt_iterator<T>(inserted));
			};
			Node<T> *maxleft()
			{
				Node<T> *tmp = this->root;

				while (tmp->left != nullptr)
					tmp = tmp->left;
				return (tmp);
			}
			Node<T> *maxright()
			{
				Node<T> *tmp = this->root;

				while (tmp->right != nullptr)
					tmp = tmp->right;
				return (tmp);
			}
			Node<T> *get_root() const { return (root); };
			size_t	size() const { return (this->_size); };
			void erase(rbt_iterator<T> pos)
			{
				Node<T> *z = pos.base();
				Node<T> *y = z;
				Node<T> *x;
				node_color y_orignal_color = y->color;
				if(z->left == NULL)
				{
					x = z->right;
					rb_transplant(z, z->right);
				}
				else if(z->right == NULL)
				{
					x = z->left;
					rb_transplant(z, z->left);
				}
				else
				{
					y = maxleft_from_node(z->right);
					y_orignal_color = y->color;
					x = y->right;
					if(x && y->parent == z)
						x->parent = z;
					else
					{
						rb_transplant(y, y->right);
						y->right = z->right;
						if (y->right)
							y->right->parent = y;
					}
					rb_transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				if(y_orignal_color == BLACK)
  					rb_delete_fixup(x);
				_my_alloc.destroy(pos.base());
				_my_alloc.deallocate(pos.base(), 1);
				this->_size--;
			};
			void clear()
			{
				if (!this->root)
					return ;
				rbt_iterator<T> it = this->maxleft();
				while (it != this->maxright())
				{
					rbt_iterator<T> tmp = it;
					it++;
					this->erase(tmp);
				}
				this->erase(this->maxright());
			}
		private:
			Compare comp;
			Alloc _my_alloc;
			Node<T> *root;
			size_t _size;
			Node<T> *new_node(const T& value)
			{
				Node<T> *node = _my_alloc.allocate(1);
				_my_alloc.construct(node, value);
				return (node);
			};
			void rb_transplant(Node<T> *u, Node<T> *v)
			{
				if(u->parent == NULL)
					this->root = v;
				else if(u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v)
					v->parent = u->parent;
			}
			Node<T>* maxleft_from_node(Node<T> *x)
			{
				while(x->left != NULL)
					x = x->left;
				return x;
			}

			void rb_delete_fixup(Node<T> *x)
			{
				if (x)
				{
					while(x != this->root && x->color == BLACK)
					{
						if(x == x->parent->left)
						{
							Node<T> *w = x->parent->right;
							if(w->color == RED)
							{
								w->color = BLACK;
								x->parent->color = RED;
								left_rotate(x->parent);
								w = x->parent->right;
							}
							if((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))
							{
								w->color = RED;
								x = x->parent;
							}
							else 
							{
								if(w->right == NULL || w->right->color == BLACK)
								{
									w->left->color = BLACK;
									w->color = RED;
									right_rotate(w);
									w = x->parent->right;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->right->color = BLACK;
								left_rotate(x->parent);
								x = this->root;
							}
						}
						else
						{
							Node<T> *w = x->parent->left;
							if(w->color == RED)
							{
								w->color = BLACK;
								x->parent->color = RED;
								right_rotate(x->parent);
								w = x->parent->left;
							}
							if((w->right == NULL || w->right->color == BLACK) && (w->left == NULL || w->left->color == BLACK))
							{
								w->color = RED;
								x = x->parent;
							}
							else
							{
								if(w->left == NULL || w->left->color == BLACK)
								{
									
									w->right->color = BLACK;
									w->color = RED;
									left_rotate(w);
									w = x->parent->left;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->left->color = BLACK;
								right_rotate(x->parent);
								x = this->root;
							}
						}
					}
					x->color = BLACK;
				}
			}
			void left_rotate(Node<T> *node)
			{
				Node<T> *n = node->right;
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
			void right_rotate(Node<T> *node)
			{
				Node<T> *n = node->left;
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
			void fix_tree(Node<T> *node)
			{
				while (node != root && node->parent->color == RED)
				{
					if (node->parent == node->parent->parent->left)
					{
						Node<T> *n = node->parent->parent->right;
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
						Node<T> *n = node->parent->parent->left;
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


		void printBT(const std::string& prefix, const Node<T>* node, bool isLeft)
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






