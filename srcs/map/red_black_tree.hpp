#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

enum node_color {
  RED,
  BLACK
};

struct Node
{
  int data;
  Node *parent;
  Node *left;
  Node *right;
  node_color color;
};

class red_black_tree
{

};

#endif