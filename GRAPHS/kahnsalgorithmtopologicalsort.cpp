#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10001];
vector<int> res;
//this works for DAG(directed acyclic graph with no cycles)
int in[10001]; //array to store the indegree of all the nodes
void kahn(int n)
{
  /* 
    if you want to store such time it should be in lexicographically smaller
      priority_queue<int , vector<int> , greater<int>> pq; -- min heap in background
      priority_queue<int> pq; -- max heap
  */
  queue<int> q; //queue to store all the nodes with indegree 0

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0) //find all the nodes with indegree 0 and store it in the queue intially
      q.push(i);
  }
  while (!q.empty())
  {
    int curr = q.front();
    res.push_back(curr);
    q.pop();
    for (auto node : arr[curr])
    {
      in[node]--; //removing the edge
      if (in[node] == 0)
        q.push(node);
    }
  }

  for(auto i:res)
    cout<<i<<" ";
  cout<<endl;
}

int main()
{
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> x >> y;
    arr[x].push_back(y); //since directed
    in[y]++;
  }
  kahn(n);
}