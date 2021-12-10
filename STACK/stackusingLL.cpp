#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
} *top = nullptr;

void push(int x)
{
  struct Node *t;
  t = new Node;

  if (t == nullptr)
    printf("stack is full\n");
  else
  {
    t->data = x;
    t->next = top;
    top = t;
  }
}
int pop()
{
  struct Node *t;
  int x = -1;

  if (top == nullptr)
    printf("Stack is Empty\n");
  else
  {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  return x;
}
void Display()
{
  struct Node *p;
  p = top;
  while (p != nullptr)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}
// it starts from 1
void peek(int pos)
{
  int x = 1;
  Node *p = top;
  for (int i = 0; p != nullptr && i < pos - 1; i++)
  {
    p = p->next;
  }
  if (p != nullptr)
    cout << p->data;
  else
    cout << "not found";
}

int isEmpty()
{
  if (top)
    return 0;
  else
    return 1; //if top doesnt exitst -- null , it is empty and return 1
}

int isFull()
{
  if (top)
    return 1;
  else
    return 0;
}

int Top()
{
  if (top)
    return top->data;
  else
    return -1;
}

int main()
{
  push(10);
  push(20);
  push(30);
  Display();
  cout << Top();
  return 0;
}