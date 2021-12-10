#include <bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node *next;
} *top = nullptr;

void push(char x)
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

char pop()
{
  struct Node *t;
  char x = -1;

  if (top == nullptr)
    printf("Stack is Empty\n");
  else
  {
    t = top;
    top = top->next;
    x = t->data;
    delete t;
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

int isBalanced(char *exp)
{
  int i;

  for (i = 0; exp[i] != '\0'; i++)
  {
    if (exp[i] == '(')
      push(exp[i]);
    else if (exp[i] == ')')
    {
      if (top == nullptr)
        return 0;
      pop();
    }
  }
  if (top == nullptr)
    return 1;
  else
    return 0;
}

int pre(char x)
{
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;
  return 0;
}

int isOperand(char x)
{
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
  else
    return 1;
}

char *InToPost(char *infix)
{
  int i = 0, j = 0;
  char *postfix;
  int len = strlen(infix);
  postfix = new char[len + 1];

  while (infix[i] != '\0')
  {
    if (isOperand(infix[i]))
      postfix[j++] = infix[i++];
    else
    {
      if (pre(infix[i]) > pre(top->data))
        push(infix[i++]);
      else
      {
        postfix[j++] = pop();
      }
    }
  }
  while (top != nullptr)
    postfix[j++] = pop();
  postfix[j] = '\0';
  return postfix;
}

int main()
{
  char *infix = "a+b*c-d/e";
  push('#');

  char *postfix = InToPost(infix);

  printf("%s ", postfix);

  return 0;
}