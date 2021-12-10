#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[10001][10001];
int visit[10001][10001];
bool isValid(int x,int y)
{
  if(x<1 || x>N || y<1 || y<M)
    return false;
  if(visit[x][y]==1)
    return false;
  
  return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x , int y)
{
  visit[x][y]=1;
  cout<<x<<" "<<y<<endl;
  for(int i=0; i<4 ; i++)
  {
    if(isValid(x+dx[i] , y+dy[i]))
      dfs(x+dx[i] , y+dy[i]);
  }

  /* 
  if(isValid(x-1 ,y))
    dfs(x-1 ,y);
  if(isValid(x,y+1))
    dfs(x,y+1);
  if(isValid(x+1,y))
    dfs(x+1,y);
  if (isValid(x,y-1))
    dfs(x,y-1);

  */
}

int main()
{
  cin>>N>>M;
  dfs(1,1);
}