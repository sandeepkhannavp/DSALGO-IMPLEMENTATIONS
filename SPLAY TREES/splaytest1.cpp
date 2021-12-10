#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *parent;
  Node *left;
  Node *right;
};

typedef Node *NodePtr;

class SplayTree
{
public:
  NodePtr root;
  SplayTree();
  void leftRotate(NodePtr x);
  void rightRotate(NodePtr x);
  void splay(NodePtr x);
  NodePtr searchTreeHelper(NodePtr node, int key);
  NodePtr searchTree(int k);
  void insert(int key);
  void deleteNode(NodePtr node, int key);
  NodePtr join(NodePtr s, NodePtr t);
  void split(NodePtr &x, NodePtr &s, NodePtr &t);

  void preorder(NodePtr node);
  void inorder(NodePtr node);
  void postorder(NodePtr node);

  NodePtr minimum(NodePtr node);
  NodePtr maximum(NodePtr node);
  NodePtr successor(NodePtr x);
  NodePtr predecessor(NodePtr x);
  NodePtr getRoot();
};

//1
void SplayTree::preorder(NodePtr node)
{
  if (node != nullptr)
  {
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
  }
}
//2
void SplayTree::inorder(NodePtr node)
{
  if (node != nullptr)
  {
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}
//3
void SplayTree::postorder(NodePtr node)
{
  if (node != nullptr)
  {
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
  }
}
//4
NodePtr SplayTree::searchTreeHelper(NodePtr node, int key)
{
  if (node == nullptr || key == node->data)
  {
    return node;
  }

  if (key < node->data)
  {
    return searchTreeHelper(node->left, key);
  }
  return searchTreeHelper(node->right, key);
}

//4-i
NodePtr SplayTree::searchTree(int k)
{
  NodePtr x = searchTreeHelper(this->root, k);
  if (x)
  {
    splay(x);
  }
  return x;
}

//5
void SplayTree::deleteNode(NodePtr node, int key)
{
  NodePtr x = nullptr;
  NodePtr t, s;
  while (node != nullptr)
  {
    if (node->data == key)
    {
      x = node;
    }

    if (node->data <= key)
    {
      node = node->right;
    }
    else
    {
      node = node->left;
    }
  }

  if (x == nullptr)
  {
    cout << "Couldn't find key in the tree" << endl;
    return;
  }
  split(x, s, t);
  if (s->left)
  {
    s->left->parent = nullptr;
  }
  root = join(s->left, t);
  delete (s);
  s = nullptr;
}
//6
void SplayTree::leftRotate(NodePtr x)
{
  NodePtr y = x->right;
  x->right = y->left;
  if (y->left != nullptr)
  {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr)
  {
    this->root = y;
  }
  else if (x == x->parent->left)
  {
    x->parent->left = y;
  }
  else
  {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}
//7
void SplayTree::rightRotate(NodePtr x)
{
  NodePtr y = x->left;
  x->left = y->right;
  if (y->right != nullptr)
  {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr)
  {
    this->root = y;
  }
  else if (x == x->parent->right)
  {
    x->parent->right = y;
  }
  else
  {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}
//8
void SplayTree::splay(NodePtr x)
{
  while (x->parent)
  {
    if (!x->parent->parent)
    {
      if (x == x->parent->left)
      {
        // zig rotation
        rightRotate(x->parent);
      }
      else
      {
        // zag rotation
        leftRotate(x->parent);
      }
    }
    else if (x == x->parent->left && x->parent == x->parent->parent->left)
    {
      // zig-zig rotation
      rightRotate(x->parent->parent);
      rightRotate(x->parent);
    }
    else if (x == x->parent->right && x->parent == x->parent->parent->right)
    {
      // zag-zag rotation
      leftRotate(x->parent->parent);
      leftRotate(x->parent);
    }
    else if (x == x->parent->right && x->parent == x->parent->parent->left)
    {
      // zig-zag rotation
      leftRotate(x->parent);
      rightRotate(x->parent);
    }
    else
    {
      // zag-zig rotation
      rightRotate(x->parent);
      leftRotate(x->parent);
    }
  }
}
//9
NodePtr SplayTree::join(NodePtr s, NodePtr t)
{
  if (!s)
  {
    return t;
  }

  if (!t)
  {
    return s;
  }
  NodePtr x = maximum(s);
  splay(x);
  x->right = t;
  t->parent = x;
  return x;
}
//10
void SplayTree::split(NodePtr &x, NodePtr &s, NodePtr &t)
{
  splay(x);
  if (x->right)
  {
    t = x->right;
    t->parent = nullptr;
  }
  else
  {
    t = nullptr;
  }
  s = x;
  s->right = nullptr;
  x = nullptr;
}

//----------------------------------------------------------------------------

//1
SplayTree::SplayTree()
{
  root = nullptr;
}


//6
NodePtr SplayTree::minimum(NodePtr node)
{
  while (node->left != nullptr)
  {
    node = node->left;
  }
  return node;
}
//7
NodePtr SplayTree::maximum(NodePtr node)
{
  while (node->right != nullptr)
  {
    node = node->right;
  }
  return node;
}
//8
NodePtr SplayTree::successor(NodePtr x)
{

  if (x->right != nullptr)
  {
    return minimum(x->right);
  }

  NodePtr y = x->parent;
  while (y != nullptr && x == y->right)
  {
    x = y;
    y = y->parent;
  }
  return y;
}
//9
NodePtr SplayTree::predecessor(NodePtr x)
{

  if (x->left != nullptr)
  {
    return maximum(x->left);
  }

  NodePtr y = x->parent;
  while (y != nullptr && x == y->left)
  {
    x = y;
    y = y->parent;
  }

  return y;
}
//10
void SplayTree::insert(int key)
{

  NodePtr node = new Node;
  node->parent = nullptr;
  node->left = nullptr;
  node->right = nullptr;
  node->data = key;
  NodePtr y = nullptr;
  NodePtr x = this->root;

  while (x != nullptr)
  {
    y = x;
    if (node->data < x->data)
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }

  node->parent = y;
  if (y == nullptr)
  {
    root = node;
  }
  else if (node->data < y->data)
  {
    y->left = node;
  }
  else
  {
    y->right = node;
  }

  splay(node);
}
//11
NodePtr SplayTree::getRoot()
{
  return this->root;
}

int main()
{
  SplayTree bst;
  //14 13 16 15 7 10
  bst.insert(14);
  bst.insert(13);
  bst.insert(16);
  bst.insert(15);
  bst.insert(7);
  bst.insert(10);
  bst.deleteNode(bst.root, 15);
  bst.searchTree(10);
  bst.preorder(bst.root);
  /*
  bst.searchTree(33);
  bst.searchTree(44);
  bst.deleteNode(89);
  bst.deleteNode(67);
  bst.deleteNode(41);
  bst.deleteNode(5);

  bst.deleteNode(98);
  bst.deleteNode(1);
  bst.deleteNode(44);
  bst.deleteNode(33);
*/
  return 0;
}