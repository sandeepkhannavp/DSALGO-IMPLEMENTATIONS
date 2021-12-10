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

void Rdisplay(Node *p)
{
  if (p)
  {
    cout << p->data << endl;
    Rdisplay(p->next);
  }
}

void Reversedisplay(Node *p)
{
  if (p)
  {
    Reversedisplay(p->next);
    cout << p->data << endl;
  }
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
}