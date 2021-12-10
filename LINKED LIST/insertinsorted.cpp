#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next; // self referential structure //points to the next node
} * first;
void create(int arr[], int n)
{
  Node *t, *last;
  first = new Node;
  first->data = arr[0];
  last = first;
  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = arr[i];
    t->next = nullptr;
    last->next = t;
    last = t;
  }
}
void display()
{
  Node *p = first;
  while (p)
  {
    cout << p->data << endl;
    p = p->next;
  }
}

void SortedInsert(Node *p, int x)
{
  Node *t, *q = nullptr;
  t = new Node;
  t->data = x;
  t->next = nullptr;

  if (first == nullptr)
    first = t;
  else
  {
    while (p && p->data < x)
    {
      q = p;
      p = p->next;
    }
    if (p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
  }
}
int main()
{
  int arr[] = {1, 2, 3, 5, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  SortedInsert(first, 4);
  display();
}