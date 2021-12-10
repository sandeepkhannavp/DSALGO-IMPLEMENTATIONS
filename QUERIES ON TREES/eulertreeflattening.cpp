#include <bits/stdc++.h>
using namespace std;
int timer;
int S[100] , T[100] , FT[100];
vector<int> arr[100];
void dfs(int node , int par)
{
  S[node]=timer;
  FT[timer]=node;
  timer++;

  for(int child: arr[node])
  {
    if(child!=par)
      dfs(child,node);
  }
  T[node]=timer;
  FT[timer]=node;
  timer++;
}

int main()
{
    int n,a,b;
    for (int i = 1; i < n; i++)
    {
      cin>>a>>b;
      arr[a].push_back(b);
      arr[b].push_back(a);    
    }
    timer=1;
    dfs(1,-1);

    cout<<"S: ";
    for (int i = 1; i <=n; i++)
    {
      cout<<S[i]<<" ";
    }
     cout<<"T: ";
    for (int i = 1; i <=n; i++)
    {
      cout<<T[i]<<" ";
    }
     cout<<"FT: ";
    for (int i = 1; i <=n; i++)
    {
      cout<<FT[i]<<" ";
    }
}