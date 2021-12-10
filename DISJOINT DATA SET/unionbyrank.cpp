#include <bits/stdc++.h>
using namespace std;
int _rank[100001];
int par[100001];
int find(int a)
{
	if(par[a] == -1)
	return a;
 
	else
	return find(par[a]);
}
 
void merge(int a , int b)
{
	a = find(a);
	b = find(b);
 
	if(a == b)
	return ;
 
	if(_rank[a] > _rank[b])
	{
		_rank[a] += _rank[b];
		par[b] = a;
	}
	else
	{
		_rank[b] += _rank[a];
		par[a] = b;
	}
}
 
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++)
  {
    par[i]=-1;
    _rank[i]=1;
  }
  
}