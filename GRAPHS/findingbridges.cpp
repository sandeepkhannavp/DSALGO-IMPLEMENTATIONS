#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100001], inTime(100001), low(100001);
vector<pair<int, int> > ans;
bool vis[100001], isBridge;
int timer;

void dfs(int node, int par) {
	vis[node] = true;
	low[node] = inTime[node] = timer;
	timer++;

	for (int child : ar[node]) {
		if (child == par) //parent
			continue;

		if (vis[child]) { //backedge
			low[node] = min(low[node], inTime[child]);
		}
		else { //tree edge
			dfs(child, node);
			if (low[child] > inTime[node]) {
				cout<<node<<"-"<<child<<" is a bridge\n";
			}
			low[node] = min(low[node], low[child]);
		}
	}
}

int main() {
	int n,m,x,y;
	cin>>n>>m;
	while(m--)
	{
	    cin>>x>>y;
	    ar[x].push_back(y);
	    ar[y].push_back(x);
	}
	dfs(1,-1);
}