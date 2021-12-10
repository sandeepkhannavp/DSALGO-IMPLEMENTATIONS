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
int count()
{
  int counter = 0;
  Node *p = first;
  while (p)
  {
    counter++;
    p = p->next;
  }
  return counter;
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
//this method is usinng auxillary array
void Reverse1(Node *p)
{
  int *A, i = 0;
  Node *q = p;
  int x = count();
  A = new int[x];
  while (q)
  {
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q)
  {
    q->data = A[i];
    q = q->next;
    i--;
  }
}
//modifying links
//this method is using sliding pointers r q p
void Reverse2(Node *p)
{
  Node *q = nullptr, *r = nullptr;
  while (p)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

//next is the recursion

void Reverse3(Node *q, Node *p)
{
  if (p)
  {
    Reverse3(p, p->next);
    p->next = q;
  }
  else
    first = q;
}
int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  Reverse3(nullptr, first);
  display();
}