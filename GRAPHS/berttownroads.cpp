#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
 
vector<int> ar[100001], inTime(100001), low(100001);
vector<pair<int, int> > ans;
bool vis[100001], isBridge;
int timer;
 
void dfs(int node, int par) {
	vis[node] = true;
	low[node] = inTime[node] = timer;
	timer++;
 
	for (int child : ar[node]) {
		if (child == par)
			continue;
 
		if (vis[child]) {
			low[node] = min(low[node], inTime[child]);
			if (inTime[child] > inTime[node])
				ans.pb({child, node});
		}
		else {
			ans.pb({node, child});
			dfs(child, node);
			if (low[child] > inTime[node]) {
				isBridge = true;
				return;
			}
			low[node] = min(low[node], low[child]);
		}
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	dfs(1, -1);
	if (isBridge)
		cout << "0\n";
	else
		for (auto i : ans)
			cout << i.first << " " << i.second << "\n";
	return 0;
}