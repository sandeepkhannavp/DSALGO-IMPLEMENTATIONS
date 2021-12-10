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
void Insert(Node *p, int index, int x)
{
  Node *t;
  int i;
  if (index < 0 || index > Length(p))
    return;

  if (index == 0)
  {
    t = new Node;
    t->data = x;
    if (Head == NULL)
    {
      Head = t;
      Head->next = Head;
    }
    else
    {
      while (p->next != Head) //goes until last node
        p = p->next;
      p->next = t;
      t->next = Head;
      Head = t;
    }
  }
  else
  {
    for (i = 0; i < index - 1; i++)
      p = p->next;
    t = new Node;
    t->data = x;
    t->next = p->next;
    p->next = t;
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  Insert(Head, 5, 6);
  display();
}