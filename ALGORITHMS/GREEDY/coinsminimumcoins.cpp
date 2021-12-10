#include <bits/stdc++.h>
#define INF 62000
#define N 10
using namespace std;

vector<int> coins{1, 3, 4};
bool ready[N];
int value[N];
int first[N];
//recursive
int solve(int x)
{
  if (x < 0)
    return INF;
  if (x == 0)
    return 0;
  int best = INF;
  for (auto c : coins)
  {
    best = min(best, solve(x - c) + 1);
  }
  return best;
}

//recursive-memoization
int solve1(int x)
{
  if (x < 0)
    return INF;
  if (x == 0)
    return 0;
  if (ready[x])
    return value[x];
  int best = INF;
  for (auto c : coins)
  {
    best = min(best, solve(x - c) + 1);
  }
  value[x] = best;
  ready[x] = true;
  return best;
}

//iterative
int solve2(int n)
{
  value[0] = 0;
  for (int x = 1; x <= n; x++)
  {
    value[x] = INF;
    for (auto c : coins)
    {
      if (x - c >= 0)
      {
        value[x] = min(value[x], value[x - c] + 1);
      }
    }
  }
  return value[n];
}

void print(int n)
{
  value[0] = 0;
  for (int x = 1; x <= n; x++)
  {
    value[x] = INF;
    for (auto c : coins)
    {
      if (x - c >= 0 && value[x - c] + 1 < value[x])
      {
        value[x] = value[x - c] + 1;
        first[x] = c;
      }
    }
  }
  while (n > 0)
  {
    cout << first[n] << "\n";
    n -= first[n];
  }
}

int main()
{
  cout << solve2(10) << endl;
  print(10);

  return 0;
}
