
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
  Node *lchild;
  int data;
  Node *rchild;
  Node(){};
  Node(int data);
};

Node::Node(int data)
{
  lchild = nullptr;
  this->data = data;
  rchild = nullptr;
}

class Tree
{
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void CreateTree();
  void Preorder(Node *p);
  void Preorder() { Preorder(root); } // Passing Private Parameter in Constructor
  void Inorder(Node *p);
  void Inorder() { Inorder(root); }
  void Postorder(Node *p);
  void Postorder() { Postorder(root); }
  void Levelorder(Node *p);
  void Levelorder() { Levelorder(root); }
  void iterativePreorder(Node *p);
  void iterativePreorder() { iterativePreorder(root); }
  void iterativeInorder(Node *p);
  void iterativeInorder() { iterativeInorder(root); }
  void iterativePostorder(Node *p);
  void iterativePostorder() { iterativePostorder(root); }
  Node *generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
  int Height(Node *p);
  int Height() { return Height(root); }
  int Count(Node *p);
  int Count() { Count(root); }
  int Sum(Node *p);
  int Sum() { Sum(root); }
  int deg2NodeCount(Node *p);
  int deg2NodeCount() { deg2NodeCount(root); }
};

Tree::Tree()
{
  root = nullptr;
}

Tree::~Tree()
{
  // TODO
}

void Tree::CreateTree()
{
  Node *p;
  Node *t;
  int x;
  queue<Node *> q;

  root = new Node;
  cout << "Enter root data: " << flush;
  cin >> x;
  root->data = x;
  root->lchild = nullptr;
  root->rchild = nullptr;
  q.emplace(root);

  while (!q.empty())
  {
    p = q.front();
    q.pop();

    cout << "Enter left child data of " << p->data << ": " << flush;
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = nullptr;
      t->rchild = nullptr;
      p->lchild = t;
      q.emplace(t);
    }

    cout << "Enter right child data of " << p->data << ": " << flush;
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = nullptr;
      t->rchild = nullptr;
      p->rchild = t;
      q.emplace(t);
    }
  }
}

void Tree::Inorder(Node *p)
{
  if (p)
  {
    Inorder(p->lchild);
    cout << p->data << ", " << flush;
    Inorder(p->rchild);
  }
}

void Tree::iterativeInorder(Node *p)
{
  stack<Node *> stk;
  while (p != nullptr || !stk.empty())
  {
    if (p != nullptr)
    {
      stk.emplace(p);
      p = p->lchild;
    }
    else
    {
      p = stk.top();
      stk.pop();
      cout << p->data << ", " << flush;
      p = p->rchild;
    }
  }
  cout << endl;
}

int searchInorder(int inArray[], int inStart, int inEnd, int data)
{
  for (int i = inStart; i <= inEnd; i++)
  {
    if (inArray[i] == data)
    {
      return i;
    }
  }
  return -1;
}

Node *Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd)
{
  static int preIndex = 0;

  if (inStart > inEnd)
  {
    return nullptr;
  }

  Node *node = new Node(preorder[preIndex++]);

  if (inStart == inEnd)
  {
    return node;
  }

  int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
  node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
  node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

  return node;
}

int main()
{

  Tree bt;

  return 0;
}