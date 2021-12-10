#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next; // self referential structure //points to the next node
} * first, *last;
void create(int arr[], int n)
{
  Node *t;
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
int count(struct Node *p)
{
  int l = 0;
  while (p)
  {
    l++;
    p = p->next;
  }
  return l;
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
void insert(Node *p, int index, int key)
{
  Node *t;
  if (index < 0 || index > count(p))
    return;
  t = new Node;
  t->data = key;
  if (index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

void Insertlast(int x)
{
  Node *t = new Node;
  t->data = x;
  t->next = nullptr;
  if (first == nullptr)
    first = last = t;
  else
  {
    last->next = t;
    last = t;
  }
}
int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  Insertlast(0);
  display();
}