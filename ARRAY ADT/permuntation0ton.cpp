#include <bits/stdc++.h>
using namespace std;
vector<int> permutation;
bool chosen[3];
void search()
{
  int n = 3;
  if (permutation.size() == n)
  {
    for (auto i : permutation)
      cout << i;
    cout << endl;
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      if (chosen[i])
        continue;
      chosen[i] = true;
      permutation.push_back(i);
      search();
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

int main()
{
  search();
}