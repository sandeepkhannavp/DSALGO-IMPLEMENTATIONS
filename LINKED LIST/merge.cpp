#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next; // self referential structure //points to the next node
} * first, *second, *third = nullptr;
void display()
{
  Node *p = first;
  while (p)
  {
    cout << p->data << endl;
    p = p->next;
  }
}
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

void Merge(Node *p, Node *q)
{
  Node *last;
  if (p->data < q->data)
  {
    third = last = p;
    p = p->next;
    third->next = nullptr;
  }
  else
  {
    third = last = q;
    q = q->next;
    third->next = nullptr;
  }
  while (p && q)
  {
    if (p->data < q->data)
    {
      last->next = p;
      last = p;
      p = p->next;
      last->next = nullptr;
    }
    else
    {
      last->next = q;
      last = q;
      q = q->next;
      last->next = nullptr;
    }
  }
  if (p)
    last->next = p;
  if (q)
    last->next = q;
}
void create2(int arr[], int n)
{
  Node *t, *last;
  second = new Node;
  second->data = arr[0];
  last = second;
  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = arr[i];
    t->next = nullptr;
    last->next = t;
    last = t;
  }
}

int main()
{
  int arr[] = {10, 20, 30, 40, 50};
  int arr2[] = {15, 18, 29, 70, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  create2(arr2, n);
  Merge(first, second);
  display();
}