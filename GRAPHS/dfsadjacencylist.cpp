// number of nodes - N
// number of edges - M

#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int visit[1001]; 
void dfs(int v)
{
  visit[v] = 1;
  cout << v << " ";
  for (int child : arr[v])
  {
    if (visit[child] == 0) //if it is not visited
      dfs(child);
  }
} 
int main()
{
  int m;
  cin >> m;
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b), arr[b].push_back(a);
  }
}