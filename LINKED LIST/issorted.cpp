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
//x will keep track of the previous node
int isSorted(struct Node *p)
{
  int x = -65536;

  while (p != NULL)
  {
    if (p->data < x)
      return 0;
    x = p->data;
    p = p->next; 
  }
  return 1;
}
int main()
{
  int arr[] = {1, 2, 3, 0, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  if (isSorted(first))
    cout << "Sorted";
  else
    cout << "Not sorted";
}