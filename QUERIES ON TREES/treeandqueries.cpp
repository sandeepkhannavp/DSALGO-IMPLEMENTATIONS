#include <bits/stdc++.h>
using namespace std;
const int maxN = 100001;
const int BLK = 700;

vector<int> ar[maxN];
int S[maxN], T[maxN], FT[2 * maxN], col[maxN];
int nodeF[maxN], eleF[maxN], FF[maxN];
int ans[maxN], n;
int timer;

struct query
{
  int l;
  int r;
  int idx;
  int k;
};

query Q[maxN];

void dfs(int node, int par)
{
  S[node] = timer;
  FT[timer] = node;
  timer++;

  for (int child : ar[node])
    if (child != par)
      dfs(child, node);

  T[node] = timer;
  FT[timer] = node;
  timer++;
}

void add(int idx)
{
  int node = FT[idx];
  int c = col[node];
  nodeF[node]++;

  if (nodeF[node] == 2)
  {
    eleF[c]++;
    FF[eleF[c]]++;
    FF[eleF[c] - 1]--;
  }
}

void remove(int idx)
{
  int node = FT[idx];
  int c = col[node];
  nodeF[node]--;

  if (nodeF[node] == 1)
  {
    eleF[c]--;
    FF[eleF[c]]++;
    FF[eleF[c] + 1]--;
  }
}

bool comp(query a, query b)
{
  int x = a.l / BLK;
  int y = b.l / BLK;

  if (x != y)
    return x < y;

  if (x % 2)
    return a.r < b.r;
  else
    return a.r > b.r;
}

int getAns(int k, int n)
{
  int ans = 0;

  for (int i = k; i <= n; i++)
    ans += FF[i];

  return ans;
}

int main()
{
  int q, a, b, k;
  cin >> n >> q;

  for (int i = 1; i <= n; i++)
    cin >> col[i];

  for (int i = 1; i <= n; i++)
  {
    cin >> a >> b,
        ar[a].push_back(b), ar[b].push_back(a);
  }

  timer = 1;
  dfs(1, -1);

  for (int i = 1; i <= n; i++)
  {
    cin >> a >> k;
    Q[i].l = S[a];
    Q[i].r = T[a];
    Q[i].k = k;
    Q[i].idx = i;
  }

  sort(Q + 1, Q + 1 + q, comp);

  int ML = 1, MR = 0;

  for (int i = 1; i <= n; i++)
  {
    int L = Q[i].l;
    int R = Q[i].r;
    int idx = Q[i].idx;
    k = Q[i].k;

    while (MR < R)
      MR++, add(MR);

    while (ML > L)
      ML--, add(ML);

    while (MR > R)
      remove(MR), MR--;

    while (ML < L)
      remove(ML), ML++;

    ans[idx] = getAns(k, n);
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << endl;
}
