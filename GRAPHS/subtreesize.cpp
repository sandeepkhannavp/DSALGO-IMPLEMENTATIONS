 // number of nodes - N
// number of edges - M

#include <bits/stdc++.h>  
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int visit[1001] = {0};
int subSize[1001] = {0};
int dfs(int node) 
{
  visit[node] = 1;
  int curr_size=1;
  for (int child : arr[node])
  {
    if (visit[child] == 0)
      curr_size+=dfs(child); //the size of a subtree is 1 + size of its children subtrees
  }
  subSize[node] = curr_size;
  return curr_size;
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