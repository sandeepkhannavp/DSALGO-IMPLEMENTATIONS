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
// in LL we assume index starts from 1
int Delete(int pos)
{
  Node *p, *q;
  p = first;
  int x = -1;
  if (pos == 1)
  {
    x = first->data;
    first = first->next;
    delete p;
  }
  else
  {
    q = nullptr;
    for (int i = 0; i < pos - 1 && p; i++)
    {
      q = p;
      p = p->next;
    }
    if (p)
    {
      q->next = p->next;
      x = p->data;
      delete p;
    }
  }
  return x;
}
int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  int x = Delete(4);
  if (x)
    cout << "Deleted " << x << endl;
  else
    cout << "Not deleted\n";
  display();
}