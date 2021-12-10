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

void middleNode1(Node *p)
{
  int length = 0;
  while (p)
  {
    length++;
    p = p->next;
  }

  int index = (int)ceil(length / 2.0);
  Node *q = first;
  for (int i = 0; i < index - 1; i++)
  {
    q = q->next;
  }
  cout << "Middle Element (Method-I): " << q->data << endl;
}

void middleNode2(Node *p)
{
  Node *q = p;
  while (q)
  {
    q = q->next;
    if (q)
    {
      q = q->next;
    }
    if (q)
    {
      p = p->next;
    }
  }
  cout << "Middle Element (Method-II): " << p->data << endl;
}

void middleNode3(Node *p)
{
  stack<Node *> s;
  while (p)
  {
    s.push(p);
    p = p->next;
  }
  int length = s.size();
  int popLength = (int)(floor(length / 2.0));
  while (popLength)
  {
    s.pop();
    popLength--;
  }
  cout << "Middle Element (Method-III): " << s.top()->data << endl;
}

int main()
{
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  create(arr, n);
  middleNode3(first);
}