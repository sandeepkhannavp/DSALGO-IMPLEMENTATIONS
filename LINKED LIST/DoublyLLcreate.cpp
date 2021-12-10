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
int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  Display(first);
  int len = length(first);
  cout << len;
}