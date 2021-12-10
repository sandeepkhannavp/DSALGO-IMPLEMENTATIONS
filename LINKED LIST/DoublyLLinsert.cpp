#include <bits/stdc++.h>
using namespace std;
struct Node
{
  Node *prev;
  int data;
  Node *next;
} * first;

void Display(Node *p)
{
  while (p != nullptr)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << "\n";
}

void create(int A[], int n)
{
  int i;
  struct Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->next = nullptr;
  last = first;
  for (i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t;
  }
}

int length(Node *p)
{
  int len = 0;
  while (p)
  {
    len++;
    p = p->next;
  }
  return len;
}

void insert(Node *p, int index, int x)
{
  Node *t;
  int i;
  if (index < 0 || index > length(p))
    return;
  if (index == 0)
  {
    t = new Node;
    t->data = x;
    t->next = first;
    t->prev = nullptr;
    first->prev = t;
    first = t;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
    {
      p = p->next;
    }
    t = new Node;
    t->data = x;
    t->next = p->next;
    t->prev = p;
    if (p->next)
      p->next->prev = t;
    p->next = t;
  }
}

int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  insert(first, 2, 7);
  Display(first);
}