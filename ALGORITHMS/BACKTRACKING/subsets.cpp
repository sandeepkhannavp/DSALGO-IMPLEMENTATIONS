#include <bits/stdc++.h>
using namespace std;
vector<int> subsets;
void search(int arr[], int k, int n)
{
  if (k == n)
  {
    for (auto i : subsets)
      cout << i << " ";
    cout << endl;
  }
  else
  {
    search(arr, k + 1, n);
    subsets.push_back(arr[k]);
    search(arr, k + 1, n);
    subsets.pop_back();
  }
}

int main()
{
  int arr[3] = {5, 11, 7};
  search(arr, 0, 3);
  return 0;
}