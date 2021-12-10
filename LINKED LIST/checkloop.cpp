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
int isLoop()
{
  struct Node *p, *q;
  p = q = first;

  do
  {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p != q);

  if (p == q)
    return 1;
  else
    return 0;
}
int main()
{
  Node *t1, *t2;
  int arr[] = {10, 20, 30, 40, 50};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  t1 = first->next->next;             //make it point on 30
  t2 = first->next->next->next->next; //make it point on 50
  t2->next = t1;                      //make last element point on 30, forming a loop
  if (isLoop())
    cout << "It forms a loop";
  else
    cout << "It is linear";
}