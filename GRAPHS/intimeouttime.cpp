// number of nodes - N
// number of edges - M
// to check whether one node is in subtree of another in time of root smaller than in time of children
// and ottime of children will be smaller than the outtime of root
#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int visit[1001] = {0};
int In[1001] = {0};
int Out[1001] = {0};
int timer=1;
void dfs(int v)  
{
  visit[v] = 1;
  In[v] = timer++;
 // cout << v << " ";
  for (int child : arr[v])
  { 
    if (visit[child] == 0)
      dfs(child);
  }
  Out[v] = timer++;
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