
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

//here q is moving first and p is following q
void RemoveDuplicates()
{
  Node *p = first;
  Node *q = p->next;
  while (q)
  {
    if (p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}

int main()
{
  int arr[] = {5, 4, 3, 2, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  RemoveDuplicates();
  display();
}