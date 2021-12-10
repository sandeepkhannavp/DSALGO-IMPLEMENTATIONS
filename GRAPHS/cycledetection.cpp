// number of nodes - N
// number of edges - M
//any edge that connects a node to its ancestor rather than parent is called back edge
#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int visit[1001] = {0};
bool dfs(int node, int par)
{
  visit[node] = 1;
  for (int child : arr[node])
  {  
    if (visit[child] == 0) //if node not visited
    {
      if (dfs(child, node) == true)
        return true;
    }
    else //if node visited
    {
      if (child != par) //if the child is its parent-there is no cycle , else there is a cycle 
        return true;
    }
  }
  return false;
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
