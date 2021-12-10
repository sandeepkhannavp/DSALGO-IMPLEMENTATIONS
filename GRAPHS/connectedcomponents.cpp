// number of nodes - N
// number of edges - M

#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int visit[1001] = {0};
void dfs(int v)
{
  visit[v] = 1;
  cout << v << " ";
  for (int child : arr[v])
  {
    if (visit[child] == 0)
      dfs(child);
  }
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  { 
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b), arr[b].push_back(a);
  }
  int cc_count = 0;
  for (int i = 1; i <= N; i++)
  {
    if (visit[i] == 0)
    {
      dfs(i);
      cc_count++;
    }
  }
  cout << "Number of connected components: " << cc_count;
}