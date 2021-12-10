#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next; // self referential structure //points to the next node
} * first, *second;
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

void concatenate()
{
  Node *p = first;
  while (p->next != nullptr)
  {
    p = p->next;
  }
  p->next = second;
  second = nullptr;
}

int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int arr2[] = {7, 8, 9, 10, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  create2(arr2, n);
  concatenate();
  display();
}