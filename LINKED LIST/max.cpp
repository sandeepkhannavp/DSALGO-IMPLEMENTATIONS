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
void max()
{
  int max = INT32_MIN;
  Node *p = first;
  while (p)
  {
    if (p->data > max)
      max = p->data;
    p = p->next;
  }
  cout << max;
}

int Rmax(Node *p)
{
  int x = 0;
  if (p == nullptr)
    return 0;
  else
  {
    x = Rmax(p->next);
    if (x > p->data)
      return x;
    else
      return p->data;
  }
}
int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  int x = Rmax(first);
  cout << x;
}