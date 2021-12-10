#include <bits/stdc++.h>
using namespace std;
int n;                   // number of nodes
vector<int> adj[100001]; // adjacency list of graph
bool visited[100001];
int inTime[100001], low[100001];
int timer;

void dfs(int node, int parent = -1)
{
  visited[node] = true;
  inTime[node] = low[node] = timer++;
  int children = 0;
  for (int child : adj[node])
  {
    if (child == parent)
      continue;
    if (visited[child])
    { //backedge
      low[node] = min(low[node], inTime[child]);
    }
    else
    { //tree edge
      dfs(child, node);
      low[node] = min(low[node], low[child]);
      if (low[child] >= inTime[node] && parent != -1) //we dont check for root
        cout << node << " is a cut edge\n";           //some times it prints again , thus maintain a set
      ++children;
    }
  }
  if (parent == -1 && children > 1) //condition for root - which is always a articulation point ,there is no node which can have smaller low time than in time of root

    cout << node << " is a cut edge\n";
}

int main()
{
  int n, m, a, b;
  cin >> n >> m;
  while (m--)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < n; ++i)
  {
    if (!visited[i])
      dfs(i);
  }
}
