#include <bits/stdc++.h>
using namespace std;
vector<int> permutation;
bool chosen[3];
void search(int arr[], int n)
{
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
      if (chosen[arr[i]])
        continue;
      chosen[arr[i]] = true;
      permutation.push_back(arr[arr[i]]);
      search(arr, n);
      chosen[arr[i]] = false;
      permutation.pop_back();
    }
  }
}

int main()
{
  int arr[3] = {0, 1, 2};
  search(arr, 3);
}