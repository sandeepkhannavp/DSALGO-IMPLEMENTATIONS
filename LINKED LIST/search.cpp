//binary search cannot be performed in the linked list as we cannot directly go the middle of the list
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
Node *search(int key)
{
  Node *p = first;
  while (p)
  {
    if (p->data == key)
    {
      return p;
    }
    else
      p = p->next;
  }
  return nullptr;
}

Node *Rsearch(Node *p, int key)
{
  if (p == nullptr)
    return nullptr;
  if (key == p->data)
    return p;
  else
    return Rsearch(p->next, key);
}

Node *ISearch(struct Node *p, int key)
{
  Node *q;

  while (p != NULL)
  {
    if (key == p->data)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  Node *x = ISearch(first, 5);
  if (x)
    cout << "found";
  else
    cout << "Not found";
}