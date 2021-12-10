#include <bits/stdc++.h>
using namespace std;
struct edge
{
  int a, b, w;
};
bool comp(edge a, edge b)
{
  if (a.w < b.w)
    return true;
  else
    return false;
}

int find(int a)
{
  if (par[a] == -1)
    return a;
  return par[a] = find(par[a]);
}

void merge(int a, int b)
{
  par[a] = b;
}

edge arr[100000];
int par[10001];
int main()
{
  int n, m, a, b, w, sum = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    par[i] = -1;
  }
  for (int i = 0; i < m; i++)
  {
    cin >> arr[i].a >> arr[i].b >> arr[i].w;
  }
  sort(arr, arr + m, comp);
  for (int i = 0; i < m; i++)
  {
    a = find(arr[i].a);
    b = find(arr[i].b);
    if (a != b)
    {
      sum += arr[i].w;
      merge(a, b);
    }
  }
  cout<<sum<<endl;
}