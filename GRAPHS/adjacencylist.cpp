// number of nodes - N
// number of edges - M

#include <bits/stdc++.h>
#define N 1001
using namespace std;
vector<int> arr[N + 1];
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b), arr[b].push_back(a);
  }
}