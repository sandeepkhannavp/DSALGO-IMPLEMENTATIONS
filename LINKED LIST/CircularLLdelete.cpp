#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
} * Head;

void display()
{
  Node *p = Head;
  do
  {
    cout << p->data << " ";
    p = p->next;
  } while (p != Head);
}
void create(int arr[], int n)
{
  Node *t, *last;
  Head = new Node;
  Head->data = arr[0];
  Head->next = Head;
  last = Head;
  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = arr[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}

int Length(Node *p)
{
  int len = 0;
  do
  {
    len++;
    p = p->next;

  } while (p != Head);
  return len;
}
int Delete(Node *p, int index)
{
  Node *q;
  int i, x;

  if (index < 0 || index > Length(Head))
    return -1;
  if (index == 1)
  {
    while (p->next != Head)
      p = p->next;
    x = Head->data;
    if (Head == p)
    {
      delete Head;
      Head = nullptr;
    }
    else
    {
      p->next = Head->next;
      delete Head;
      Head = p->next;
    }
  }
  else
  {
    for (i = 0; i < index - 2; i++)
      p = p->next;
    q = p->next;
    p->next = q->next;
    x = q->data;
    delete q;
  }
  return x;
}

int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  Delete(Head, 4);
  display();
}
