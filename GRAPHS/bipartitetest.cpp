// number of nodes - N
// number of edges - M

#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int color[N+1];
int visit[1001] = {0};
bool dfs(int v , int c)
{
  visit[v] = 1;
  color[v] = c;
  cout << v << " ";
  for (auto child : arr[v]) 
  {
    if (visit[child] == 0) //if node not visited
    {
      if(dfs(child,c^1)==false)
        return false;
    }
    else                   //if node visited
    {
      if(color[v]==color[child])
        return false;
    }
  }
  return true;
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
  cout<<boolalpha;
  cout<<dfs(1,1);
}