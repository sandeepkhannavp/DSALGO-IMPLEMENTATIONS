#include <bits/stdc++.h>
using namespace std;
struct Node
{
  Node *prev;
  int data;
  Node *next;
};

int main()
{
  Node *t = new Node;
  t->data = 0;
  t->prev = nullptr;
  t->next = nullptr;
}