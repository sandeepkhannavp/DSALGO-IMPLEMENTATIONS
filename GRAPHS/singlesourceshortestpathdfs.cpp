// number of nodes - N
// number of edges - M

#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int dist[N+1];
int visit[1001] = {0};
void dfs(int node,int d)
{
  visit[node] = 1;
  dist[node] = d;
  cout << node << " ";
  for (int child : arr[node])
  {  
    if (visit[child] == 0)
      dfs(child,dist[node]+1);
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
  dfs(1,0);
}