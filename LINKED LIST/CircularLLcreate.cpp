#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
} * Head;

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

int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
}
