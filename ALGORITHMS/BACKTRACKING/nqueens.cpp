#include <iostream>
#define n 8
using namespace std;
int count = 0;
int column[n];
int diag1[2 * n - 1];
int diag2[2 * n - 1];
void search(int y)
{
  if (y == n)
  {
    count++;
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
  cout << count;
  return 0;
}