#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
int st[400001], arr[100001];

// si - segment index  , ss - segment start , se - segment end
void build(int si, int ss, int se)
{
  if (ss == se)
  {
    st[si] = arr[ss];
    return;
  }

  int mid = (ss + se) / 2;
  build(2 * si, ss, mid);         // index of the left node is 2*si
  build(2 * si + 1, mid + 1, se); // index of the right node is 2*si+1

  st[si] = min(st[2 * si], st[2 * si + 1]);
}

// qs - query start , qe - equery end
int query(int si, int ss, int se, int qs, int qe)
{
  if (qe < ss || qs > se) // completely outside - if the segment starts after the query index has already ended or segment ends before the query has started
    return INF;

  if (ss >= qs && se <= qe) // completely inside - if segment lies completely inside the query
    return st[si];

  int mid = (ss + se) / 2;
  int l = query(2 * si, ss, mid, qs, qe);
  int r = query(2 * si + 1, mid + 1, se, qs, qe);

  return min(l, r);
}

void update(int si, int ss, int se, int qi)
{
  if (ss == se)
  {
    st[si] = arr[ss];
    return;
  }

  int mid = (ss + se) / 2;
  if (qi <= mid)
    update(2 * si, ss, mid, qi);
  else
    update(2 * si + 1, mid + 1, se, qi);

  st[si] = st[si] = min(st[2 * si], st[2 * si + 1]);
}

int main()
{
  int n, q, l, r;

  cin >> n;
  REP(i, n)
  cin >> arr[i];

  cin >> q;
  build(1, 1, n);
  while (q--)
  {
    cin >> l >> r;
    cout << query(1, 1, n, l + 1, r + 1) << endl; // because the input is in zero based index system
  }
}