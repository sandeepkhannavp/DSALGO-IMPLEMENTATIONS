#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *next; // self referential structure //points to the next node
};
int main()
{
  Node *p = new Node;
  p->data = 10;
  p->next = nullptr;
}