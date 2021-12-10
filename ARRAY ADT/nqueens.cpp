#include <bits/stdc++.h>
using namespace std;
int column[4];
int diag1[10];
int diag2[10];
int counter = 0;
void search(int y)
{
  int n = 8;
  if (y == n)
  {
    counter++;
    return;
  }
  for (int x = 0; x < n; x++)
  {
    if (column[x] || diag1[x + y] || diag2[x - y + n - 1])
      continue;
    column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
    search(y + 1);
    column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
  }
}
int main()
{
  search(0);
  cout << counter;
}